// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AssetDefinitionDefault.h"

#include "AssetDefinition_DialogueObject.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UAssetDefinition_DialogueObject final : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:

	// Returns the dialogue object name shown in the editor.
	virtual FText GetAssetDisplayName() const override;

	// Returns the dialogue object color shown in the editor.
	virtual FLinearColor GetAssetColor() const override;

	// Returns the asset class handled by this definition.
	virtual TSoftClassPtr<UObject> GetAssetClass() const override;

	// Returns the Content Browser creation category.
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override;

	// Opens dialogue objects in the dialogue graph editor.
	virtual EAssetCommandResult OpenAssets(const FAssetOpenArgs& openArgs) const override;
};
