// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

namespace DialogueTextUtilities
{
	// Builds visible character offsets and active rich text tag counts.
	void BuildRevealData(const FString& Text, TArray<int32>& Offsets, TArray<int32>& OpenTags);
}
