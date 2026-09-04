// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetDefinition_DialogueObject.h"

#include "DialogueObject.h"
#include "DialogueObjectEditor.h"

#define LOCTEXT_NAMESPACE "AssetDefinition_DialogueObject"

FText UAssetDefinition_DialogueObject::GetAssetDisplayName() const
{
	return LOCTEXT("DisplayName", "Dialogue Object");
}

FLinearColor UAssetDefinition_DialogueObject::GetAssetColor() const
{
	return FLinearColor(0.04f, 0.34f, 0.92f);
}

TSoftClassPtr<UObject> UAssetDefinition_DialogueObject::GetAssetClass() const
{
	return UDialogueObject::StaticClass();
}

TConstArrayView<FAssetCategoryPath> UAssetDefinition_DialogueObject::GetAssetCategories() const
{
	static const auto categories = { FAssetCategoryPath(LOCTEXT("Category", "Dialogue Tool")) };
	return categories;
}

EAssetCommandResult UAssetDefinition_DialogueObject::OpenAssets(const FAssetOpenArgs& openArgs) const
{
	for (UDialogueObject* dialogueObject : openArgs.LoadObjects<UDialogueObject>())
	{
		const TSharedRef<FDialogueObjectEditor> editor = MakeShared<FDialogueObjectEditor>();
		editor->InitDialogueObjectEditor(openArgs.GetToolkitMode(), openArgs.ToolkitHost, dialogueObject);
	}

	return EAssetCommandResult::Handled;
}

#undef LOCTEXT_NAMESPACE
