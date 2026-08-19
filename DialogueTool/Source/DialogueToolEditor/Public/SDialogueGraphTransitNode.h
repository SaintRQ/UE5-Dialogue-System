// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphTransitNode;
struct FAssetData;

class DIALOGUETOOLEDITOR_API SDialogueGraphTransitNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphTransitNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the dialogue transit graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphTransitNode* transitNode);

	// Rebuilds the transit node widget.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented transit graph node.
	UDialogueGraphTransitNode* GetTransitNode() const;

	// Creates and registers a transit graph pin widget.
	TSharedRef<SGraphPin> CreateTransitPin(UEdGraphPin* pin);

	// Returns the selected dialogue library object path.
	FString GetDialogueLibraryPath() const;

	// Saves the selected dialogue library.
	void OnDialogueLibraryChanged(const FAssetData& assetData);

	// Returns the transit border color.
	FSlateColor GetBorderColor() const;
};
