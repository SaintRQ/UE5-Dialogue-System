// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "DialogueAction.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class DIALOGUETOOL_API UDialogueAction : public UObject
{
	GENERATED_BODY()

public:

	// Executes the action using the supplied context.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Dialogue Tool|Action")
	void ExecuteAction(UObject* context);
};
