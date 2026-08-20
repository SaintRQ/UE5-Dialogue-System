// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/BlueprintFactory.h"

#include "DialogueBlueprintFactories.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueConditionBlueprintFactory final : public UBlueprintFactory
{
	GENERATED_BODY()

public:

	// Configures Blueprint creation for dialogue conditions.
	UDialogueConditionBlueprintFactory();

	// Returns the factory name shown in the creation menu.
	virtual FText GetDisplayName() const override;

	// Returns the Dialogue Tool creation category.
	virtual uint32 GetMenuCategories() const override;
};

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueActionBlueprintFactory final : public UBlueprintFactory
{
	GENERATED_BODY()

public:

	// Configures Blueprint creation for dialogue actions.
	UDialogueActionBlueprintFactory();

	// Returns the factory name shown in the creation menu.
	virtual FText GetDisplayName() const override;

	// Returns the Dialogue Tool creation category.
	virtual uint32 GetMenuCategories() const override;
};

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueProviderBlueprintFactory final : public UBlueprintFactory
{
	GENERATED_BODY()

public:

	// Configures Blueprint creation for dialogue providers.
	UDialogueProviderBlueprintFactory();

	// Returns the factory name shown in the creation menu.
	virtual FText GetDisplayName() const override;

	// Returns the Dialogue Tool creation category.
	virtual uint32 GetMenuCategories() const override;
};
