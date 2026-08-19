// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueAction;
class UDialogueGraphActionNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphActionNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphActionNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the dialogue action graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphActionNode* actionNode);

	// Rebuilds the node widget from action data.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented action graph node.
	UDialogueGraphActionNode* GetActionNode() const;

	// Creates and registers a graph pin widget.
	TSharedRef<SGraphPin> CreateActionPin(UEdGraphPin* pin);

	// Returns the node border color.
	FSlateColor GetBorderColor() const;

	// Returns an action instance.
	UDialogueAction* GetAction(int32 actionIndex) const;

	// Saves a selected action class.
	void OnActionClassSet(const UClass* actionClass, int32 actionIndex);

	// Adds an action class entry.
	FReply OnAddAction();

	// Removes an action class entry.
	FReply OnRemoveAction(int32 actionIndex);
};
