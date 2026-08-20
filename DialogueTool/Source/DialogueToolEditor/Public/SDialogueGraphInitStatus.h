// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"

class UEdGraphNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphInitStatus final : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphInitStatus)
		: _ShowStatus(true)
	{
	}
		SLATE_ARGUMENT(bool, ShowStatus)
	SLATE_END_ARGS()

	// Constructs an initialization connection status indicator.
	void Construct(const FArguments& arguments, UEdGraphNode* graphNode);

private:

	// Returns the current connection status color.
	FSlateColor GetStatusColor() const;

	// Returns the current connection status tooltip.
	FText GetStatusTooltip() const;

	// Deletes the represented graph node.
	FReply OnDeleteNode();

	TWeakObjectPtr<UEdGraphNode> GraphNode;
};
