// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueConditionPopup.h"

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
	OnGetCondition = arguments._OnGetCondition;
	OnSetConditionClass = arguments._OnSetConditionClass;
	OnAddCondition = arguments._OnAddCondition;
	OnRemoveCondition = arguments._OnRemoveCondition;

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
			.Padding(6.0f)
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

void SDialogueConditionPopup::OnConditionClassSet(const UClass* conditionClass, int32 conditionIndex)
{
	OnSetConditionClass.ExecuteIfBound(conditionClass, conditionIndex);
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
