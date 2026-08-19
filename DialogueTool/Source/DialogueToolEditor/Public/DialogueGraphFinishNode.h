// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphFinishNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphFinishNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the terminal input flow pin.
	virtual void AllocateDefaultPins() override;

	// Connects a dragged output pin to this terminal node.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Returns the terminal node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the terminal node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns the terminal input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns whether this terminal returns from a dialogue library.
	bool IsReturnNode() const;
};
