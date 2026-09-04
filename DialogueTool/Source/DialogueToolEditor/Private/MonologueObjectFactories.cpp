// Copyright Epic Games, Inc. All Rights Reserved.

#include "MonologueObjectFactories.h"

#include "Monologue/MonologueLibraryObject.h"
#include "Monologue/MonologueObject.h"

UMonologueObjectFactory::UMonologueObjectFactory()
{
	SupportedClass = UMonologueObject::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UMonologueObjectFactory::FactoryCreateNew(
	UClass* Class,
	UObject* Parent,
	FName Name,
	EObjectFlags Flags,
	UObject* Context,
	FFeedbackContext* Warn)
{
	return NewObject<UMonologueObject>(Parent, Class, Name, Flags);
}

UMonologueLibraryObjectFactory::UMonologueLibraryObjectFactory()
{
	SupportedClass = UMonologueLibraryObject::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UMonologueLibraryObjectFactory::FactoryCreateNew(
	UClass* Class,
	UObject* Parent,
	FName Name,
	EObjectFlags Flags,
	UObject* Context,
	FFeedbackContext* Warn)
{
	return NewObject<UMonologueLibraryObject>(Parent, Class, Name, Flags);
}
