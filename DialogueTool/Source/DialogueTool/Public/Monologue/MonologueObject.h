// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueObject.h"

#include "MonologueObject.generated.h"

/** Stores linear dialogue data without player responses. */
UCLASS(BlueprintType)
class DIALOGUETOOL_API UMonologueObject : public UDialogueObject
{
	GENERATED_BODY()

public:

	// Returns whether an object is a monologue or monologue library asset.
	static bool IsMonologueAsset(const UObject* Object);
};
