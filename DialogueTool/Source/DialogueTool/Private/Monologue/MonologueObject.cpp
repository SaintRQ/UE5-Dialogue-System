// Copyright Epic Games, Inc. All Rights Reserved.


#include "Monologue/MonologueObject.h"

#include "Monologue/MonologueLibraryObject.h"

bool UMonologueObject::IsMonologueAsset(const UObject* Object)
{
	return Object && (Object->IsA<UMonologueObject>() || Object->IsA<UMonologueLibraryObject>());
}

