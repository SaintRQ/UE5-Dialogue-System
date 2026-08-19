// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueAddButton.h"

#include "Brushes/SlateRoundedBoxBrush.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueAddButton"

void SDialogueAddButton::Construct(const FArguments& arguments)
{
	BackgroundBrush = MakeShared<FSlateRoundedBoxBrush>(arguments._Color, 10.0f);
	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(BackgroundBrush.Get())
		.Padding(0.0f)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "SimpleButton")
			.ContentPadding(FMargin(13.0f, 3.0f))
			.OnClicked(arguments._OnClicked)
			[
				SNew(STextBlock)
				.Text(arguments._Text)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
				.ColorAndOpacity(FLinearColor::White)
			]
		]
	];
}

#undef LOCTEXT_NAMESPACE
