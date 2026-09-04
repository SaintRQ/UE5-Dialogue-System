// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "DialogueCondition.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class DIALOGUETOOL_API UDialogueCondition : public UObject
{
	GENERATED_BODY()

public:

	// Evaluates the condition using the supplied ordered context.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Dialogue Tool|Condition")
	bool ExecuteCondition(const TArray<UObject*>& Context) const;
};
