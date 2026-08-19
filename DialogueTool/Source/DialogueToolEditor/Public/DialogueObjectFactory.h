// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"

#include "DialogueObjectFactory.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueObjectFactory final : public UFactory
{
	GENERATED_BODY()

public:

	// Configures the factory for dialogue object assets.
	UDialogueObjectFactory();

	// Creates a dialogue object asset.
	virtual UObject* FactoryCreateNew(
		UClass* inClass,
		UObject* inParent,
		FName inName,
		EObjectFlags flags,
		UObject* context,
		FFeedbackContext* warn) override;
};
