// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueConditionPopup.h"

#include "Brushes/SlateRoundedBoxBrush.h"
#include "DialogueCondition.h"
#include "SDialogueAddButton.h"
#include "SDialogueObjectEntry.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueConditionPopup"

void SDialogueConditionPopup::Construct(const FArguments& arguments)
{
	ConditionCount = arguments._ConditionCount;
	ConditionMode = arguments._ConditionMode;
	OnGetCondition = arguments._OnGetCondition;
	OnSetConditionClass = arguments._OnSetConditionClass;
	OnAddCondition = arguments._OnAddCondition;
	OnRemoveCondition = arguments._OnRemoveCondition;
	OnSetConditionMode = arguments._OnSetConditionMode;
	AllModeBrush = MakeShared<FSlateRoundedBoxBrush>(FLinearColor(0.06f, 0.38f, 0.92f, 0.5f), 8.0f);
	AnyModeBrush = MakeShared<FSlateRoundedBoxBrush>(FLinearColor(0.04f, 0.7f, 0.24f, 0.5f), 8.0f);

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
		.BorderBackgroundColor(FLinearColor(0.72f, 0.46f, 0.04f))
		.Padding(2.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
			.BorderBackgroundColor(FLinearColor(0.008f, 0.012f, 0.018f))
			.Padding(1.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(2.0f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.45f, 0.27f, 0.025f))
					.Padding(8.0f, 5.0f)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("ConditionsTitle", "Conditions"))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
						.Justification(ETextJustify::Center)
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				.Padding(2.0f, 4.0f, 2.0f, 7.0f)
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(0.0f, 0.0f, 8.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("ConditionMode", "MATCH"))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBorder)
						.BorderImage(this, &SDialogueConditionPopup::GetModeBrush)
						.Padding(0.0f)
						[
							SNew(SButton)
							.ButtonStyle(FAppStyle::Get(), "SimpleButton")
							.ContentPadding(FMargin(14.0f, 3.0f))
							.OnClicked(this, &SDialogueConditionPopup::OnConditionModeClicked)
							[
								SNew(STextBlock)
								.Text(this, &SDialogueConditionPopup::GetModeText)
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
								.ColorAndOpacity(this, &SDialogueConditionPopup::GetModeTextColor)
							]
						]
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBox)
					.MinDesiredWidth(420.0f)
					.MaxDesiredHeight(360.0f)
					[
						SNew(SScrollBox)

						+ SScrollBox::Slot()
						[
							SAssignNew(ConditionList, SVerticalBox)
						]
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				.Padding(2.0f, 5.0f, 2.0f, 2.0f)
				[
					SNew(SDialogueAddButton)
					.Color(FLinearColor(0.82f, 0.48f, 0.04f))
					.OnClicked(this, &SDialogueConditionPopup::OnAddConditionClicked)
				]
			]
		]
	];

	RefreshConditions();
}

void SDialogueConditionPopup::RefreshConditions()
{
	ConditionList->ClearChildren();
	for (int32 conditionIndex = 0; conditionIndex < ConditionCount.Get(); ++conditionIndex)
	{
		TSharedRef<SHorizontalBox> conditionRow = SNew(SHorizontalBox);
		conditionRow->AddSlot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(0.0f, 0.0f, 6.0f, 0.0f)
		[
			SNew(STextBlock)
			.Text(FText::AsNumber(conditionIndex + 1))
		];

		conditionRow->AddSlot()
		.FillWidth(1.0f)
		.VAlign(VAlign_Center)
		[
			SNew(SDialogueObjectEntry)
			.BaseClass(UDialogueCondition::StaticClass())
			.Object_Lambda([this, conditionIndex]() -> UObject*
			{
				return GetCondition(conditionIndex);
			})
			.OnSetClass(FOnSetDialogueObjectClass::CreateSP(
				this,
				&SDialogueConditionPopup::OnConditionClassSet,
				conditionIndex))
		];

		conditionRow->AddSlot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(4.0f, 0.0f, 0.0f, 0.0f)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "SimpleButton")
			.ToolTipText(LOCTEXT("RemoveConditionTooltip", "Remove this condition."))
			.OnClicked(this, &SDialogueConditionPopup::OnRemoveConditionClicked, conditionIndex)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("RemoveCondition", "-"))
			]
		];

		ConditionList->AddSlot()
		.AutoHeight()
		.Padding(2.0f)
		[
			conditionRow
		];
	}
}

UDialogueCondition* SDialogueConditionPopup::GetCondition(int32 conditionIndex) const
{
	return OnGetCondition.IsBound() ? OnGetCondition.Execute(conditionIndex) : nullptr;
}

const FSlateBrush* SDialogueConditionPopup::GetModeBrush() const
{
	return ConditionMode.Get() == EDialogueConditionMode::All
		? AllModeBrush.Get()
		: AnyModeBrush.Get();
}

FText SDialogueConditionPopup::GetModeText() const
{
	return ConditionMode.Get() == EDialogueConditionMode::All
		? LOCTEXT("AllMode", "ALL")
		: LOCTEXT("AnyMode", "ANY");
}

FSlateColor SDialogueConditionPopup::GetModeTextColor() const
{
	return ConditionMode.Get() == EDialogueConditionMode::All
		? FLinearColor(0.42f, 0.72f, 1.0f)
		: FLinearColor(0.42f, 1.0f, 0.6f);
}

void SDialogueConditionPopup::OnConditionClassSet(const UClass* conditionClass, int32 conditionIndex)
{
	OnSetConditionClass.ExecuteIfBound(conditionClass, conditionIndex);
}

FReply SDialogueConditionPopup::OnConditionModeClicked()
{
	OnSetConditionMode.ExecuteIfBound(ConditionMode.Get() == EDialogueConditionMode::All
		? EDialogueConditionMode::Any
		: EDialogueConditionMode::All);
	return FReply::Handled();
}

FReply SDialogueConditionPopup::OnAddConditionClicked()
{
	OnAddCondition.ExecuteIfBound();
	RefreshConditions();
	return FReply::Handled();
}

FReply SDialogueConditionPopup::OnRemoveConditionClicked(int32 conditionIndex)
{
	OnRemoveCondition.ExecuteIfBound(conditionIndex);
	RefreshConditions();
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
