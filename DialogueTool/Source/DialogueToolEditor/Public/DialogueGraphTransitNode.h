// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphTransitNode.generated.h"

class UDialogueLibraryObject;

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphTransitNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the transit input and return output flow pins.
	virtual void AllocateDefaultPins() override;

	// Creates runtime transit data after the graph node is placed.
	virtual void PostPlacedNewNode() override;

	// Connects a dragged flow pin to this transit node after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Stores runtime transit data in the graph node before clipboard export.
	virtual void PrepareForCopying() override;

	// Creates independent runtime transit data after clipboard import.
	virtual void PostPasteNode() override;

	// Synchronizes a changed graph connection with runtime transit data.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Synchronizes runtime transit data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Removes the associated runtime transit data.
	virtual void DestroyNode() override;

	// Prevents transit nodes from being created in dialogue libraries.
	virtual bool CanCreateUnderSpecifiedSchema(const UEdGraphSchema* schema) const override;

	// Returns the transit node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the transit node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns mutable transit data represented by this graph node.
	FDialogueTransit* GetTransitData();

	// Returns transit data represented by this graph node.
	const FDialogueTransit* GetTransitData() const;

	// Returns the transit input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns the transit return output pin.
	UEdGraphPin* GetOutputPin() const;

	// Returns the compact runtime identifier represented by this graph node.
	int64 GetTransitNodeId() const;

	// Returns the source identifier captured during clipboard import.
	int64 GetPastedFromTransitNodeId() const;

	// Clears temporary clipboard data after export.
	void FinishCopying();

	// Remaps the copied return transition to newly pasted node identifiers.
	void RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds);

	// Changes the dialogue library entered by this transit.
	void SetDialogueLibrary(UDialogueLibraryObject* dialogueLibrary);

	// Synchronizes the stored return connection.
	void RefreshOutputConnection();

private:

	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Refreshes graph nodes that can lead into this transit.
	void RefreshSourceNodes() const;

	// Refreshes the graph after transit data changes.
	void NotifyTransitChanged();

	UPROPERTY()
	int64 TransitNodeId = 0;

	UPROPERTY()
	FDialogueTransit ClipboardTransitData;

	UPROPERTY()
	bool HasClipboardTransitData = false;

	int64 PastedFromTransitNodeId = 0;
};
