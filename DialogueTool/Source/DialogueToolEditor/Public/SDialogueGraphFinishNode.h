// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphFinishNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphFinishNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphFinishNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the terminal dialogue graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphFinishNode* finishNode);

	// Rebuilds the terminal node widget.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented terminal graph node.
	UDialogueGraphFinishNode* GetFinishNode() const;

	// Creates and registers the terminal input pin widget.
	TSharedRef<SGraphPin> CreateFinishPin(UEdGraphPin* pin);

	// Returns the terminal border color.
	FSlateColor GetBorderColor() const;
};
