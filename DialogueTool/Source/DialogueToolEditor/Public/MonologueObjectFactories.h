// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"

#include "MonologueObjectFactories.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UMonologueObjectFactory final : public UFactory
{
	GENERATED_BODY()

public:

	// Configures the factory for monologue object assets.
	UMonologueObjectFactory();

	// Creates a monologue object asset.
	virtual UObject* FactoryCreateNew(
		UClass* Class,
		UObject* Parent,
		FName Name,
		EObjectFlags Flags,
		UObject* Context,
		FFeedbackContext* Warn) override;
};

UCLASS()
class DIALOGUETOOLEDITOR_API UMonologueLibraryObjectFactory final : public UFactory
{
	GENERATED_BODY()

public:

	// Configures the factory for monologue library assets.
	UMonologueLibraryObjectFactory();

	// Creates a monologue library asset.
	virtual UObject* FactoryCreateNew(
		UClass* Class,
		UObject* Parent,
		FName Name,
		EObjectFlags Flags,
		UObject* Context,
		FFeedbackContext* Warn) override;
};
