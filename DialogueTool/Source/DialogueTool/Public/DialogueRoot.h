#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.generated.h"

class UDialogueAction;
class UDialogueCondition;
class UDialogueLibraryObject;
class UDialogueProvider;
class USoundBase;

inline constexpr int64 DialogueFinishNodeId = MIN_int64;
inline constexpr float MonologueDefaultTextDelay = 3.0f;

UENUM(BlueprintType)
enum  class EDialogueConditionVisibilityResult : uint8
{
	VisibleSuccess,
	VisibleFailure
	
};

UENUM(BlueprintType)
enum class EDialogueConditionMode : uint8
{
	All,
	Any
};


USTRUCT(BlueprintType)
struct FDialogueCache
{
	GENERATED_USTRUCT_BODY()

	// Selects a random output while avoiding the previous result when possible.
	int32 SelectRandomOutput(int64 RandomID, int32 OutputCount);
	
	UPROPERTY(BlueprintReadWrite)
	bool IsFirstTalk = true;
	
	UPROPERTY(BlueprintReadWrite)
	TSet<int64> TopicsMemory = TSet<int64>();

	UPROPERTY(BlueprintReadWrite)
	TSet<int64> ResponsesMemory = TSet<int64>();

	UPROPERTY(BlueprintReadWrite)
	TMap<int64, int32> RandomOutputHistory;
	
};
	


USTRUCT(BlueprintType)
struct FDialogueSwitcherCondition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName Name = NAME_None;

	UPROPERTY()
	EDialogueConditionMode ConditionMode = EDialogueConditionMode::All;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueCondition>> Conditions;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;

	UPROPERTY()
	int64 NextNode = -1;
};

USTRUCT(BlueprintType)
struct DIALOGUETOOL_API FDialogueSwitcher
{
	GENERATED_USTRUCT_BODY()

	// Restores the required conditional and default switcher entries.
	void EnsureMinimumConditions();

	UPROPERTY()
	TArray<FDialogueSwitcherCondition> Conditions;
};

USTRUCT(BlueprintType)
struct FDialogueTransit
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TObjectPtr<UDialogueLibraryObject> DialogueLibrary = nullptr;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> ReturnActions;

	UPROPERTY()
	int64 ReturnNode = -1;
};

USTRUCT(BlueprintType)
struct FDialogueSkipText
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;

	UPROPERTY()
	int64 NextNode = -1;
};

USTRUCT(BlueprintType)
struct FDialogueRandomOutput
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;

	UPROPERTY()
	int64 NextNode = -1;
};

USTRUCT(BlueprintType)
struct DIALOGUETOOL_API FDialogueRandom
{
	GENERATED_USTRUCT_BODY()

	// Restores the two required random outputs.
	void EnsureMinimumOutputs();

	UPROPERTY()
	TArray<FDialogueRandomOutput> Outputs;
};

USTRUCT(BlueprintType)
struct FDialogueInit
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FName Name = NAME_None;

	UPROPERTY()
	EDialogueConditionMode ConditionMode = EDialogueConditionMode::All;
	
	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueCondition>> Conditions;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;
	
	UPROPERTY()
	int64 NextNode = -1; 
};

USTRUCT(BlueprintType)
struct FDialogueResponse
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int64 ID = 0;
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FText Response = FText::GetEmpty();

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FName CustomTextId = NAME_None;

	UPROPERTY(BlueprintReadOnly, Instanced, Category = "Dialogue")
	TObjectPtr<UDialogueProvider> ResponseProvider = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TSoftObjectPtr<USoundBase> Sound;

	UPROPERTY()
	EDialogueConditionMode ConditionMode = EDialogueConditionMode::All;
	
	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueCondition>> Conditions;
	
	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;
	
	UPROPERTY()
	int64 NextNode = -1; 
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	bool AlwaysVisible = true;
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	EDialogueConditionVisibilityResult Visibility = EDialogueConditionVisibilityResult::VisibleSuccess;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	bool FinishDialogue = false;
	
};

USTRUCT(BlueprintType)
struct FMonologueTextSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Monologue")
	bool Enabled = true;

	UPROPERTY(BlueprintReadOnly, Category = "Monologue", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float Delay = MonologueDefaultTextDelay;

	UPROPERTY()
	bool Initialized = false;
};

USTRUCT(BlueprintType)
struct DIALOGUETOOL_API FDialogueNode
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	bool IsRoot = false;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	int32 Role = INDEX_NONE;
	
	UPROPERTY()
	TArray<FText> RootText = TArray<FText>();

	UPROPERTY()
	TArray<FName> RootTextCustomIds;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueProvider>> RootTextProviders;

	UPROPERTY()
	TArray<TSoftObjectPtr<USoundBase>> RootSounds;

	UPROPERTY()
	TArray<FMonologueTextSettings> MonologueTextSettings;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;
	
	UPROPERTY()
	TArray<FDialogueResponse> Response = TArray<FDialogueResponse>();

	UPROPERTY()
	int64 NextNode = -1;

	// Restores text timing entries and applies the owning asset's default to new entries.
	void EnsureTextTimingSettings(bool EnabledByDefault);
	
};
