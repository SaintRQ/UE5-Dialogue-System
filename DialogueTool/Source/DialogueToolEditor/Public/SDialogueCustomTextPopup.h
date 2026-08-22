// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"

class SVerticalBox;

DECLARE_DELEGATE_OneParam(FOnDialogueCustomTextSelected, FName);

class DIALOGUETOOLEDITOR_API SDialogueCustomTextPopup final : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogueCustomTextPopup)
		: _Response(false)
	{
	}
		SLATE_ARGUMENT(bool, Response)
		SLATE_EVENT(FOnDialogueCustomTextSelected, OnSelected)
	SLATE_END_ARGS()

	// Constructs a searchable custom text selection popup.
	void Construct(const FArguments& arguments);

private:

	// Rebuilds rows matching the current search query.
	void RefreshEntries();

	// Updates the current search query.
	void OnSearchTextChanged(const FText& text);

	// Selects a custom text identifier and closes the popup.
	FReply OnEntrySelected(FName customTextId);

	bool Response = false;
	FString SearchText;
	FOnDialogueCustomTextSelected OnSelected;
	TSharedPtr<SVerticalBox> EntryList;
};
