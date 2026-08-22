// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SGraphNode.h"

class UDialogueGraphNode;

class DIALOGUETOOLEDITOR_API SDialogueGraphNode final : public SGraphNode
{
public:

	SLATE_BEGIN_ARGS(SDialogueGraphNode)
	{
	}
	SLATE_END_ARGS()

	// Constructs the dialogue graph node widget.
	void Construct(const FArguments& arguments, UDialogueGraphNode* dialogueNode);

	// Rebuilds the node widget from dialogue data.
	virtual void UpdateGraphNode() override;

private:

	// Returns the represented dialogue graph node.
	UDialogueGraphNode* GetDialogueNode() const;

	// Creates and registers a graph pin widget.
	TSharedRef<SGraphPin> CreateDialoguePin(UEdGraphPin* pin);

	// Returns the node border color.
	FSlateColor GetBorderColor() const;

	// Returns the condition icon color for a response.
	FSlateColor GetResponseConditionIconColor(int32 responseIndex) const;

	// Returns the always-visible icon color for a response.
	FSlateColor GetResponseAlwaysVisibleIconColor(int32 responseIndex) const;

	// Returns the icon color for an assigned text or response sound.
	FSlateColor GetSoundIconColor(bool response, int32 entryIndex) const;

	// Adds a root text entry.
	FReply OnAddRootText();

	// Removes a root text entry.
	FReply OnRemoveRootText(int32 textIndex);

	// Saves a root text entry.
	void OnRootTextCommitted(const FText& text, ETextCommit::Type commitType, int32 textIndex);

	// Adds a response entry.
	FReply OnAddResponse();

	// Opens the custom topic or response text menu.
	FReply OnOpenCustomTextMenu(bool response);

	// Adds a topic or response entry linked to a custom text identifier.
	void OnAddCustomText(FName customTextId, bool response);

	// Adds the terminal response entry.
	FReply OnAddFinishResponse();

	// Removes a response entry.
	FReply OnRemoveResponse(int32 responseIndex);

	// Opens condition settings for a response.
	FReply OnOpenResponseConditions(int32 responseIndex);

	// Opens sound selection for a text or response entry.
	FReply OnOpenSound(bool response, int32 entryIndex);

	// Toggles whether a failed response remains visible.
	FReply OnToggleResponseAlwaysVisible(int32 responseIndex);

	// Saves a response entry.
	void OnResponseTextCommitted(const FText& text, ETextCommit::Type commitType, int32 responseIndex);
};
