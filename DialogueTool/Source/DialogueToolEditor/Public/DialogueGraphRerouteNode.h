// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphRerouteNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphRerouteNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the input and output flow pins.
	virtual void AllocateDefaultPins() override;

	// Connects a dragged flow pin to this reroute node after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Refreshes upstream runtime transitions after a pin connection changes.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Refreshes upstream runtime transitions after node links change.
	virtual void NodeConnectionListChanged() override;

	// Draws this node as a compact graph control point.
	virtual bool ShouldDrawNodeAsControlPointOnly(int32& outInputPinIndex, int32& outOutputPinIndex) const override;

	// Returns the reroute node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the reroute node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns the reroute input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns the reroute output pin.
	UEdGraphPin* GetOutputPin() const;

private:

	// Refreshes dialogue nodes connected before this reroute chain.
	void RefreshUpstreamDialogueNodes(TSet<const UEdGraphNode*>& visitedNodes) const;
};
