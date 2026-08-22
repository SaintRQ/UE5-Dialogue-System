// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphSkipTextNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphSkipTextNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphSkipTextNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the skip-text graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphSkipTextNode* skipTextNode);

	// Rebuilds the skip-text node widget.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented skip-text graph node.
	UDialogueGraphSkipTextNode* GetSkipTextNode() const;

	// Creates and registers a skip-text graph pin widget.
	TSharedRef<SGraphPin> CreateSkipTextPin(UEdGraphPin* pin);

	// Returns the skip-text border color.
	FSlateColor GetBorderColor() const;
};
