// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphInitNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphInitNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates one output flow pin for every initialization entry.
	virtual void AllocateDefaultPins() override;

	// Recreates output pins after the initialization list changes.
	virtual void ReconstructNode() override;

	// Synchronizes a changed graph connection with runtime initialization data.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Synchronizes initialization data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Prevents users from deleting the required initialization node.
	virtual bool CanUserDeleteNode() const override;

	// Prevents creating a second initialization node through duplication.
	virtual bool CanDuplicateNode() const override;

	// Returns the initialization node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the initialization node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns mutable initialization data represented by this graph node.
	TArray<FDialogueInit>* GetInitData();

	// Returns initialization data represented by this graph node.
	const TArray<FDialogueInit>* GetInitData() const;

	// Returns the output pin for an initialization entry.
	UEdGraphPin* GetInitOutputPin(int32 initIndex) const;

	// Adds an empty initialization entry.
	void AddInit();

	// Removes an initialization entry.
	void RemoveInit(int32 initIndex);

	// Changes an initialization entry name.
	void SetInitName(int32 initIndex, FName name);

	// Adds an empty condition entry to an initialization entry.
	void AddInitCondition(int32 initIndex);

	// Removes a condition entry from an initialization entry.
	void RemoveInitCondition(int32 initIndex, int32 conditionIndex);

	// Changes an initialization condition class.
	void SetInitConditionClass(int32 initIndex, int32 conditionIndex, const UClass* conditionClass);

private:

	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Refreshes the graph after initialization data changes.
	void NotifyInitChanged(bool bReconstructPins);
};
