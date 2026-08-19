// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AssetDefinitionDefault.h"

#include "AssetDefinition_DialogueLibraryObject.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UAssetDefinition_DialogueLibraryObject final : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:

	// Returns the dialogue library name shown in the editor.
	virtual FText GetAssetDisplayName() const override;

	// Returns the dialogue library color shown in the editor.
	virtual FLinearColor GetAssetColor() const override;

	// Returns the asset class handled by this definition.
	virtual TSoftClassPtr<UObject> GetAssetClass() const override;

	// Returns the Content Browser creation category.
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override;

	// Opens dialogue libraries in the dialogue graph editor.
	virtual EAssetCommandResult OpenAssets(const FAssetOpenArgs& openArgs) const override;
};
