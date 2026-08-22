// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueCustomTextPopup.h"

#include "DialogueToolSettings.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueCustomTextPopup"

void SDialogueCustomTextPopup::Construct(const FArguments& arguments)
{
	Response = arguments._Response;
	OnSelected = arguments._OnSelected;

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
		.BorderBackgroundColor(FLinearColor(0.04f, 0.7f, 0.24f))
		.Padding(2.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
			.BorderBackgroundColor(FLinearColor(0.006f, 0.04f, 0.018f))
			.Padding(8.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2.0f, 2.0f, 2.0f, 7.0f)
				[
					SNew(STextBlock)
					.Text(Response
						? LOCTEXT("ResponseTitle", "Custom Response Text")
						: LOCTEXT("TopicTitle", "Custom Topic Text"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
					.ColorAndOpacity(FLinearColor(0.42f, 1.0f, 0.6f))
					.Justification(ETextJustify::Center)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2.0f, 0.0f, 2.0f, 7.0f)
				[
					SNew(SSearchBox)
					.HintText(LOCTEXT("SearchHint", "Search by ID or text..."))
					.OnTextChanged(this, &SDialogueCustomTextPopup::OnSearchTextChanged)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2.0f, 0.0f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.018f, 0.28f, 0.1f))
					.Padding(6.0f, 4.0f)
					[
						SNew(SGridPanel)
						.FillColumn(1, 1.0f)

						+ SGridPanel::Slot(0, 0)
						[
							SNew(SBox)
							.WidthOverride(180.0f)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("IdColumn", "ID"))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
							]
						]

						+ SGridPanel::Slot(1, 0)
						.Padding(8.0f, 0.0f, 0.0f, 0.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("TextColumn", "Text"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
						]
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2.0f, 2.0f, 2.0f, 0.0f)
				[
					SNew(SBox)
					.WidthOverride(680.0f)
					.MaxDesiredHeight(420.0f)
					[
						SNew(SScrollBox)
						.ScrollBarVisibility(EVisibility::Visible)

						+ SScrollBox::Slot()
						[
							SAssignNew(EntryList, SVerticalBox)
						]
					]
				]
			]
		]
	];

	RefreshEntries();
}

void SDialogueCustomTextPopup::RefreshEntries()
{
	EntryList->ClearChildren();
	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	const TMap<FName, FText>& customTextList = Response
		? settings->ResponseCustomTextList
		: settings->TopicCustomTextList;
	TArray<FName> customTextIds;
	customTextList.GenerateKeyArray(customTextIds);
	customTextIds.Sort([](const FName& left, const FName& right)
	{
		return left.LexicalLess(right);
	});

	int32 visibleEntries = 0;
	const FString searchText = SearchText.TrimStartAndEnd();
	for (const FName customTextId : customTextIds)
	{
		const FText& customText = customTextList.FindChecked(customTextId);
		if (!searchText.IsEmpty()
			&& !customTextId.ToString().Contains(searchText, ESearchCase::IgnoreCase)
			&& !customText.ToString().Contains(searchText, ESearchCase::IgnoreCase))
		{
			continue;
		}

		++visibleEntries;
		EntryList->AddSlot()
		.AutoHeight()
		.Padding(0.0f, 1.0f)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "SimpleButton")
			.ContentPadding(FMargin(6.0f, 5.0f))
			.ToolTipText(customText)
			.OnClicked(this, &SDialogueCustomTextPopup::OnEntrySelected, customTextId)
			[
				SNew(SGridPanel)
				.FillColumn(1, 1.0f)

				+ SGridPanel::Slot(0, 0)
				.VAlign(VAlign_Top)
				[
					SNew(SBox)
					.WidthOverride(180.0f)
					[
						SNew(STextBlock)
						.Text(FText::FromName(customTextId))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						.ColorAndOpacity(FLinearColor(0.42f, 1.0f, 0.6f))
					]
				]

				+ SGridPanel::Slot(1, 0)
				.Padding(8.0f, 0.0f, 0.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text(customText)
					.AutoWrapText(true)
				]
			]
		];
	}

	if (visibleEntries == 0)
	{
		EntryList->AddSlot()
		.AutoHeight()
		.HAlign(HAlign_Center)
		.Padding(12.0f)
		[
			SNew(STextBlock)
			.Text(searchText.IsEmpty()
				? LOCTEXT("NoEntries", "No custom text configured")
				: LOCTEXT("NoSearchResults", "No matching custom text"))
			.ColorAndOpacity(FLinearColor(0.5f, 0.53f, 0.58f))
		];
	}
}

void SDialogueCustomTextPopup::OnSearchTextChanged(const FText& text)
{
	SearchText = text.ToString();
	RefreshEntries();
}

FReply SDialogueCustomTextPopup::OnEntrySelected(FName customTextId)
{
	OnSelected.ExecuteIfBound(customTextId);
	FSlateApplication::Get().DismissAllMenus();
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
