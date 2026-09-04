// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueRoot.h"
#include "TimerManager.h"

#include "MonologueComponent.generated.h"

class UDialogueAction;
class UDialogueCondition;
class UDialogueObject;
class UDialogueProvider;
class UMonologueObject;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMonologueTextUpdated, const FText&, Text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMonologueRoleUpdated, int32, RoleId, UObject*, RoleContext);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMonologueFinished, const FDialogueCache&, Cache);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMonologueSoundRequested, USoundBase*, Sound);

/** Plays one local monologue independently from the global dialogue manager. */
UCLASS(BlueprintType, ClassGroup = (DialogueTool), meta = (BlueprintSpawnableComponent))
class DIALOGUETOOL_API UMonologueComponent final : public UActorComponent
{
	GENERATED_BODY()

public:

	// Creates a non-ticking monologue component.
	UMonologueComponent();

	// Stops local playback before the component is removed.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Starts the first initialization entry whose conditions succeed.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool|Monologue")
	bool StartMonologue(
		UMonologueObject* Monologue,
		const FDialogueCache& Cache,
		const TArray<UObject*>& Speakers);

	// Advances manual playback and returns whether input was handled.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool|Monologue")
	bool ContinueMonologue();

	// Stops the active monologue and broadcasts its completion.
	UFUNCTION(BlueprintCallable, Category = "Dialogue Tool|Monologue")
	void FinishMonologue();

	// Returns whether this component is playing a monologue.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool|Monologue")
	bool IsMonologuePlaying() const { return ActiveMonologue != nullptr; }

	// Returns the text currently published to listeners.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool|Monologue")
	const FText& GetCurrentText() const { return CurrentDisplayedText; }

	// Returns the current pseudo-speaker from the start context.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool|Monologue")
	UObject* GetCurrentRole() const;

	// Returns the cache currently used by local playback.
	UFUNCTION(BlueprintPure, Category = "Dialogue Tool|Monologue")
	const FDialogueCache& GetMonologueCache() const { return MonologueCache; }

	// Uses the settings below instead of the shared Dialogue Tool settings.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Tool|Monologue|Settings")
	bool OverrideSettings = false;

	// Automatically continues after a fully revealed text.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Tool|Monologue|Settings",
		meta = (EditCondition = "OverrideSettings"))
	bool AutoContinue = false;

	// Defines the delay before automatic continuation or manual text hiding in seconds.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Tool|Monologue|Settings",
		meta = (EditCondition = "OverrideSettings", ClampMin = "0.0", UIMin = "0.0"))
	float AutoContinueDelay = 1.0f;

	// Defines how long hidden manual text waits for Continue before playback resets.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Tool|Monologue|Settings",
		meta = (ClampMin = "0.0", UIMin = "0.0"))
	float ManualContinueTimeout = 5.0f;

	// Allows manual Continue input while automatic continuation is enabled.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Tool|Monologue|Settings",
		meta = (EditCondition = "OverrideSettings && AutoContinue"))
	bool AllowManualContinue = true;

	// Defines how many visible characters are revealed per second; zero reveals text instantly.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Tool|Monologue|Settings",
		meta = (EditCondition = "OverrideSettings", ClampMin = "0", UIMin = "0"))
	int32 CharactersPerSecond = 20;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Monologue|Events")
	FMonologueRoleUpdated OnUpdateRole;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Monologue|Events")
	FMonologueTextUpdated OnUpdateText;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Monologue|Events")
	FMonologueFinished OnMonologueFinished;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue Tool|Monologue|Events")
	FMonologueSoundRequested OnPlaySound;

private:

	enum class EPlaybackState : uint8
	{
		Inactive,
		TypingText,
		WaitingForContinue,
		ExecutingActions
	};

	// Returns whether the configured condition mode succeeds.
	bool AreConditionsMet(
		const TArray<TObjectPtr<UDialogueCondition>>& Conditions,
		EDialogueConditionMode ConditionMode) const;

	// Returns the primary object supplied to text providers.
	UObject* GetProviderContext() const;

	// Generates text using a configured provider.
	FText ResolveProviderText(const UDialogueProvider* Provider) const;

	// Continues playback without applying the manual input restriction.
	void ContinueMonologueInternal();

	// Starts displaying the current text entry.
	void StartCurrentText();

	// Reveals the next visible character while preserving rich text markup.
	void UpdateCurrentText();

	// Publishes the completed text and schedules its transition.
	void CompleteCurrentTextReveal();

	// Hides completed text while manual playback waits for input.
	void HideCurrentText();

	// Resets manual playback after its continue timeout expires.
	void ExpireManualContinue();

	// Executes topic actions and advances to its output.
	void CompleteCurrentTopic();

	// Resolves flow nodes and enters the next topic.
	void AdvanceToNode(int64 NodeId);

	// Enters a monologue library and stores the caller continuation.
	bool EnterMonologueLibrary(const FDialogueTransit& Transit);

	// Finishes a root monologue or returns from its active library.
	void CompleteActiveMonologue();

	// Executes valid actions on separate ticks before continuing flow.
	void BeginActions(
		const TArray<TObjectPtr<UDialogueAction>>& Actions,
		int64 NextNodeId);

	// Executes one queued action and schedules the following action.
	void ExecuteNextAction();

	// Stores and broadcasts text displayed by the local presentation.
	void PublishText(const FText& Text);

	// Clears timers and all local playback state.
	void ResetMonologueState();

	UPROPERTY(Transient)
	TObjectPtr<UDialogueObject> ActiveMonologue = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UDialogueObject> PreviousMonologue = nullptr;

	UPROPERTY(Transient)
	TArray<UObject*> MonologueContext;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDialogueAction>> PendingActions;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDialogueAction>> PreviousReturnActions;

	UPROPERTY(Transient)
	FDialogueCache MonologueCache;

	EPlaybackState PlaybackState = EPlaybackState::Inactive;
	FTimerHandle TextTimerHandle;
	FTimerHandle ContinueTimeoutTimerHandle;
	FTimerHandle ActionTimerHandle;
	FText CurrentSourceText;
	FText CurrentDisplayedText;
	FString CurrentSourceString;
	TArray<int32> CurrentRevealOffsets;
	TArray<int32> CurrentRevealOpenTags;
	int64 CurrentNodeId = -1;
	int64 PendingNextNodeId = -1;
	int64 PreviousReturnNodeId = -1;
	int32 CurrentRoleId = INDEX_NONE;
	bool HasCurrentRole = false;
	int32 CurrentTextIndex = 0;
	int32 RevealedCharacters = 0;
	int32 PendingActionIndex = 0;
};
