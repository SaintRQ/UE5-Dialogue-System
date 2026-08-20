// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueProvider.h"

FText UDialogueProvider::ExecuteProvider_Implementation(
	UObject* context,
	const FDialogueCache& cache) const
{
	return FText::GetEmpty();
}
