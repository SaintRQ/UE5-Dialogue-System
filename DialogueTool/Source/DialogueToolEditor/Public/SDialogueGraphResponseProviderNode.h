// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphResponseProviderNode;
class UDialogueProvider;

class DIALOGUETOOLEDITOR_API SDialogueGraphResponseProviderNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphResponseProviderNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the response provider graph node widget.
	void Construct(
		const FArguments& arguments,
		UDialogueGraphResponseProviderNode* responseProviderNode);

	// Rebuilds the response provider node widget.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented response provider graph node.
	UDialogueGraphResponseProviderNode* GetResponseProviderNode() const;

	// Creates and registers the provider output pin widget.
	TSharedRef<SGraphPin> CreateProviderPin(UEdGraphPin* pin);

	// Returns the configured dialogue provider.
	UDialogueProvider* GetDialogueProvider() const;

	// Saves the selected response provider class.
	void OnResponseProviderClassChanged(const UClass* responseProviderClass);

	// Returns the response provider border color.
	FSlateColor GetBorderColor() const;
};
