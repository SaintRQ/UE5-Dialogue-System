// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"

#include "DialogueProvider.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class DIALOGUETOOL_API UDialogueProvider : public UObject
{
	GENERATED_BODY()

public:

	// Generates dialogue text from the execution context and current cache.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Dialogue Tool|Provider")
	FText ExecuteProvider(UObject* context, const FDialogueCache& cache) const;

	// Returns empty text when a native provider does not override generation.
	virtual FText ExecuteProvider_Implementation(UObject* context, const FDialogueCache& cache) const;
};
