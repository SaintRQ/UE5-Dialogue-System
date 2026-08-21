#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.generated.h"

class UDialogueAction;
class UDialogueCondition;
class UDialogueLibraryObject;
class UDialogueProvider;
class USoundBase;

inline constexpr int64 DialogueFinishNodeId = MIN_int64;

UENUM(BlueprintType)
enum  class EDialogueConditionVisibilityResult : uint8
{
	VisibleSuccess,
	VisibleFailure
	
};


USTRUCT(BlueprintType)
struct FDialogueCache
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	bool IsFirstTalk = true;
	
	UPROPERTY(BlueprintReadWrite)
	TSet<int64> TopicsMemory = TSet<int64>();

	UPROPERTY(BlueprintReadWrite)
	TSet<int64> ResponsesMemory = TSet<int64>();
	
};
	


USTRUCT(BlueprintType)
struct FDialogueSwitcherCondition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName Name = NAME_None;

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

	// Restores the two required switcher conditions.
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
struct FDialogueInit
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FName Name = NAME_None;
	
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
struct FDialogueNode
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	bool IsRoot = false;
	
	UPROPERTY()
	TArray<FText> RootText = TArray<FText>();

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueProvider>> RootTextProviders;

	UPROPERTY()
	TArray<TSoftObjectPtr<USoundBase>> RootSounds;

	UPROPERTY(Instanced)
	TArray<TObjectPtr<UDialogueAction>> Actions;
	
	UPROPERTY()
	TArray<FDialogueResponse> Response = TArray<FDialogueResponse>();

	UPROPERTY()
	int64 NextNode = -1;
	
};
