// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AssetDefinitionDefault.h"

#include "AssetDefinition_MonologueObjects.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UAssetDefinition_MonologueObject final : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:

	// Returns the monologue object name shown in the editor.
	virtual FText GetAssetDisplayName() const override;

	// Returns the monologue object color shown in the editor.
	virtual FLinearColor GetAssetColor() const override;

	// Returns the asset class handled by this definition.
	virtual TSoftClassPtr<UObject> GetAssetClass() const override;

	// Returns the nested Content Browser creation category.
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override;

	// Opens monologue objects in the monologue graph editor.
	virtual EAssetCommandResult OpenAssets(const FAssetOpenArgs& OpenArgs) const override;
};

UCLASS()
class DIALOGUETOOLEDITOR_API UAssetDefinition_MonologueLibraryObject final : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:

	// Returns the monologue library name shown in the editor.
	virtual FText GetAssetDisplayName() const override;

	// Returns the monologue library color shown in the editor.
	virtual FLinearColor GetAssetColor() const override;

	// Returns the asset class handled by this definition.
	virtual TSoftClassPtr<UObject> GetAssetClass() const override;

	// Returns the nested Content Browser creation category.
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override;

	// Opens monologue libraries in the monologue graph editor.
	virtual EAssetCommandResult OpenAssets(const FAssetOpenArgs& OpenArgs) const override;
};
