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
class UMonologueObject;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueTextUpdated, const FText&, Text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueRoleUpdated, int32, RoleId, UObject*, RoleContext);
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

	// Returns the dialogue manager associated with an object context.
	static UDialogueManager* GetFromContext(const UObject* Context);

	// Returns whether an object can be started as a monologue.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool")
	static bool IsMonologueObject(const UDialogueObject* Object);

	// Stops dialogue playback before the subsystem is destroyed.
	virtual void Deinitialize() override;

	// Starts the first initialization entry whose conditions succeed.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	bool StartDialogue(
		UDialogueObject* Dialogue,
		const FDialogueCache& Cache,
		const TArray<UObject*>& Speakers);

	// Starts the first monologue initialization entry whose conditions succeed.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	bool StartMonologue(
		UMonologueObject* Monologue,
		const FDialogueCache& Cache,
		const TArray<UObject*>& Speakers);

	// Completes animated text or advances to the next dialogue text entry.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void ContinueDialogue();

	// Selects a successful response by its displayed array index.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void SelectResponse(int32 ResponseIndex);

	// Re-evaluates and publishes responses for the active topic.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void RefreshResponses();

	// Stops the active dialogue and broadcasts its completion.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool")
	void FinishDialogue();

	// Returns the cache currently used by dialogue playback.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool")
	const FDialogueCache& GetDialogueCache() const { return DialogueCache; }

	// Returns compact versioned save data for a dialogue cache.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool|Save")
	static TArray<uint8> SerializeDialogueCache(const FDialogueCache& Cache);

	// Restores a dialogue cache from data returned by SerializeDialogueCache.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool|Save")
	static bool DeserializeDialogueCache(const TArray<uint8>& Data, FDialogueCache& Cache);

	// Returns the response currently being evaluated, or zero outside response conditions.
	int64 GetEvaluatedResponseId() const { return EvaluatedResponseId; }

	// Returns whether the topic containing the evaluated response was visited before its current entry.
	bool WasEvaluatedTopicVisited() const { return EvaluatedResponseId > 0 && CurrentTopicWasVisited; }
	
	// Returns whether dialogue playback is waiting for explicit continue input.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool")
	bool IsWaitingForContinue() const;

	// Returns the current text node's pseudo-speaker from the start context.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool")
	UObject* GetCurrentRole() const;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Events")
	FDialogueRoleUpdated OnUpdateRole;

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

	// Starts a validated dialogue or monologue asset.
	bool StartDialogueInternal(
		UDialogueObject* Dialogue,
		const FDialogueCache& Cache,
		const TArray<UObject*>& Speakers,
		bool ExpectMonologue);

	// Returns whether the configured condition mode succeeds.
	bool AreConditionsMet(
		const TArray<TObjectPtr<UDialogueCondition>>& Conditions,
		EDialogueConditionMode ConditionMode,
		int64 ResponseId = 0) const;

	// Returns the ordered context supplied to dialogue conditions and actions.
	const TArray<UObject*>& GetExecutionContext() const;

	// Returns the primary object supplied to dialogue providers.
	UObject* GetProviderContext() const;

	// Generates text using a configured dialogue provider.
	FText ResolveProviderText(const UDialogueProvider* Provider) const;

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

	// Resolves flow nodes and enters the next topic.
	void AdvanceToNode(int64 NodeId, bool SkipText = false);

	// Enters a dialogue library and stores the caller continuation.
	bool EnterDialogueLibrary(const FDialogueTransit& Transit);

	// Finishes a root dialogue or returns from the active library.
	void CompleteActiveDialogue();

	// Evaluates and broadcasts the current topic responses.
	void PublishResponses(const TArray<FDialogueResponse>& Responses);

	// Executes valid actions on separate ticks before continuing dialogue flow.
	void BeginActions(
		const TArray<TObjectPtr<UDialogueAction>>& Actions,
		int64 NextNodeId,
		bool FinishTextAfterAllActions = false,
		bool SkipTextAfterAllActions = false);

	// Executes one queued action and schedules the following action.
	void ExecuteNextAction();

	// Publishes the generated response used to close a dialogue dead end.
	void ShowEndResponse();

	// Clears timers and all active dialogue state.
	void ResetDialogueState();

	UPROPERTY(Transient)
	TObjectPtr<UDialogueObject> ActiveDialogue = nullptr;

	UPROPERTY(Transient)
	TArray<UObject*> DialogueContext;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDialogueAction>> PendingActions;

	UPROPERTY(Transient)
	TArray<FDialogueResponse> CurrentResponses;

	UPROPERTY(Transient)
	FDialogueCache DialogueCache;

	mutable int64 EvaluatedResponseId = 0;

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
	bool CurrentTopicWasVisited = false;
	int64 PendingNextNodeId = -1;
	int64 PreviousReturnNodeId = -1;
	int32 CurrentRoleId = INDEX_NONE;
	bool HasCurrentRole = false;
	int32 CurrentTextIndex = 0;
	int32 RevealedCharacters = 0;
	int32 PendingActionIndex = 0;
	bool FinishAfterActions = false;
	bool SkipTextAfterActions = false;
};
