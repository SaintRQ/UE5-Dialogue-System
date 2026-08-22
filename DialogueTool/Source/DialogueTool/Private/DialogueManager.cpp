// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueManager.h"

#include "DialogueAction.h"
#include "DialogueCondition.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "DialogueToolSettings.h"
#include "DialogueProvider.h"
#include "Containers/StringConv.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Sound/SoundBase.h"

UDialogueManager* UDialogueManager::GetFromContext(const UObject* context)
{
	UWorld* world = context ? context->GetWorld() : nullptr;
	UGameInstance* gameInstance = world ? world->GetGameInstance() : nullptr;
	return gameInstance ? gameInstance->GetSubsystem<UDialogueManager>() : nullptr;
}

void UDialogueManager::Deinitialize()
{
	ResetDialogueState();
	Super::Deinitialize();
}

bool UDialogueManager::StartDialogue(
	UDialogueObject* dialogue,
	const FDialogueCache& cache,
	UObject* context)
{
	ResetDialogueState();
	if (!dialogue || dialogue->IsA<UDialogueLibraryObject>() || !GetWorld())
	{
		return false;
	}

	ActiveDialogue = dialogue;
	DialogueContext = context;
	DialogueCache = cache;
	for (const FDialogueInit& init : dialogue->GetDialogueInitData())
	{
		if (AreConditionsMet(init.Conditions))
		{
			BeginActions(init.Actions, init.NextNode);
			return true;
		}
	}

	ResetDialogueState();
	return false;
}

void UDialogueManager::ContinueDialogue()
{
	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	if (settings->AutoContinue && !settings->AllowContinueClick)
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

void UDialogueManager::SelectResponse(int32 responseIndex)
{
	if (PlaybackState != EPlaybackState::WaitingForResponse
		|| !CurrentResponses.IsValidIndex(responseIndex)
		|| CurrentResponses[responseIndex].Visibility != EDialogueConditionVisibilityResult::VisibleSuccess)
	{
		return;
	}

	const FDialogueResponse response = CurrentResponses[responseIndex];
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

bool UDialogueManager::AreConditionsMet(
	const TArray<TObjectPtr<UDialogueCondition>>& conditions,
	const int64 responseId) const
{
	TGuardValue<int64> responseIdGuard(EvaluatedResponseId, responseId);
	UObject* context = GetExecutionContext();
	for (UDialogueCondition* condition : conditions)
	{
		if (condition && !condition->ExecuteCondition(context))
		{
			return false;
		}
	}

	return true;
}

UObject* UDialogueManager::GetExecutionContext() const
{
	return DialogueContext.IsValid() ? DialogueContext.Get() : GetGameInstance();
}

FText UDialogueManager::ResolveProviderText(const UDialogueProvider* provider) const
{
	return provider
		? provider->ExecuteProvider(GetExecutionContext(), DialogueCache)
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
	CurrentRevealOffsets.Reset();
	CurrentRevealOpenTags.Reset();
	int32 openTags = 0;
	for (int32 index = 0; index < CurrentSourceString.Len();)
	{
		if (CurrentSourceString[index] == TEXT('<'))
		{
			const int32 tagEnd = CurrentSourceString.Find(
				TEXT(">"),
				ESearchCase::CaseSensitive,
				ESearchDir::FromStart,
				index + 1);
			if (tagEnd != INDEX_NONE)
			{
				int32 tagLastCharacter = tagEnd - 1;
				while (tagLastCharacter > index && FChar::IsWhitespace(CurrentSourceString[tagLastCharacter]))
				{
					--tagLastCharacter;
				}

				if (index + 1 < tagEnd && CurrentSourceString[index + 1] == TEXT('/'))
				{
					openTags = FMath::Max(0, openTags - 1);
				}
				else if (CurrentSourceString[tagLastCharacter] != TEXT('/'))
				{
					++openTags;
				}

				index = tagEnd + 1;
				continue;
			}
		}

		int32 characterLength = 1;
		if (CurrentSourceString[index] == TEXT('&'))
		{
			static constexpr const TCHAR* escapeSequences[] = {
				TEXT("&quot;"),
				TEXT("&lt;"),
				TEXT("&gt;"),
				TEXT("&amp;")
			};
			for (const TCHAR* escapeSequence : escapeSequences)
			{
				const int32 escapeLength = FCString::Strlen(escapeSequence);
				if (CurrentSourceString.Mid(index, escapeLength).Equals(escapeSequence, ESearchCase::CaseSensitive))
				{
					characterLength = escapeLength;
					break;
				}
			}
		}
		else if (StringConv::IsHighSurrogate(CurrentSourceString[index])
			&& CurrentSourceString.IsValidIndex(index + 1)
			&& StringConv::IsLowSurrogate(CurrentSourceString[index + 1]))
		{
			characterLength = 2;
		}

		index += characterLength;
		CurrentRevealOffsets.Add(index);
		CurrentRevealOpenTags.Add(openTags);
	}

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
	if (dialogueNode
		&& CurrentTextIndex == dialogueNode->RootText.Num() - 1
		&& (!dialogueNode->Response.IsEmpty()
			|| ActiveDialogue->FindDialogueSkipText(dialogueNode->NextNode)))
	{
		CompleteCurrentTopic();
		return;
	}

	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	if (dialogueNode && settings->AutoContinue)
	{
		if (settings->AutoContinueDelay <= 0.0f)
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
				settings->AutoContinueDelay,
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

	if (!dialogueNode->Response.IsEmpty())
	{
		PublishResponses(dialogueNode->Response);
		return;
	}

	BeginActions(dialogueNode->Actions, dialogueNode->NextNode);
}

void UDialogueManager::AdvanceToNode(int64 nodeId, bool skipText)
{
	TSet<int64> visitedFlowNodes;
	while (ActiveDialogue)
	{
		if (nodeId == DialogueFinishNodeId)
		{
			CompleteActiveDialogue();
			return;
		}

		if (nodeId <= 0)
		{
			break;
		}

		if (const FDialogueNode* dialogueNode = ActiveDialogue->FindDialogueNode(nodeId))
		{
			CurrentTopicWasVisited = DialogueCache.TopicsMemory.Contains(nodeId);
			DialogueCache.TopicsMemory.Add(nodeId);
			CurrentNodeId = nodeId;
			CurrentTextIndex = 0;
			if (skipText && !dialogueNode->Response.IsEmpty())
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

		const FDialogueSwitcher* switcher = ActiveDialogue->FindDialogueSwitcher(nodeId);
		if (switcher)
		{
			if (visitedFlowNodes.Contains(nodeId))
			{
				break;
			}

			visitedFlowNodes.Add(nodeId);
			const FDialogueSwitcherCondition* selectedCondition = switcher->Conditions.FindByPredicate(
				[this](const FDialogueSwitcherCondition& condition)
				{
					return AreConditionsMet(condition.Conditions);
				});
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
				BeginActions(selectedCondition->Actions, selectedCondition->NextNode, false, skipText);
				return;
			}

			nodeId = selectedCondition->NextNode;
			continue;
		}

		if (const FDialogueSkipText* skipTextData = ActiveDialogue->FindDialogueSkipText(nodeId))
		{
			if (visitedFlowNodes.Contains(nodeId))
			{
				break;
			}

			visitedFlowNodes.Add(nodeId);
			if (skipTextData->Actions.ContainsByPredicate(
				[](const TObjectPtr<UDialogueAction>& action)
				{
					return action != nullptr;
				}))
			{
				BeginActions(skipTextData->Actions, skipTextData->NextNode, false, true);
				return;
			}

			nodeId = skipTextData->NextNode;
			skipText = true;
			continue;
		}

		if (const FDialogueTransit* transit = ActiveDialogue->FindDialogueTransit(nodeId))
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

bool UDialogueManager::EnterDialogueLibrary(const FDialogueTransit& transit)
{
	UDialogueLibraryObject* dialogueLibrary = transit.DialogueLibrary;
	if (!dialogueLibrary || ActiveDialogue->IsA<UDialogueLibraryObject>())
	{
		return false;
	}

	const FDialogueInit* selectedInit = dialogueLibrary->GetDialogueInitData().FindByPredicate(
		[this](const FDialogueInit& init)
		{
			return AreConditionsMet(init.Conditions);
		});
	if (!selectedInit)
	{
		return false;
	}

	PreviousDialogue = ActiveDialogue;
	PreviousReturnActions = transit.ReturnActions;
	PreviousReturnNodeId = transit.ReturnNode;
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

void UDialogueManager::PublishResponses(const TArray<FDialogueResponse>& responses)
{
	CurrentResponses.Reset(responses.Num());
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

		const bool conditionsMet = AreConditionsMet(response.Conditions, response.ID);
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

	for (const FDialogueResponse& response : responses)
	{
		if (!response.FinishDialogue)
		{
			addResponse(response);
		}
	}
	for (const FDialogueResponse& response : responses)
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
	const TArray<TObjectPtr<UDialogueAction>>& actions,
	int64 nextNodeId,
	bool finishAfterActions,
	bool skipTextAfterActions)
{
	PendingActions.Reset(actions.Num());
	for (UDialogueAction* action : actions)
	{
		if (action)
		{
			PendingActions.Add(action);
		}
	}

	if (PendingActions.IsEmpty())
	{
		if (finishAfterActions)
		{
			CompleteActiveDialogue();
		}
		else
		{
			AdvanceToNode(nextNodeId, skipTextAfterActions);
		}
		return;
	}

	PendingNextNodeId = nextNodeId;
	PendingActionIndex = 0;
	FinishAfterActions = finishAfterActions;
	SkipTextAfterActions = skipTextAfterActions;
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
	CurrentTextIndex = 0;
	RevealedCharacters = 0;
	PendingActionIndex = 0;
	FinishAfterActions = false;
	SkipTextAfterActions = false;
}
