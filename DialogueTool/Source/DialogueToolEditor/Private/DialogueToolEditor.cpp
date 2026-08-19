// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolEditor.h"

#include "DialogueGraphNodeFactory.h"
#include "EdGraphUtilities.h"

void FDialogueToolEditorModule::StartupModule()
{
	GraphNodeFactory = MakeShared<FDialogueGraphNodeFactory>();
	FEdGraphUtilities::RegisterVisualNodeFactory(GraphNodeFactory);
}

void FDialogueToolEditorModule::ShutdownModule()
{
	if (GraphNodeFactory.IsValid())
	{
		FEdGraphUtilities::UnregisterVisualNodeFactory(GraphNodeFactory);
		GraphNodeFactory.Reset();
	}
}

IMPLEMENT_MODULE(FDialogueToolEditorModule, DialogueToolEditor)
