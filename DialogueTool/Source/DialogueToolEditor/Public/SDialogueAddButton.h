// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Input/SButton.h"
#include "Widgets/SCompoundWidget.h"

struct FSlateRoundedBoxBrush;

class DIALOGUETOOLEDITOR_API SDialogueAddButton final : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogueAddButton)
		: _Color(FLinearColor(0.08f, 0.4f, 0.8f))
		, _Text(NSLOCTEXT("SDialogueAddButton", "Add", "Add"))
	{
	}
		SLATE_ARGUMENT(FLinearColor, Color)
		SLATE_ARGUMENT(FText, Text)
		SLATE_EVENT(FOnClicked, OnClicked)
	SLATE_END_ARGS()

	// Constructs a compact colored add button.
	void Construct(const FArguments& arguments);

private:

	TSharedPtr<FSlateRoundedBoxBrush> BackgroundBrush;
};
