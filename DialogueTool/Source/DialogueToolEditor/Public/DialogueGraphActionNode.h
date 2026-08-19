// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueAction.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphActionNode.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphActionNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:
	// Restores the required action entry after loading a graph node.
	virtual void PostLoad() override;

	// Creates the input and output flow pins.
	virtual void AllocateDefaultPins() override;

	// Creates the required action entry for a new graph node.
	virtual void PostPlacedNewNode() override;

	// Connects a dragged flow pin to this action node after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Creates independent action instances after clipboard import.
	virtual void PostPasteNode() override;

	// Refreshes dialogue data after a pin connection changes.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Refreshes dialogue data after node links change.
	virtual void NodeConnectionListChanged() override;

	// Clears linked runtime actions before removal.
	virtual void DestroyNode() override;

	// Returns the action node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the action node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns the action input pin.
	UEdGraphPin* GetInputPin() const;

	// Returns the action output pin.
	UEdGraphPin* GetOutputPin() const;

	// Returns action instances stored by this graph node.
	const TArray<TObjectPtr<UDialogueAction>>& GetActions() const;

	// Adds an empty action entry.
	void AddAction();

	// Removes an action entry.
	void RemoveAction(int32 actionIndex);

	// Changes an action class entry.
	void SetActionClass(int32 actionIndex, const UClass* actionClass);

private:
	// Returns the dialogue asset that owns this graph node.
	class UDialogueObject* GetDialogueObject() const;

	// Updates linked runtime dialogue data and the graph widget.
	void NotifyActionsChanged();

	// Refreshes all dialogue outputs that may pass through this node.
	void RefreshDialogueNodes() const;

	UPROPERTY()
	TArray<TObjectPtr<UDialogueAction>> Actions;
};
