// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EdGraphUtilities.h"

class DIALOGUETOOLEDITOR_API FDialogueGraphNodeFactory final : public FGraphPanelNodeFactory
{
public:

	// Creates Slate widgets for dialogue graph nodes.
	virtual TSharedPtr<SGraphNode> CreateNode(UEdGraphNode* node) const override;
};
