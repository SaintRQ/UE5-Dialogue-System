// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueManager.h"

#include "DialogueAction.h"
#include "DialogueCondition.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "DialogueTextUtilities.h"
#include "DialogueToolSettings.h"
#include "DialogueProvider.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Misc/Crc.h"
#include "Monologue/MonologueObject.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"
#include "Sound/SoundBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogDialogueManager, Log, All);

namespace
{
	constexpr uint32 dialogueCacheSaveMagic = 0x56535444;
	constexpr uint8 dialogueCacheSaveVersion = 1;
	constexpr uint32 dialogueCacheSaveMaxEntries = 1 << 20;
}

UDialogueManager* UDialogueManager::GetFromContext(const UObject* Context)
{
	UWorld* world = Context ? Context->GetWorld() : nullptr;
	UGameInstance* gameInstance = world ? world->GetGameInstance() : nullptr;
	return gameInstance ? gameInstance->GetSubsystem<UDialogueManager>() : nullptr;
}

bool UDialogueManager::IsMonologueObject(const UDialogueObject* Object)
{
	return Object && Object->IsA<UMonologueObject>();
}

TArray<uint8> UDialogueManager::SerializeDialogueCache(const FDialogueCache& Cache)
{
	TArray<uint8> data;
	FMemoryWriter writer(data, true);
	const auto writeCount = [&writer](const int32 value)
	{
		uint32 packedValue = static_cast<uint32>(value);
		writer.SerializeIntPacked(packedValue);
	};
	const auto writeSet = [&writer, &writeCount](const TSet<int64>& values)
	{
		TArray<int64> sortedValues = values.Array();
		sortedValues.Sort();
		writeCount(sortedValues.Num());
		for (int64 value : sortedValues)
		{
			writer << value;
		}
	};

	uint32 magic = dialogueCacheSaveMagic;
	uint8 version = dialogueCacheSaveVersion;
	uint8 isFirstTalk = Cache.IsFirstTalk ? 1 : 0;
	writer << magic;
	writer << version;
	writer << isFirstTalk;
	writeSet(Cache.TopicsMemory);
	writeSet(Cache.ResponsesMemory);

	TArray<int64> randomIDs;
	for (const TPair<int64, int32>& randomOutput : Cache.RandomOutputHistory)
	{
		if (randomOutput.Value >= 0)
		{
			randomIDs.Add(randomOutput.Key);
		}
	}
	randomIDs.Sort();
	writeCount(randomIDs.Num());
	for (int64 randomID : randomIDs)
	{
		uint32 outputIndex = static_cast<uint32>(Cache.RandomOutputHistory.FindChecked(randomID));
		writer << randomID;
		writer.SerializeIntPacked(outputIndex);
	}

	uint32 checksum = FCrc::MemCrc32(data.GetData(), data.Num());
	writer << checksum;
	return data;
}

bool UDialogueManager::DeserializeDialogueCache(const TArray<uint8>& Data, FDialogueCache& Cache)
{
	const auto rejectData = [](const TCHAR* reason)
	{
		UE_LOG(LogDialogueManager, Warning, TEXT("Cannot restore dialogue cache: %s."), reason);
		return false;
	};
	if (Data.Num() < static_cast<int32>(sizeof(uint32) * 2 + sizeof(uint8) * 2))
	{
		return rejectData(TEXT("the buffer is too small"));
	}

	const int32 payloadSize = Data.Num() - sizeof(uint32);
	uint32 storedChecksum = 0;
	FMemory::Memcpy(&storedChecksum, Data.GetData() + payloadSize, sizeof(storedChecksum));
	if (storedChecksum != FCrc::MemCrc32(Data.GetData(), payloadSize))
	{
		return rejectData(TEXT("checksum mismatch"));
	}

	FMemoryReader reader(Data, true);
	reader.SetLimitSize(payloadSize);
	const auto readCount = [&reader](uint32& value)
	{
		value = 0;
		reader.SerializeIntPacked(value);
		return !reader.IsError() && value <= dialogueCacheSaveMaxEntries;
	};
	const auto readSet = [&reader, &readCount](TSet<int64>& values)
	{
		uint32 count = 0;
		if (!readCount(count))
		{
			return false;
		}

		values.Reserve(count);
		for (uint32 valueIndex = 0; valueIndex < count; ++valueIndex)
		{
			int64 value = 0;
			reader << value;
			if (reader.IsError())
			{
				return false;
			}
			values.Add(value);
		}
		return true;
	};

	uint32 magic = 0;
	uint8 version = 0;
	uint8 isFirstTalk = 0;
	reader << magic;
	reader << version;
	reader << isFirstTalk;
	if (reader.IsError() || magic != dialogueCacheSaveMagic
		|| version != dialogueCacheSaveVersion || isFirstTalk > 1)
	{
		return rejectData(TEXT("unsupported format or version"));
	}

	FDialogueCache restoredCache;
	restoredCache.IsFirstTalk = isFirstTalk != 0;
	if (!readSet(restoredCache.TopicsMemory) || !readSet(restoredCache.ResponsesMemory))
	{
		return rejectData(TEXT("invalid dialogue memory"));
	}

	uint32 randomCount = 0;
	if (!readCount(randomCount))
	{
		return rejectData(TEXT("invalid random state count"));
	}
	restoredCache.RandomOutputHistory.Reserve(randomCount);
	for (uint32 randomIndex = 0; randomIndex < randomCount; ++randomIndex)
	{
		int64 randomID = 0;
		uint32 outputIndex = 0;
		reader << randomID;
		reader.SerializeIntPacked(outputIndex);
		if (reader.IsError() || outputIndex > static_cast<uint32>(MAX_int32))
		{
			return rejectData(TEXT("invalid random state"));
		}
		restoredCache.RandomOutputHistory.Add(randomID, static_cast<int32>(outputIndex));
	}
	if (reader.IsError() || reader.Tell() != payloadSize)
	{
		return rejectData(TEXT("unexpected trailing or missing data"));
	}

	Cache = MoveTemp(restoredCache);
	return true;
}

void UDialogueManager::Deinitialize()
{
	ResetDialogueState();
	Super::Deinitialize();
}

bool UDialogueManager::StartDialogue(
	UDialogueObject* Dialogue,
	const FDialogueCache& Cache,
	const TArray<UObject*>& Speakers)
{
	return StartDialogueInternal(Dialogue, Cache, Speakers, false);
}

bool UDialogueManager::StartMonologue(
	UMonologueObject* Monologue,
	const FDialogueCache& Cache,
	const TArray<UObject*>& Speakers)
{
	return StartDialogueInternal(Monologue, Cache, Speakers, true);
}

bool UDialogueManager::StartDialogueInternal(
	UDialogueObject* Dialogue,
	const FDialogueCache& Cache,
	const TArray<UObject*>& Speakers,
	const bool ExpectMonologue)
{
	ResetDialogueState();
	if (!Dialogue || Dialogue->IsA<UDialogueLibraryObject>() || !GetWorld()
		|| UMonologueObject::IsMonologueAsset(Dialogue) != ExpectMonologue)
	{
		return false;
	}

	ActiveDialogue = Dialogue;
	DialogueContext.Reserve(Speakers.Num());
	for (UObject* contextObject : Speakers)
	{
		DialogueContext.Add(IsValid(contextObject) ? contextObject : nullptr);
	}
	if (DialogueContext.IsEmpty())
	{
		DialogueContext.Add(GetGameInstance());
	}
	DialogueCache = Cache;
	const TArray<FDialogueInit>& initData = Dialogue->GetDialogueInitData();
	for (int32 initIndex = 0; initIndex < initData.Num() - 1; ++initIndex)
	{
		const FDialogueInit& init = initData[initIndex];
		if (AreConditionsMet(init.Conditions, init.ConditionMode))
		{
			BeginActions(init.Actions, init.NextNode);
			return true;
		}
	}
	if (!initData.IsEmpty())
	{
		const FDialogueInit& defaultInit = initData.Last();
		BeginActions(defaultInit.Actions, defaultInit.NextNode);
		return true;
	}

	ResetDialogueState();
	return false;
}

void UDialogueManager::ContinueDialogue()
{
	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	if (settings->AutoContinue && !settings->AllowManualContinue)
	{
		return;
	}

	ContinueDialogueInternal();
}

void UDialogueManager::ContinueDialogueInternal()
{
	UWorld* world = GetWorld();
	if (!world)
	{
		return;
	}

	world->GetTimerManager().ClearTimer(TextTimerHandle);
	if (PlaybackState == EPlaybackState::TypingText)
	{
		CompleteCurrentTextReveal();
		return;
	}

	if (PlaybackState != EPlaybackState::WaitingForContinue || !ActiveDialogue)
	{
		return;
	}

	const FDialogueNode* dialogueNode = ActiveDialogue->FindDialogueNode(CurrentNodeId);
	if (!dialogueNode)
	{
		ShowEndResponse();
		return;
	}

	++CurrentTextIndex;
	if (dialogueNode->RootText.IsValidIndex(CurrentTextIndex))
	{
		StartCurrentText();
	}
	else
	{
		CompleteCurrentTopic();
	}
}

void UDialogueManager::SelectResponse(int32 ResponseIndex)
{
	if (PlaybackState != EPlaybackState::WaitingForResponse
		|| !CurrentResponses.IsValidIndex(ResponseIndex)
		|| CurrentResponses[ResponseIndex].Visibility != EDialogueConditionVisibilityResult::VisibleSuccess)
	{
		return;
	}

	const FDialogueResponse response = CurrentResponses[ResponseIndex];
	if (response.ID > 0)
	{
		DialogueCache.ResponsesMemory.Add(response.ID);
	}
	CurrentResponses.Reset();
	OnUpdateResponses.Broadcast(CurrentResponses);
	if (USoundBase* sound = response.Sound.LoadSynchronous())
	{
		OnPlaySound.Broadcast(sound);
	}
	BeginActions(response.Actions, response.NextNode, response.FinishDialogue);
}

void UDialogueManager::RefreshResponses()
{
	if (PlaybackState != EPlaybackState::WaitingForResponse || !ActiveDialogue)
	{
		return;
	}

	const FDialogueNode* dialogueNode = ActiveDialogue->FindDialogueNode(CurrentNodeId);
	if (dialogueNode && !dialogueNode->Response.IsEmpty())
	{
		PublishResponses(dialogueNode->Response);
	}
}

void UDialogueManager::FinishDialogue()
{
	if (!ActiveDialogue)
	{
		return;
	}

	DialogueCache.IsFirstTalk = false;
	FDialogueCache cache = MoveTemp(DialogueCache);
	ResetDialogueState();
	OnDialogueFinished.Broadcast(cache);
}

bool UDialogueManager::IsWaitingForContinue() const
{
	return PlaybackState == EPlaybackState::WaitingForContinue;
}

UObject* UDialogueManager::GetCurrentRole() const
{
	UObject* roleContext = DialogueContext.IsValidIndex(CurrentRoleId)
		? DialogueContext[CurrentRoleId]
		: nullptr;
	return IsValid(roleContext) ? roleContext : nullptr;
}

bool UDialogueManager::AreConditionsMet(
	const TArray<TObjectPtr<UDialogueCondition>>& Conditions,
	const EDialogueConditionMode ConditionMode,
	const int64 ResponseId) const
{
	TGuardValue<int64> responseIdGuard(EvaluatedResponseId, ResponseId);
	for (UDialogueCondition* condition : Conditions)
	{
		if (!condition)
		{
			continue;
		}

		const bool passed = condition->ExecuteCondition(GetExecutionContext());
		if (ConditionMode == EDialogueConditionMode::Any && passed)
		{
			return true;
		}
		if (ConditionMode == EDialogueConditionMode::All && !passed)
		{
			return false;
		}
	}

	return ConditionMode == EDialogueConditionMode::All;
}

const TArray<UObject*>& UDialogueManager::GetExecutionContext() const
{
	return DialogueContext;
}

UObject* UDialogueManager::GetProviderContext() const
{
	for (UObject* contextObject : DialogueContext)
	{
		if (IsValid(contextObject))
		{
			return contextObject;
		}
	}
	return GetGameInstance();
}

FText UDialogueManager::ResolveProviderText(const UDialogueProvider* Provider) const
{
	return Provider
		? Provider->ExecuteProvider(GetProviderContext(), DialogueCache)
		: FText::GetEmpty();
}

void UDialogueManager::StartCurrentText()
{
	const FDialogueNode* dialogueNode = ActiveDialogue
		? ActiveDialogue->FindDialogueNode(CurrentNodeId)
		: nullptr;
	if (!dialogueNode || !dialogueNode->RootText.IsValidIndex(CurrentTextIndex))
	{
		CompleteCurrentTopic();
		return;
	}

	if (!HasCurrentRole || CurrentRoleId != dialogueNode->Role)
	{
		CurrentRoleId = dialogueNode->Role;
		HasCurrentRole = true;
		OnUpdateRole.Broadcast(CurrentRoleId, GetCurrentRole());
	}

	const FName customTextId = dialogueNode->RootTextCustomIds.IsValidIndex(CurrentTextIndex)
		? dialogueNode->RootTextCustomIds[CurrentTextIndex]
		: NAME_None;
	if (!customTextId.IsNone())
	{
		const FText* customText = GetDefault<UDialogueToolSettings>()->TopicCustomTextList.Find(customTextId);
		CurrentSourceText = customText ? *customText : FText::GetEmpty();
	}
	else if (dialogueNode->RootTextProviders.IsValidIndex(CurrentTextIndex)
		&& dialogueNode->RootTextProviders[CurrentTextIndex])
	{
		CurrentSourceText = ResolveProviderText(dialogueNode->RootTextProviders[CurrentTextIndex]);
	}
	else
	{
		CurrentSourceText = dialogueNode->RootText[CurrentTextIndex];
	}
	if (dialogueNode->RootSounds.IsValidIndex(CurrentTextIndex))
	{
		if (USoundBase* sound = dialogueNode->RootSounds[CurrentTextIndex].LoadSynchronous())
		{
			OnPlaySound.Broadcast(sound);
		}
	}
	CurrentSourceString = CurrentSourceText.ToString();
	DialogueTextUtilities::BuildRevealData(CurrentSourceString, CurrentRevealOffsets, CurrentRevealOpenTags);

	RevealedCharacters = 0;
	const int32 charactersPerSecond = GetDefault<UDialogueToolSettings>()->CharactersPerSecond;
	if (charactersPerSecond <= 0 || CurrentRevealOffsets.IsEmpty())
	{
		CompleteCurrentTextReveal();
		return;
	}

	PlaybackState = EPlaybackState::TypingText;
	UpdateCurrentText();
	if (PlaybackState == EPlaybackState::TypingText)
	{
		GetWorld()->GetTimerManager().SetTimer(
			TextTimerHandle,
			this,
			&UDialogueManager::UpdateCurrentText,
			1.0f / static_cast<float>(charactersPerSecond),
			true);
	}
}

void UDialogueManager::UpdateCurrentText()
{
	if (PlaybackState != EPlaybackState::TypingText)
	{
		return;
	}

	RevealedCharacters = FMath::Min(RevealedCharacters + 1, CurrentRevealOffsets.Num());
	if (RevealedCharacters >= CurrentRevealOffsets.Num())
	{
		GetWorld()->GetTimerManager().ClearTimer(TextTimerHandle);
		CompleteCurrentTextReveal();
		return;
	}

	const int32 revealIndex = RevealedCharacters - 1;
	FString revealedText = CurrentSourceString.Left(CurrentRevealOffsets[revealIndex]);
	revealedText.Reserve(revealedText.Len() + CurrentRevealOpenTags[revealIndex] * 3);
	for (int32 index = 0; index < CurrentRevealOpenTags[revealIndex]; ++index)
	{
		revealedText.Append(TEXT("</>"));
	}
	OnUpdateText.Broadcast(FText::FromString(MoveTemp(revealedText)));
}

void UDialogueManager::CompleteCurrentTextReveal()
{
	RevealedCharacters = CurrentRevealOffsets.Num();
	PlaybackState = EPlaybackState::WaitingForContinue;
	OnUpdateText.Broadcast(CurrentSourceText);

	const FDialogueNode* dialogueNode = ActiveDialogue
		? ActiveDialogue->FindDialogueNode(CurrentNodeId)
		: nullptr;
	const bool bMonologue = UMonologueObject::IsMonologueAsset(ActiveDialogue);
	if (dialogueNode
		&& CurrentTextIndex == dialogueNode->RootText.Num() - 1
		&& ((!bMonologue && !dialogueNode->Response.IsEmpty())
			|| ActiveDialogue->FindDialogueSkipText(dialogueNode->NextNode)))
	{
		CompleteCurrentTopic();
		return;
	}

	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	bool autoContinue = settings->AutoContinue;
	float autoContinueDelay = settings->AutoContinueDelay;
	if (dialogueNode && dialogueNode->RootText.IsValidIndex(CurrentTextIndex))
	{
		const FMonologueTextSettings* textSettings = dialogueNode->MonologueTextSettings.IsValidIndex(CurrentTextIndex)
			? &dialogueNode->MonologueTextSettings[CurrentTextIndex]
			: nullptr;
		if ((textSettings && textSettings->Enabled)
			|| (!textSettings && bMonologue))
		{
			autoContinue = true;
			autoContinueDelay = textSettings ? textSettings->Delay : MonologueDefaultTextDelay;
		}
	}

	if (dialogueNode && autoContinue)
	{
		if (autoContinueDelay <= 0.0f)
		{
			TextTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
				this,
				&UDialogueManager::ContinueDialogueInternal);
		}
		else
		{
			GetWorld()->GetTimerManager().SetTimer(
				TextTimerHandle,
				this,
				&UDialogueManager::ContinueDialogueInternal,
				autoContinueDelay,
				false);
		}
	}
}

void UDialogueManager::CompleteCurrentTopic()
{
	const FDialogueNode* dialogueNode = ActiveDialogue
		? ActiveDialogue->FindDialogueNode(CurrentNodeId)
		: nullptr;
	if (!dialogueNode)
	{
		ShowEndResponse();
		return;
	}

	if (!UMonologueObject::IsMonologueAsset(ActiveDialogue) && !dialogueNode->Response.IsEmpty())
	{
		PublishResponses(dialogueNode->Response);
		return;
	}

	BeginActions(dialogueNode->Actions, dialogueNode->NextNode);
}

void UDialogueManager::AdvanceToNode(int64 NodeId, bool SkipText)
{
	TSet<int64> visitedFlowNodes;
	while (ActiveDialogue)
	{
		if (NodeId == DialogueFinishNodeId)
		{
			CompleteActiveDialogue();
			return;
		}

		if (NodeId <= 0)
		{
			break;
		}

		if (const FDialogueNode* dialogueNode = ActiveDialogue->FindDialogueNode(NodeId))
		{
			CurrentTopicWasVisited = DialogueCache.TopicsMemory.Contains(NodeId);
			DialogueCache.TopicsMemory.Add(NodeId);
			CurrentNodeId = NodeId;
			CurrentTextIndex = 0;
			if (SkipText && !UMonologueObject::IsMonologueAsset(ActiveDialogue)
				&& !dialogueNode->Response.IsEmpty())
			{
				PublishResponses(dialogueNode->Response);
			}
			else if (dialogueNode->RootText.IsEmpty())
			{
				CompleteCurrentTopic();
			}
			else
			{
				StartCurrentText();
			}
			return;
		}

		const FDialogueSwitcher* switcher = ActiveDialogue->FindDialogueSwitcher(NodeId);
		if (switcher)
		{
			if (visitedFlowNodes.Contains(NodeId))
			{
				break;
			}

			visitedFlowNodes.Add(NodeId);
			const FDialogueSwitcherCondition* selectedCondition = switcher->Conditions.IsEmpty()
				? nullptr
				: &switcher->Conditions.Last();
			for (int32 conditionIndex = 0; conditionIndex < switcher->Conditions.Num() - 1; ++conditionIndex)
			{
				const FDialogueSwitcherCondition& condition = switcher->Conditions[conditionIndex];
				if (AreConditionsMet(condition.Conditions, condition.ConditionMode))
				{
					selectedCondition = &condition;
					break;
				}
			}
			if (!selectedCondition)
			{
				break;
			}

			if (selectedCondition->Actions.ContainsByPredicate(
				[](const TObjectPtr<UDialogueAction>& action)
				{
					return action != nullptr;
				}))
			{
				BeginActions(selectedCondition->Actions, selectedCondition->NextNode, false, SkipText);
				return;
			}

			NodeId = selectedCondition->NextNode;
			continue;
		}

		if (const FDialogueRandom* random = ActiveDialogue->FindDialogueRandom(NodeId))
		{
			if (visitedFlowNodes.Contains(NodeId) || random->Outputs.IsEmpty())
			{
				break;
			}

			visitedFlowNodes.Add(NodeId);
			const FDialogueRandomOutput& selectedOutput = random->Outputs[
				DialogueCache.SelectRandomOutput(NodeId, random->Outputs.Num())];
			if (selectedOutput.Actions.ContainsByPredicate(
				[](const TObjectPtr<UDialogueAction>& action)
				{
					return action != nullptr;
				}))
			{
				BeginActions(selectedOutput.Actions, selectedOutput.NextNode, false, SkipText);
				return;
			}

			NodeId = selectedOutput.NextNode;
			continue;
		}

		if (const FDialogueSkipText* skipTextData = ActiveDialogue->FindDialogueSkipText(NodeId))
		{
			if (visitedFlowNodes.Contains(NodeId))
			{
				break;
			}

			visitedFlowNodes.Add(NodeId);
			if (skipTextData->Actions.ContainsByPredicate(
				[](const TObjectPtr<UDialogueAction>& action)
				{
					return action != nullptr;
				}))
			{
				BeginActions(skipTextData->Actions, skipTextData->NextNode, false, true);
				return;
			}

			NodeId = skipTextData->NextNode;
			SkipText = true;
			continue;
		}

		if (const FDialogueTransit* transit = ActiveDialogue->FindDialogueTransit(NodeId))
		{
			if (EnterDialogueLibrary(*transit))
			{
				return;
			}

			BeginActions(transit->ReturnActions, transit->ReturnNode);
			return;
		}

		break;
	}

	ShowEndResponse();
}

bool UDialogueManager::EnterDialogueLibrary(const FDialogueTransit& Transit)
{
	UDialogueLibraryObject* dialogueLibrary = Transit.DialogueLibrary;
	if (!dialogueLibrary || ActiveDialogue->IsA<UDialogueLibraryObject>()
		|| (UMonologueObject::IsMonologueAsset(ActiveDialogue)
			!= UMonologueObject::IsMonologueAsset(dialogueLibrary)))
	{
		return false;
	}

	const TArray<FDialogueInit>& initData = dialogueLibrary->GetDialogueInitData();
	const FDialogueInit* selectedInit = initData.IsEmpty() ? nullptr : &initData.Last();
	for (int32 initIndex = 0; initIndex < initData.Num() - 1; ++initIndex)
	{
		const FDialogueInit& init = initData[initIndex];
		if (AreConditionsMet(init.Conditions, init.ConditionMode))
		{
			selectedInit = &init;
			break;
		}
	}
	if (!selectedInit)
	{
		return false;
	}

	PreviousDialogue = ActiveDialogue;
	PreviousReturnActions = Transit.ReturnActions;
	PreviousReturnNodeId = Transit.ReturnNode;
	ActiveDialogue = dialogueLibrary;
	BeginActions(selectedInit->Actions, selectedInit->NextNode);
	return true;
}

void UDialogueManager::CompleteActiveDialogue()
{
	if (!ActiveDialogue || !ActiveDialogue->IsA<UDialogueLibraryObject>() || !PreviousDialogue)
	{
		FinishDialogue();
		return;
	}

	ActiveDialogue = PreviousDialogue;
	PreviousDialogue = nullptr;
	const int64 returnNodeId = PreviousReturnNodeId;
	PreviousReturnNodeId = -1;
	TArray<TObjectPtr<UDialogueAction>> returnActions = MoveTemp(PreviousReturnActions);
	BeginActions(returnActions, returnNodeId);
}

void UDialogueManager::PublishResponses(const TArray<FDialogueResponse>& Responses)
{
	CurrentResponses.Reset(Responses.Num());
	const auto addResponse = [this](const FDialogueResponse& response)
	{
		if (response.FinishDialogue)
		{
			FDialogueResponse& currentResponse = CurrentResponses.Add_GetRef(response);
			const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
			currentResponse.Response = ActiveDialogue && ActiveDialogue->IsA<UDialogueLibraryObject>()
				? settings->ResponseReturnDialogueText
				: settings->ResponseEndDialogueText;
			currentResponse.AlwaysVisible = true;
			currentResponse.Visibility = EDialogueConditionVisibilityResult::VisibleSuccess;
			return;
		}

		const bool conditionsMet = AreConditionsMet(
			response.Conditions,
			response.ConditionMode,
			response.ID);
		if (!conditionsMet && !response.AlwaysVisible)
		{
			return;
		}

		FDialogueResponse& currentResponse = CurrentResponses.Add_GetRef(response);
		if (!response.CustomTextId.IsNone())
		{
			const FText* customText = GetDefault<UDialogueToolSettings>()->ResponseCustomTextList.Find(response.CustomTextId);
			currentResponse.Response = customText ? *customText : FText::GetEmpty();
		}
		else if (response.ResponseProvider)
		{
			currentResponse.Response = ResolveProviderText(response.ResponseProvider);
		}
		currentResponse.Visibility = conditionsMet
			? EDialogueConditionVisibilityResult::VisibleSuccess
			: EDialogueConditionVisibilityResult::VisibleFailure;
	};

	for (const FDialogueResponse& response : Responses)
	{
		if (!response.FinishDialogue)
		{
			addResponse(response);
		}
	}
	for (const FDialogueResponse& response : Responses)
	{
		if (response.FinishDialogue)
		{
			addResponse(response);
		}
	}

	PlaybackState = EPlaybackState::WaitingForResponse;
	OnUpdateResponses.Broadcast(CurrentResponses);
}

void UDialogueManager::BeginActions(
	const TArray<TObjectPtr<UDialogueAction>>& Actions,
	int64 NextNodeId,
	bool FinishTextAfterAllActions,
	bool SkipTextAfterAllActions)
{
	PendingActions.Reset(Actions.Num());
	for (UDialogueAction* action : Actions)
	{
		if (action)
		{
			PendingActions.Add(action);
		}
	}

	if (PendingActions.IsEmpty())
	{
		if (FinishTextAfterAllActions)
		{
			CompleteActiveDialogue();
		}
		else
		{
			AdvanceToNode(NextNodeId, SkipTextAfterAllActions);
		}
		return;
	}

	PendingNextNodeId = NextNodeId;
	PendingActionIndex = 0;
	FinishAfterActions = FinishTextAfterAllActions;
	SkipTextAfterActions = SkipTextAfterAllActions;
	PlaybackState = EPlaybackState::ExecutingActions;
	ActionTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
		this,
		&UDialogueManager::ExecuteNextAction);
}

void UDialogueManager::ExecuteNextAction()
{
	if (PlaybackState != EPlaybackState::ExecutingActions
		|| !PendingActions.IsValidIndex(PendingActionIndex))
	{
		return;
	}

	PendingActions[PendingActionIndex++]->ExecuteAction(GetExecutionContext());
	if (PlaybackState != EPlaybackState::ExecutingActions)
	{
		return;
	}

	if (PendingActions.IsValidIndex(PendingActionIndex))
	{
		ActionTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
			this,
			&UDialogueManager::ExecuteNextAction);
		return;
	}

	PendingActions.Reset();
	if (FinishAfterActions)
	{
		CompleteActiveDialogue();
	}
	else
	{
		AdvanceToNode(PendingNextNodeId, SkipTextAfterActions);
	}
}

void UDialogueManager::ShowEndResponse()
{
	if (!ActiveDialogue)
	{
		return;
	}
	if (UMonologueObject::IsMonologueAsset(ActiveDialogue))
	{
		CompleteActiveDialogue();
		return;
	}

	TArray<FDialogueResponse> responses;
	responses.AddDefaulted_GetRef().FinishDialogue = true;
	PublishResponses(responses);
}

void UDialogueManager::ResetDialogueState()
{
	if (UWorld* world = GetWorld())
	{
		world->GetTimerManager().ClearTimer(TextTimerHandle);
		world->GetTimerManager().ClearTimer(ActionTimerHandle);
	}

	ActiveDialogue = nullptr;
	DialogueContext.Reset();
	PendingActions.Reset();
	CurrentResponses.Reset();
	DialogueCache = FDialogueCache();
	EvaluatedResponseId = 0;
	PreviousDialogue = nullptr;
	PreviousReturnActions.Reset();
	PlaybackState = EPlaybackState::Inactive;
	CurrentSourceText = FText::GetEmpty();
	CurrentSourceString.Reset();
	CurrentRevealOffsets.Reset();
	CurrentRevealOpenTags.Reset();
	CurrentNodeId = -1;
	CurrentTopicWasVisited = false;
	PendingNextNodeId = -1;
	PreviousReturnNodeId = -1;
	CurrentRoleId = INDEX_NONE;
	HasCurrentRole = false;
	CurrentTextIndex = 0;
	RevealedCharacters = 0;
	PendingActionIndex = 0;
	FinishAfterActions = false;
	SkipTextAfterActions = false;
}
