// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TimerManager.h"

#include "DialogueManager.generated.h"

class UDialogueAction;
class UDialogueCondition;
class UDialogueObject;
class UDialogueProvider;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueTextUpdated, const FText&, Text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FDialogueResponsesUpdated,
	const TArray<FDialogueResponse>&,
	Responses);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FDialogueFinished,
	const FDialogueCache&,
	Cache);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FDialogueSoundRequested,
	USoundBase*,
	Sound);

UCLASS(BlueprintType)
class DIALOGUETOOL_API UDialogueManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	// Stops dialogue playback before the subsystem is destroyed.
	virtual void Deinitialize() override;

	// Starts the first initialization entry whose conditions succeed.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	bool StartDialogue(
		UDialogueObject* dialogue,
		const FDialogueCache& cache,
		UObject* context = nullptr);

	// Completes animated text or advances to the next dialogue text entry.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void ContinueDialogue();

	// Selects a successful response by its displayed array index.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void SelectResponse(int32 responseIndex);

	// Stops the active dialogue and broadcasts its completion.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void FinishDialogue();

	// Returns the cache currently used by dialogue playback.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool")
	const FDialogueCache& GetDialogueCache() const { return DialogueCache; }
	
	// Returns whether dialogue playback is waiting for explicit continue input.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool")
	bool IsWaitingForContinue() const;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Events")
	FDialogueTextUpdated OnUpdateText;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Events")
	FDialogueResponsesUpdated OnUpdateResponses;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Events")
	FDialogueFinished OnDialogueFinished;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Events")
	FDialogueSoundRequested OnPlaySound;

private:

	enum class EPlaybackState : uint8
	{
		Inactive,
		TypingText,
		WaitingForContinue,
		WaitingForResponse,
		ExecutingActions
	};

	// Returns whether every configured condition succeeds.
	bool AreConditionsMet(const TArray<TObjectPtr<UDialogueCondition>>& conditions) const;

	// Returns the object supplied to dialogue conditions and actions.
	UObject* GetExecutionContext() const;

	// Generates text using a configured dialogue provider.
	FText ResolveProviderText(const UDialogueProvider* provider) const;

	// Continues dialogue without applying the manual input restriction.
	void ContinueDialogueInternal();

	// Starts displaying the current topic text entry.
	void StartCurrentText();

	// Reveals the next visible character while preserving rich text markup.
	void UpdateCurrentText();

	// Publishes the completed text and immediately shows responses after the final entry.
	void CompleteCurrentTextReveal();

	// Processes responses or the default transition after the current topic.
	void CompleteCurrentTopic();

	// Resolves switchers and enters the next topic.
	void AdvanceToNode(int64 nodeId);

	// Enters a dialogue library and stores the caller continuation.
	bool EnterDialogueLibrary(const FDialogueTransit& transit);

	// Finishes a root dialogue or returns from the active library.
	void CompleteActiveDialogue();

	// Evaluates and broadcasts the current topic responses.
	void PublishResponses(const TArray<FDialogueResponse>& responses);

	// Executes valid actions on separate ticks before continuing dialogue flow.
	void BeginActions(
		const TArray<TObjectPtr<UDialogueAction>>& actions,
		int64 nextNodeId,
		bool finishAfterActions = false);

	// Executes one queued action and schedules the following action.
	void ExecuteNextAction();

	// Publishes the generated response used to close a dialogue dead end.
	void ShowEndResponse();

	// Clears timers and all active dialogue state.
	void ResetDialogueState();

	UPROPERTY(Transient)
	TObjectPtr<UDialogueObject> ActiveDialogue = nullptr;

	UPROPERTY(Transient)
	TWeakObjectPtr<UObject> DialogueContext;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDialogueAction>> PendingActions;

	UPROPERTY(Transient)
	TArray<FDialogueResponse> CurrentResponses;

	UPROPERTY(Transient)
	FDialogueCache DialogueCache;

	UPROPERTY(Transient)
	TObjectPtr<UDialogueObject> PreviousDialogue = nullptr;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDialogueAction>> PreviousReturnActions;

	EPlaybackState PlaybackState = EPlaybackState::Inactive;
	FTimerHandle TextTimerHandle;
	FTimerHandle ActionTimerHandle;
	FText CurrentSourceText;
	FString CurrentSourceString;
	TArray<int32> CurrentRevealOffsets;
	TArray<int32> CurrentRevealOpenTags;
	int64 CurrentNodeId = -1;
	int64 PendingNextNodeId = -1;
	int64 PreviousReturnNodeId = -1;
	int32 CurrentTextIndex = 0;
	int32 RevealedCharacters = 0;
	int32 PendingActionIndex = 0;
	bool FinishAfterActions = false;
};
