// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"

#include "DialogueGraphResponseProviderNode.generated.h"

class UDialogueProvider;

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphResponseProviderNode final : public UEdGraphNode
{
	GENERATED_BODY()

public:

	// Creates the response provider output pin.
	virtual void AllocateDefaultPins() override;

	// Connects the provider to a response input after creation.
	virtual void AutowireNewNode(UEdGraphPin* fromPin) override;

	// Duplicates provider data into the destination dialogue after pasting.
	virtual void PostPasteNode() override;

	// Synchronizes linked responses after a connection changes.
	virtual void PinConnectionListChanged(UEdGraphPin* pin) override;

	// Synchronizes linked responses after node links change.
	virtual void NodeConnectionListChanged() override;

	// Clears provider data from linked responses before deletion.
	virtual void DestroyNode() override;

	// Returns the response provider node title.
	virtual FText GetNodeTitle(ENodeTitleType::Type titleType) const override;

	// Returns the response provider node tooltip.
	virtual FText GetTooltipText() const override;

	// Returns the response provider output pin.
	UEdGraphPin* GetOutputPin() const;

	// Returns the selected dialogue provider class.
	UClass* GetResponseProviderClass() const;

	// Returns the configured dialogue provider.
	UDialogueProvider* GetDialogueProvider() const;

	// Saves the selected response provider class.
	void SetResponseProviderClass(const UClass* responseProviderClass);

private:

	// Synchronizes provider data for every topic in this graph.
	void RefreshDialogueNodes() const;

	// Refreshes the node and owning dialogue asset after provider changes.
	void NotifyProviderChanged();

	UPROPERTY(Instanced)
	TObjectPtr<UDialogueProvider> DialogueProvider = nullptr;
};
