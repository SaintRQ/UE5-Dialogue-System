// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueObjectFactory.h"

#include "DialogueObject.h"

UDialogueObjectFactory::UDialogueObjectFactory()
{
	SupportedClass = UDialogueObject::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UDialogueObjectFactory::FactoryCreateNew(
	UClass* inClass,
	UObject* inParent,
	FName inName,
	EObjectFlags flags,
	UObject* context,
	FFeedbackContext* warn)
{
	return NewObject<UDialogueObject>(inParent, inClass, inName, flags);
}
