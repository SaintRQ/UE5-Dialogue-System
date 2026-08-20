// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueBlueprintFactories.h"

#include "AssetToolsModule.h"
#include "DialogueAction.h"
#include "DialogueCondition.h"
#include "DialogueProvider.h"

#define LOCTEXT_NAMESPACE "DialogueBlueprintFactories"

namespace
{
	uint32 GetDialogueToolCategory()
	{
		IAssetTools& assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		return assetTools.RegisterAdvancedAssetCategory(
			TEXT("Dialogue Tool"),
			LOCTEXT("Category", "Dialogue Tool"));
	}
}

UDialogueConditionBlueprintFactory::UDialogueConditionBlueprintFactory()
{
	ParentClass = UDialogueCondition::StaticClass();
	bSkipClassPicker = true;
}

FText UDialogueConditionBlueprintFactory::GetDisplayName() const
{
	return LOCTEXT("ConditionDisplayName", "Dialogue Condition");
}

uint32 UDialogueConditionBlueprintFactory::GetMenuCategories() const
{
	return GetDialogueToolCategory();
}

UDialogueActionBlueprintFactory::UDialogueActionBlueprintFactory()
{
	ParentClass = UDialogueAction::StaticClass();
	bSkipClassPicker = true;
}

FText UDialogueActionBlueprintFactory::GetDisplayName() const
{
	return LOCTEXT("ActionDisplayName", "Dialogue Action");
}

uint32 UDialogueActionBlueprintFactory::GetMenuCategories() const
{
	return GetDialogueToolCategory();
}

UDialogueProviderBlueprintFactory::UDialogueProviderBlueprintFactory()
{
	ParentClass = UDialogueProvider::StaticClass();
	bSkipClassPicker = true;
}

FText UDialogueProviderBlueprintFactory::GetDisplayName() const
{
	return LOCTEXT("ProviderDisplayName", "Dialogue Provider");
}

uint32 UDialogueProviderBlueprintFactory::GetMenuCategories() const
{
	return GetDialogueToolCategory();
}

#undef LOCTEXT_NAMESPACE
