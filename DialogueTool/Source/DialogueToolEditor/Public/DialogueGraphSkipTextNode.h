// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphSkipTextNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphSkipTextNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the skip-text input and output flow pins.
	virtual void AllocateDefaultPins() override;

	// Creates runtime skip-text data after the graph node is placed.
	virtual void PostPlacedNewNode() override;

	// Connects a dragged flow pin to this skip-text node after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Stores runtime skip-text data before clipboard export.
	virtual void PrepareForCopying() override;

	// Creates independent runtime skip-text data after clipboard import.
	virtual void PostPasteNode() override;

	// Synchronizes a changed graph connection with runtime skip-text data.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Synchronizes runtime skip-text data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Removes the associated runtime skip-text data.
	virtual void DestroyNode() override;

	// Returns the skip-text node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the skip-text node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns mutable skip-text data represented by this graph node.
	FDialogueSkipText* GetSkipTextData();

	// Returns skip-text data represented by this graph node.
	const FDialogueSkipText* GetSkipTextData() const;

	// Returns the skip-text input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns the skip-text output pin.
	UEdGraphPin* GetOutputPin() const;

	// Returns the compact runtime identifier represented by this graph node.
	int64 GetSkipTextNodeId() const;

	// Returns the source identifier captured during clipboard import.
	int64 GetPastedFromSkipTextNodeId() const;

	// Clears temporary clipboard data after export.
	void FinishCopying();

	// Remaps the copied transition to newly pasted node identifiers.
	void RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds);

	// Synchronizes the stored output connection.
	void RefreshOutputConnection();

private:

	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Refreshes graph nodes that can lead into this skip-text node.
	void RefreshSourceNodes() const;

	UPROPERTY()
	int64 SkipTextNodeId = 0;

	UPROPERTY()
	FDialogueSkipText ClipboardSkipTextData;

	UPROPERTY()
	bool HasClipboardSkipTextData = false;

	int64 PastedFromSkipTextNodeId = 0;
};
