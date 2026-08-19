// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolSettings.h"

UDialogueToolSettings::UDialogueToolSettings()
{
	CategoryName = TEXT("Plugins");
	SectionName = TEXT("Dialogue Tool");
	ResponseReturnDialogueText = NSLOCTEXT("DialogueTool", "ReturnDialogue", "Return");
}
