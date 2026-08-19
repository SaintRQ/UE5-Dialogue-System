#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.generated.h"

class UDialogueAction;
class UDialogueCondition;
class UDialogueLibraryObject;

inline constexpr int64 DialogueFinishNodeId = MIN_int64;

UENUM(BlueprintType)
enum  class EDialogueConditionVisibilityResult : uint8
{
	VisibleSuccess,
	VisibleFailure,
	Invisible
	
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
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	FText Response = FText::GetEmpty();
	
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
	TArray<TObjectPtr<UDialogueAction>> Actions;
	
	UPROPERTY()
	TArray<FDialogueResponse> Response = TArray<FDialogueResponse>();

	UPROPERTY()
	int64 NextNode = -1;
	
};
