// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueCondition;
class UDialogueGraphSwitcherNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphSwitcherNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphSwitcherNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the dialogue switcher graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphSwitcherNode* switcherNode);

	// Rebuilds the node widget from switcher data.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented switcher graph node.
	UDialogueGraphSwitcherNode* GetSwitcherNode() const;

	// Creates and registers a switcher pin widget.
	TSharedRef<SGraphPin> CreateSwitcherPin(UEdGraphPin* pin);

	// Returns the node border color.
	FSlateColor GetBorderColor() const;

	// Returns the condition button icon color.
	FSlateColor GetConditionIconColor(int32 conditionIndex) const;

	// Opens the condition editor for a switcher entry.
	FReply OnOpenConditions(int32 conditionIndex);

	// Adds a switcher condition.
	FReply OnAddCondition();

	// Removes a switcher condition.
	FReply OnRemoveCondition(int32 conditionIndex);

	// Saves a switcher condition name.
	void OnConditionNameCommitted(const FText& text, ETextCommit::Type commitType, int32 conditionIndex);
};
