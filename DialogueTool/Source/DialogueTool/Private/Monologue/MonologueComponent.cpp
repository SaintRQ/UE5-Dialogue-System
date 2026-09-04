// Copyright Epic Games, Inc. All Rights Reserved.

#include "Monologue/MonologueComponent.h"

#include "DialogueAction.h"
#include "DialogueCondition.h"
#include "DialogueObject.h"
#include "DialogueProvider.h"
#include "DialogueTextUtilities.h"
#include "DialogueToolSettings.h"
#include "Engine/World.h"
#include "Monologue/MonologueLibraryObject.h"
#include "Monologue/MonologueObject.h"
#include "Sound/SoundBase.h"

UMonologueComponent::UMonologueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMonologueComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ResetMonologueState();
	Super::EndPlay(EndPlayReason);
}

bool UMonologueComponent::StartMonologue(
	UMonologueObject* Monologue,
	const FDialogueCache& Cache,
	const TArray<UObject*>& Speakers)
{
	ResetMonologueState();
	PublishText(FText::GetEmpty());
	if (!Monologue || !GetWorld())
	{
		return false;
	}

	ActiveMonologue = Monologue;
	MonologueContext.Reserve(Speakers.Num());
	for (UObject* speaker : Speakers)
	{
		MonologueContext.Add(IsValid(speaker) ? speaker : nullptr);
	}
	if (MonologueContext.IsEmpty())
	{
		MonologueContext.Add(GetOwner());
	}

	MonologueCache = Cache;
	const TArray<FDialogueInit>& initData = Monologue->GetDialogueInitData();
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

	ResetMonologueState();
	return false;
}

bool UMonologueComponent::ContinueMonologue()
{
	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	UWorld* world = GetWorld();
	const bool autoContinue = OverrideSettings ? AutoContinue : settings->AutoContinue;
	const bool allowManualContinue = OverrideSettings ? AllowManualContinue : settings->AllowManualContinue;
	if (!ActiveMonologue || !world
		|| (PlaybackState != EPlaybackState::TypingText
			&& PlaybackState != EPlaybackState::WaitingForContinue)
		|| (autoContinue && !allowManualContinue))
	{
		return false;
	}

	const FDialogueNode* dialogueNode = ActiveMonologue->FindDialogueNode(CurrentNodeId);
	if (dialogueNode
		&& CurrentTextIndex == dialogueNode->RootText.Num() - 1
		&& dialogueNode->NextNode <= 0)
	{
		return false;
	}
	if (PlaybackState == EPlaybackState::TypingText)
	{
		world->GetTimerManager().ClearTimer(TextTimerHandle);
		PlaybackState = EPlaybackState::WaitingForContinue;
	}
	ContinueMonologueInternal();
	return true;
}

void UMonologueComponent::FinishMonologue()
{
	if (!ActiveMonologue)
	{
		return;
	}

	MonologueCache.IsFirstTalk = false;
	FDialogueCache cache = MoveTemp(MonologueCache);
	ResetMonologueState();
	PublishText(FText::GetEmpty());
	OnMonologueFinished.Broadcast(cache);
}

UObject* UMonologueComponent::GetCurrentRole() const
{
	UObject* roleContext = MonologueContext.IsValidIndex(CurrentRoleId)
		? MonologueContext[CurrentRoleId]
		: nullptr;
	return IsValid(roleContext) ? roleContext : nullptr;
}

bool UMonologueComponent::AreConditionsMet(
	const TArray<TObjectPtr<UDialogueCondition>>& Conditions,
	const EDialogueConditionMode ConditionMode) const
{
	for (UDialogueCondition* condition : Conditions)
	{
		if (!condition)
		{
			continue;
		}

		const bool passed = condition->ExecuteCondition(MonologueContext);
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

UObject* UMonologueComponent::GetProviderContext() const
{
	for (UObject* contextObject : MonologueContext)
	{
		if (IsValid(contextObject))
		{
			return contextObject;
		}
	}
	return GetOwner();
}

FText UMonologueComponent::ResolveProviderText(const UDialogueProvider* Provider) const
{
	return Provider
		? Provider->ExecuteProvider(GetProviderContext(), MonologueCache)
		: FText::GetEmpty();
}

void UMonologueComponent::ContinueMonologueInternal()
{
	UWorld* world = GetWorld();
	if (!world)
	{
		return;
	}

	world->GetTimerManager().ClearTimer(TextTimerHandle);
	world->GetTimerManager().ClearTimer(ContinueTimeoutTimerHandle);
	if (PlaybackState == EPlaybackState::TypingText)
	{
		CompleteCurrentTextReveal();
		return;
	}
	if (PlaybackState != EPlaybackState::WaitingForContinue || !ActiveMonologue)
	{
		return;
	}

	const FDialogueNode* dialogueNode = ActiveMonologue->FindDialogueNode(CurrentNodeId);
	if (!dialogueNode)
	{
		CompleteActiveMonologue();
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

void UMonologueComponent::StartCurrentText()
{
	const FDialogueNode* dialogueNode = ActiveMonologue
		? ActiveMonologue->FindDialogueNode(CurrentNodeId)
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
	const int32 charactersPerSecond = OverrideSettings
		? CharactersPerSecond
		: GetDefault<UDialogueToolSettings>()->CharactersPerSecond;
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
			&UMonologueComponent::UpdateCurrentText,
			1.0f / static_cast<float>(charactersPerSecond),
			true);
	}
}

void UMonologueComponent::UpdateCurrentText()
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
	PublishText(FText::FromString(MoveTemp(revealedText)));
}

void UMonologueComponent::CompleteCurrentTextReveal()
{
	RevealedCharacters = CurrentRevealOffsets.Num();
	PlaybackState = EPlaybackState::WaitingForContinue;
	PublishText(CurrentSourceText);

	const FDialogueNode* dialogueNode = ActiveMonologue
		? ActiveMonologue->FindDialogueNode(CurrentNodeId)
		: nullptr;
	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	bool autoContinue = OverrideSettings ? AutoContinue : settings->AutoContinue;
	float autoContinueDelay = OverrideSettings ? AutoContinueDelay : settings->AutoContinueDelay;
	if (!OverrideSettings && dialogueNode && dialogueNode->RootText.IsValidIndex(CurrentTextIndex))
	{
		const FMonologueTextSettings* textSettings = dialogueNode->MonologueTextSettings.IsValidIndex(CurrentTextIndex)
			? &dialogueNode->MonologueTextSettings[CurrentTextIndex]
			: nullptr;
		if (!textSettings || textSettings->Enabled)
		{
			autoContinue = true;
			autoContinueDelay = textSettings ? textSettings->Delay : MonologueDefaultTextDelay;
		}
	}

	if (!dialogueNode)
	{
		return;
	}
	autoContinueDelay = FMath::Max(0.0f, autoContinueDelay);
	if (autoContinueDelay <= 0.0f)
	{
		TextTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
			this,
			autoContinue
				? &UMonologueComponent::ContinueMonologueInternal
				: &UMonologueComponent::HideCurrentText);
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(
			TextTimerHandle,
			this,
				autoContinue
					? &UMonologueComponent::ContinueMonologueInternal
					: &UMonologueComponent::HideCurrentText,
			autoContinueDelay,
			false);
	}
}

void UMonologueComponent::HideCurrentText()
{
	if (ActiveMonologue && PlaybackState == EPlaybackState::WaitingForContinue)
	{
		PublishText(FText::GetEmpty());
		const float continueTimeout = FMath::Max(0.0f, ManualContinueTimeout);
		if (continueTimeout <= 0.0f)
		{
			ContinueTimeoutTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
				this,
				&UMonologueComponent::ExpireManualContinue);
		}
		else
		{
			GetWorld()->GetTimerManager().SetTimer(
				ContinueTimeoutTimerHandle,
				this,
				&UMonologueComponent::ExpireManualContinue,
				continueTimeout,
				false);
		}
	}
}

void UMonologueComponent::ExpireManualContinue()
{
	ResetMonologueState();
	PublishText(FText::GetEmpty());
}

void UMonologueComponent::CompleteCurrentTopic()
{
	const FDialogueNode* dialogueNode = ActiveMonologue
		? ActiveMonologue->FindDialogueNode(CurrentNodeId)
		: nullptr;
	if (!dialogueNode)
	{
		CompleteActiveMonologue();
		return;
	}

	BeginActions(dialogueNode->Actions, dialogueNode->NextNode);
}

void UMonologueComponent::AdvanceToNode(int64 NodeId)
{
	TSet<int64> visitedFlowNodes;
	while (ActiveMonologue)
	{
		if (NodeId == DialogueFinishNodeId)
		{
			CompleteActiveMonologue();
			return;
		}
		if (NodeId <= 0)
		{
			break;
		}

		if (const FDialogueNode* dialogueNode = ActiveMonologue->FindDialogueNode(NodeId))
		{
			MonologueCache.TopicsMemory.Add(NodeId);
			CurrentNodeId = NodeId;
			CurrentTextIndex = 0;
			if (dialogueNode->RootText.IsEmpty())
			{
				CompleteCurrentTopic();
			}
			else
			{
				StartCurrentText();
			}
			return;
		}

		const FDialogueSwitcher* switcher = ActiveMonologue->FindDialogueSwitcher(NodeId);
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
				BeginActions(selectedCondition->Actions, selectedCondition->NextNode);
				return;
			}

			NodeId = selectedCondition->NextNode;
			continue;
		}

		if (const FDialogueRandom* random = ActiveMonologue->FindDialogueRandom(NodeId))
		{
			if (visitedFlowNodes.Contains(NodeId) || random->Outputs.IsEmpty())
			{
				break;
			}

			visitedFlowNodes.Add(NodeId);
			const FDialogueRandomOutput& selectedOutput = random->Outputs[
				MonologueCache.SelectRandomOutput(NodeId, random->Outputs.Num())];
			if (selectedOutput.Actions.ContainsByPredicate(
				[](const TObjectPtr<UDialogueAction>& action)
				{
					return action != nullptr;
				}))
			{
				BeginActions(selectedOutput.Actions, selectedOutput.NextNode);
				return;
			}

			NodeId = selectedOutput.NextNode;
			continue;
		}

		if (const FDialogueTransit* transit = ActiveMonologue->FindDialogueTransit(NodeId))
		{
			if (EnterMonologueLibrary(*transit))
			{
				return;
			}

			BeginActions(transit->ReturnActions, transit->ReturnNode);
			return;
		}

		break;
	}

	CompleteActiveMonologue();
}

bool UMonologueComponent::EnterMonologueLibrary(const FDialogueTransit& Transit)
{
	UMonologueLibraryObject* monologueLibrary = Cast<UMonologueLibraryObject>(Transit.DialogueLibrary);
	if (!monologueLibrary || ActiveMonologue->IsA<UMonologueLibraryObject>())
	{
		return false;
	}

	const TArray<FDialogueInit>& initData = monologueLibrary->GetDialogueInitData();
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

	PreviousMonologue = ActiveMonologue;
	PreviousReturnActions = Transit.ReturnActions;
	PreviousReturnNodeId = Transit.ReturnNode;
	ActiveMonologue = monologueLibrary;
	BeginActions(selectedInit->Actions, selectedInit->NextNode);
	return true;
}

void UMonologueComponent::CompleteActiveMonologue()
{
	if (!ActiveMonologue || !ActiveMonologue->IsA<UMonologueLibraryObject>() || !PreviousMonologue)
	{
		FinishMonologue();
		return;
	}

	ActiveMonologue = PreviousMonologue;
	PreviousMonologue = nullptr;
	const int64 returnNodeId = PreviousReturnNodeId;
	PreviousReturnNodeId = -1;
	TArray<TObjectPtr<UDialogueAction>> returnActions = MoveTemp(PreviousReturnActions);
	BeginActions(returnActions, returnNodeId);
}

void UMonologueComponent::BeginActions(
	const TArray<TObjectPtr<UDialogueAction>>& Actions,
	const int64 NextNodeId)
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
		AdvanceToNode(NextNodeId);
		return;
	}

	PendingNextNodeId = NextNodeId;
	PendingActionIndex = 0;
	PlaybackState = EPlaybackState::ExecutingActions;
	ActionTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
		this,
		&UMonologueComponent::ExecuteNextAction);
}

void UMonologueComponent::ExecuteNextAction()
{
	if (PlaybackState != EPlaybackState::ExecutingActions
		|| !PendingActions.IsValidIndex(PendingActionIndex))
	{
		return;
	}

	PendingActions[PendingActionIndex++]->ExecuteAction(MonologueContext);
	if (PlaybackState != EPlaybackState::ExecutingActions)
	{
		return;
	}
	if (PendingActions.IsValidIndex(PendingActionIndex))
	{
		ActionTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(
			this,
			&UMonologueComponent::ExecuteNextAction);
		return;
	}

	PendingActions.Reset();
	AdvanceToNode(PendingNextNodeId);
}

void UMonologueComponent::PublishText(const FText& Text)
{
	CurrentDisplayedText = Text;
	OnUpdateText.Broadcast(CurrentDisplayedText);
}

void UMonologueComponent::ResetMonologueState()
{
	if (UWorld* world = GetWorld())
	{
		world->GetTimerManager().ClearTimer(TextTimerHandle);
		world->GetTimerManager().ClearTimer(ContinueTimeoutTimerHandle);
		world->GetTimerManager().ClearTimer(ActionTimerHandle);
	}

	ActiveMonologue = nullptr;
	PreviousMonologue = nullptr;
	MonologueContext.Reset();
	PendingActions.Reset();
	PreviousReturnActions.Reset();
	MonologueCache = FDialogueCache();
	PlaybackState = EPlaybackState::Inactive;
	CurrentSourceText = FText::GetEmpty();
	CurrentDisplayedText = FText::GetEmpty();
	CurrentSourceString.Reset();
	CurrentRevealOffsets.Reset();
	CurrentRevealOpenTags.Reset();
	CurrentNodeId = -1;
	PendingNextNodeId = -1;
	PreviousReturnNodeId = -1;
	CurrentRoleId = INDEX_NONE;
	HasCurrentRole = false;
	CurrentTextIndex = 0;
	RevealedCharacters = 0;
	PendingActionIndex = 0;
}
