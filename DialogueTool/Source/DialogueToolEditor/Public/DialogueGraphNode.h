// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the flow pins represented by the dialogue data.
	virtual void AllocateDefaultPins() override;

	// Creates runtime dialogue data after the graph node is placed.
	virtual void PostPlacedNewNode() override;

	// Connects a dragged flow pin to this dialogue node after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Stores runtime dialogue data in the graph node before clipboard export.
	virtual void PrepareForCopying() override;

	// Creates independent runtime dialogue data after clipboard import.
	virtual void PostPasteNode() override;

	// Recreates flow pins after the response list changes.
	virtual void ReconstructNode() override;

	// Synchronizes a changed graph connection with runtime dialogue data.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Synchronizes runtime dialogue data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Removes the associated runtime dialogue data.
	virtual void DestroyNode() override;

	// Returns the title displayed on the graph node.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the graph node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns mutable dialogue data represented by this graph node.
	FDialogueNode* GetDialogueData();

	// Returns dialogue data represented by this graph node.
	const FDialogueNode* GetDialogueData() const;

	// Returns the input flow pin.
	UEdGraphPin* GetInputPin() const;

	// Returns the output used when the node has no responses.
	UEdGraphPin* GetDefaultOutputPin() const;

	// Returns the output pin for a response.
	UEdGraphPin* GetResponseOutputPin(int32 responseIndex) const;

	// Returns the compact runtime identifier represented by this graph node.
	int64 GetDialogueNodeId() const;

	// Returns the source identifier captured during clipboard import.
	int64 GetPastedFromDialogueNodeId() const;

	// Clears temporary clipboard data after export.
	void FinishCopying();

	// Remaps copied runtime transitions to newly pasted node identifiers.
	void RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds);

	// Adds an empty root text entry.
	void AddRootText();

	// Removes a root text entry.
	void RemoveRootText(int32 textIndex);

	// Changes a root text entry.
	void SetRootText(int32 textIndex, const FText& text);

	// Adds an empty response.
	void AddResponse();

	// Adds the single terminal response.
	void AddFinishResponse();

	// Removes a response.
	void RemoveResponse(int32 responseIndex);

	// Changes a response text.
	void SetResponseText(int32 responseIndex, const FText& text);

	// Toggles whether a failed response remains visible.
	void ToggleResponseAlwaysVisible(int32 responseIndex);

	// Adds an empty condition entry to a response.
	void AddResponseCondition(int32 responseIndex);

	// Removes a condition entry from a response.
	void RemoveResponseCondition(int32 responseIndex, int32 conditionIndex);

	// Changes a response condition class.
	void SetResponseConditionClass(int32 responseIndex, int32 conditionIndex, const UClass* conditionClass);

private:

	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Refreshes the graph after dialogue data changes.
	void NotifyDialogueChanged(bool bReconstructPins);

	UPROPERTY()
	int64 DialogueNodeId = 0;

	UPROPERTY()
	FDialogueNode ClipboardDialogueData;

	UPROPERTY()
	bool HasClipboardDialogueData = false;

	int64 PastedFromDialogueNodeId = 0;
};
