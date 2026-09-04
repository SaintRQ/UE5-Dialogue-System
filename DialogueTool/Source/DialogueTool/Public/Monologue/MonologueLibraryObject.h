// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueLibraryObject.h"

#include "MonologueLibraryObject.generated.h"

/** Stores reusable linear monologue flow that returns to its caller on completion. */
UCLASS(BlueprintType)
class DIALOGUETOOL_API UMonologueLibraryObject : public UDialogueLibraryObject
{
	GENERATED_BODY()
};
