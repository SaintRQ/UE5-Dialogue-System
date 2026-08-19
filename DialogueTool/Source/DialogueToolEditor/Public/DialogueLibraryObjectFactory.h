// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"

#include "DialogueLibraryObjectFactory.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueLibraryObjectFactory final : public UFactory
{
	GENERATED_BODY()

public:

	// Configures the factory for dialogue library assets.
	UDialogueLibraryObjectFactory();

	// Creates a dialogue library asset.
	virtual UObject* FactoryCreateNew(
		UClass* inClass,
		UObject* inParent,
		FName inName,
		EObjectFlags flags,
		UObject* context,
		FFeedbackContext* warn) override;
};
