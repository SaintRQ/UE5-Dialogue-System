// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FDialogueToolModule : public IModuleInterface
{
public:

	// Initializes the dialogue module.
	virtual void StartupModule() override;

	// Shuts down the dialogue module.
	virtual void ShutdownModule() override;
};
