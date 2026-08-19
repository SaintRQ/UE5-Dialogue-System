// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Input/SMultiLineEditableTextBox.h"

class FMenuBuilder;

class DIALOGUETOOLEDITOR_API SDialogueRichTextEditor final : public SMultiLineEditableTextBox
{
public:

	SLATE_BEGIN_ARGS(SDialogueRichTextEditor)
		: _AutoWrapText(false)
	{
	}
		SLATE_ATTRIBUTE(FText, Text)
		SLATE_ATTRIBUTE(FText, HintText)
		SLATE_ARGUMENT(bool, AutoWrapText)
		SLATE_EVENT(FOnTextCommitted, OnTextCommitted)
	SLATE_END_ARGS()

	// Constructs an editable dialogue text box with rich-text tag actions.
	void Construct(const FArguments& arguments);

private:

	// Adds configured rich-text styles to the standard text context menu.
	void ExtendContextMenu(FMenuBuilder& menuBuilder);

	// Wraps the selected text in the specified rich-text tag.
	void ApplyRichTextTag(FName tagName);

	// Returns whether selected text can be wrapped in a tag.
	bool CanApplyRichTextTag() const;

	FOnTextCommitted OnDialogueTextCommitted;
};
