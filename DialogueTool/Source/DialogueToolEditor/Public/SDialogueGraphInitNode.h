// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphInitNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphInitNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphInitNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the dialogue initialization graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphInitNode* initNode);

	// Rebuilds the node widget from initialization data.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented initialization graph node.
	UDialogueGraphInitNode* GetInitNode() const;

	// Creates and registers an initialization output pin widget.
	TSharedRef<SGraphPin> CreateInitPin(UEdGraphPin* pin);

	// Returns the node border color.
	FSlateColor GetBorderColor() const;

	// Returns the condition icon color for an initialization entry.
	FSlateColor GetInitConditionIconColor(int32 initIndex) const;

	// Adds an initialization entry.
	FReply OnAddInit();

	// Removes an initialization entry.
	FReply OnRemoveInit(int32 initIndex);

	// Saves an initialization entry name.
	void OnInitNameCommitted(const FText& text, ETextCommit::Type commitType, int32 initIndex);

	// Opens condition settings for an initialization entry.
	FReply OnOpenInitConditions(int32 initIndex);
};
