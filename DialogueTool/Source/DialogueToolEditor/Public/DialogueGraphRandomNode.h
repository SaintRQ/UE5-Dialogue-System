// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphRandomNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphRandomNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates one input and one pin for every random output.
	virtual void AllocateDefaultPins() override;

	// Creates runtime random data after the graph node is placed.
	virtual void PostPlacedNewNode() override;

	// Connects a dragged flow pin to this random node after creation.
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

	// Stores runtime random data before clipboard export.
	virtual void PrepareForCopying() override;

	// Creates independent runtime random data after clipboard import.
	virtual void PostPasteNode() override;

	// Recreates flow pins after the output list changes.
	virtual void ReconstructNode() override;

	// Synchronizes a changed graph connection with runtime random data.
	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;

	// Synchronizes runtime random data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Removes the associated runtime random data.
	virtual void DestroyNode() override;

	// Returns the random node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	// Returns the random node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns mutable random data represented by this graph node.
	FDialogueRandom* GetRandomData();

	// Returns random data represented by this graph node.
	const FDialogueRandom* GetRandomData() const;

	// Returns the random input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns a random output pin by index.
	UEdGraphPin* GetRandomOutputPin(int32 OutputIndex) const;

	// Returns the compact runtime identifier represented by this graph node.
	int64 GetRandomNodeId() const;

	// Returns the source identifier captured during clipboard import.
	int64 GetPastedFromRandomNodeId() const;

	// Clears temporary clipboard data after export.
	void FinishCopying();

	// Remaps copied runtime transitions to newly pasted identifiers.
	void RemapPastedConnections(const TMap<int64, int64>& PastedNodeIds);

	// Adds a random output pin.
	void AddOutput();

	// Removes a random output while preserving the required two entries.
	void RemoveOutput(int32 OutputIndex);

	// Synchronizes every random output with runtime data.
	void RefreshOutputConnections();

private:

	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Synchronizes one output with runtime data.
	void SynchronizeOutput(UEdGraphPin* Pin);

	// Refreshes graph sources that may lead to this random node.
	void RefreshSourceNodes() const;

	// Refreshes the graph after random data changes.
	void NotifyRandomChanged(bool ReconstructPins);

	UPROPERTY()
	int64 RandomNodeId = 0;

	UPROPERTY()
	FDialogueRandom ClipboardRandomData;

	UPROPERTY()
	bool HasClipboardRandomData = false;

	int64 PastedFromRandomNodeId = 0;
};
