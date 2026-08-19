// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueLibraryObjectFactory.h"

#include "DialogueLibraryObject.h"

UDialogueLibraryObjectFactory::UDialogueLibraryObjectFactory()
{
	SupportedClass = UDialogueLibraryObject::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UDialogueLibraryObjectFactory::FactoryCreateNew(
	UClass* inClass,
	UObject* inParent,
	FName inName,
	EObjectFlags flags,
	UObject* context,
	FFeedbackContext* warn)
{
	return NewObject<UDialogueLibraryObject>(inParent, inClass, inName, flags);
}
