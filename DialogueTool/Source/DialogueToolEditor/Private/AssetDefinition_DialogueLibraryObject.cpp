// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetDefinition_DialogueLibraryObject.h"

#include "DialogueLibraryObject.h"
#include "DialogueObjectEditor.h"

#define LOCTEXT_NAMESPACE "AssetDefinition_DialogueLibraryObject"

FText UAssetDefinition_DialogueLibraryObject::GetAssetDisplayName() const
{
	return LOCTEXT("DisplayName", "Dialogue Library");
}

FLinearColor UAssetDefinition_DialogueLibraryObject::GetAssetColor() const
{
	return FLinearColor(0.42f, 0.08f, 0.72f);
}

TSoftClassPtr<UObject> UAssetDefinition_DialogueLibraryObject::GetAssetClass() const
{
	return UDialogueLibraryObject::StaticClass();
}

TConstArrayView<FAssetCategoryPath> UAssetDefinition_DialogueLibraryObject::GetAssetCategories() const
{
	static const auto categories = { FAssetCategoryPath(LOCTEXT("Category", "Dialogue Tool")) };
	return categories;
}

EAssetCommandResult UAssetDefinition_DialogueLibraryObject::OpenAssets(const FAssetOpenArgs& openArgs) const
{
	for (UDialogueLibraryObject* dialogueLibrary : openArgs.LoadObjects<UDialogueLibraryObject>())
	{
		const TSharedRef<FDialogueObjectEditor> editor = MakeShared<FDialogueObjectEditor>();
		editor->InitDialogueObjectEditor(openArgs.GetToolkitMode(), openArgs.ToolkitHost, dialogueLibrary);
	}

	return EAssetCommandResult::Handled;
}

#undef LOCTEXT_NAMESPACE
