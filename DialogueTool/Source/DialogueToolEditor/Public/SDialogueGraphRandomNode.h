// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphRandomNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphRandomNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphRandomNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the random graph node widget.
	void Construct(const FArguments& Arguments, UDialogueGraphRandomNode* RandomNode);

	// Rebuilds the random node widget from its output data.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented random graph node.
	UDialogueGraphRandomNode* GetRandomNode() const;

	// Creates and registers a random graph pin widget.
	TSharedRef<SGraphPin> CreateRandomPin(UEdGraphPin* Pin);

	// Returns the random node border color.
	FSlateColor GetBorderColor() const;

	// Adds a random output.
	FReply OnAddOutput();

	// Removes a random output.
	FReply OnRemoveOutput(int32 OutputIndex);
};
