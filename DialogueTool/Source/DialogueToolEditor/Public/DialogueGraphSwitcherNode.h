// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphSwitcherNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphSwitcherNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the input and one output pin for every switcher condition.
	virtual void AllocateDefaultPins() override;

	// Creates runtime switcher data after the graph node is placed.
	virtual void PostPlacedNewNode() override;

	// Connects a dragged flow pin to this switcher node after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Stores runtime switcher data before clipboard export.
	virtual void PrepareForCopying() override;

	// Creates independent runtime switcher data after clipboard import.
	virtual void PostPasteNode() override;

	// Recreates flow pins after the condition list changes.
	virtual void ReconstructNode() override;

	// Synchronizes a changed graph connection with runtime switcher data.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Synchronizes runtime switcher data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Removes the associated runtime switcher data.
	virtual void DestroyNode() override;

	// Returns the switcher node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the switcher node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns mutable switcher data represented by this graph node.
	FDialogueSwitcher* GetSwitcherData();

	// Returns switcher data represented by this graph node.
	const FDialogueSwitcher* GetSwitcherData() const;

	// Returns the switcher input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns the output pin for a switcher condition.
	UEdGraphPin* GetConditionOutputPin(int32 conditionIndex) const;

	// Returns the compact runtime identifier represented by this graph node.
	int64 GetSwitcherNodeId() const;

	// Returns the source identifier captured during clipboard import.
	int64 GetPastedFromSwitcherNodeId() const;

	// Clears temporary clipboard data after export.
	void FinishCopying();

	// Remaps copied runtime transitions to newly pasted identifiers.
	void RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds);

	// Adds a switcher condition.
	void AddCondition();

	// Removes a switcher condition while preserving the required two entries.
	void RemoveCondition(int32 conditionIndex);

	// Changes a switcher condition name.
	void SetConditionName(int32 conditionIndex, FName name);

	// Adds a requirement to a switcher condition.
	void AddConditionRequirement(int32 conditionIndex);

	// Removes a requirement from a switcher condition.
	void RemoveConditionRequirement(int32 conditionIndex, int32 requirementIndex);

	// Changes a switcher condition requirement class.
	void SetConditionRequirementClass(int32 conditionIndex, int32 requirementIndex, const UClass* conditionClass);

	// Synchronizes every switcher output with runtime data.
	void RefreshOutputConnections();

private:

	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Synchronizes one output with runtime data.
	void SynchronizeOutput(UEdGraphPin* pin);

	// Refreshes graph sources that may lead to this switcher.
	void RefreshSourceNodes() const;

	// Refreshes the graph after switcher data changes.
	void NotifySwitcherChanged(bool bReconstructPins);

	UPROPERTY()
	int64 SwitcherNodeId = 0;

	UPROPERTY()
	FDialogueSwitcher ClipboardSwitcherData;

	UPROPERTY()
	bool HasClipboardSwitcherData = false;

	int64 PastedFromSwitcherNodeId = 0;
};
