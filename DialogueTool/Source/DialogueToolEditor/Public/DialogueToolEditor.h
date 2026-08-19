// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FDialogueGraphNodeFactory;

class DIALOGUETOOLEDITOR_API FDialogueToolEditorModule final : public IModuleInterface
{
public:

	// Registers dialogue editor integrations.
	virtual void StartupModule() override;

	// Unregisters dialogue editor integrations.
	virtual void ShutdownModule() override;

private:

	TSharedPtr<FDialogueGraphNodeFactory> GraphNodeFactory;
};
