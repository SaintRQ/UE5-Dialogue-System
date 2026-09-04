// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetDefinition_MonologueObjects.h"

#include "DialogueObjectEditor.h"
#include "Monologue/MonologueLibraryObject.h"
#include "Monologue/MonologueObject.h"

#define LOCTEXT_NAMESPACE "AssetDefinition_MonologueObjects"

FText UAssetDefinition_MonologueObject::GetAssetDisplayName() const
{
	return LOCTEXT("ObjectDisplayName", "Monologue Object");
}

FLinearColor UAssetDefinition_MonologueObject::GetAssetColor() const
{
	return FLinearColor(0.04f, 0.7f, 0.24f);
}

TSoftClassPtr<UObject> UAssetDefinition_MonologueObject::GetAssetClass() const
{
	return UMonologueObject::StaticClass();
}

TConstArrayView<FAssetCategoryPath> UAssetDefinition_MonologueObject::GetAssetCategories() const
{
	static const auto categories = {
		FAssetCategoryPath(
			LOCTEXT("Category", "Dialogue Tool"),
			LOCTEXT("MonologueCategory", "Monologue"))
	};
	return categories;
}

EAssetCommandResult UAssetDefinition_MonologueObject::OpenAssets(const FAssetOpenArgs& OpenArgs) const
{
	for (UMonologueObject* monologueObject : OpenArgs.LoadObjects<UMonologueObject>())
	{
		const TSharedRef<FDialogueObjectEditor> editor = MakeShared<FDialogueObjectEditor>();
		editor->InitDialogueObjectEditor(OpenArgs.GetToolkitMode(), OpenArgs.ToolkitHost, monologueObject);
	}

	return EAssetCommandResult::Handled;
}

FText UAssetDefinition_MonologueLibraryObject::GetAssetDisplayName() const
{
	return LOCTEXT("LibraryDisplayName", "Monologue Library");
}

FLinearColor UAssetDefinition_MonologueLibraryObject::GetAssetColor() const
{
	return FLinearColor(0.42f, 0.08f, 0.72f);
}

TSoftClassPtr<UObject> UAssetDefinition_MonologueLibraryObject::GetAssetClass() const
{
	return UMonologueLibraryObject::StaticClass();
}

TConstArrayView<FAssetCategoryPath> UAssetDefinition_MonologueLibraryObject::GetAssetCategories() const
{
	static const auto categories = {
		FAssetCategoryPath(
			LOCTEXT("Category", "Dialogue Tool"),
			LOCTEXT("MonologueCategory", "Monologue"))
	};
	return categories;
}

EAssetCommandResult UAssetDefinition_MonologueLibraryObject::OpenAssets(const FAssetOpenArgs& OpenArgs) const
{
	for (UMonologueLibraryObject* monologueLibrary : OpenArgs.LoadObjects<UMonologueLibraryObject>())
	{
		const TSharedRef<FDialogueObjectEditor> editor = MakeShared<FDialogueObjectEditor>();
		editor->InitDialogueObjectEditor(OpenArgs.GetToolkitMode(), OpenArgs.ToolkitHost, monologueLibrary);
	}

	return EAssetCommandResult::Handled;
}

#undef LOCTEXT_NAMESPACE
