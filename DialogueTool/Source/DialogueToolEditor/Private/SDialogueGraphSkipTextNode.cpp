// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphSkipTextNode.h"

#include "DialogueGraphSkipTextNode.h"
#include "SDialogueGraphInitStatus.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphSkipTextNode"

void SDialogueGraphSkipTextNode::Construct(
	const FArguments& arguments,
	UDialogueGraphSkipTextNode* skipTextNode)
{
	GraphNode = skipTextNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(skipTextNode ? skipTextNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphSkipTextNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphSkipTextNode* skipTextNode = GetSkipTextNode();
	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	TSharedRef<SWidget> outputWidget = SNullWidget::NullWidget;
	if (skipTextNode)
	{
		if (UEdGraphPin* inputPin = skipTextNode->GetInputPin())
		{
			inputWidget = CreateSkipTextPin(inputPin);
		}
		if (UEdGraphPin* outputPin = skipTextNode->GetOutputPin())
		{
			outputWidget = CreateSkipTextPin(outputPin);
		}
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphSkipTextNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
			.BorderBackgroundColor(FLinearColor(0.06f, 0.045f, 0.012f))
			.Padding(0.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.42f, 0.27f, 0.035f))
					.Padding(8.0f, 6.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NodeTitle", "SKIP TEXT"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
							.ColorAndOpacity(FLinearColor(1.0f, 0.72f, 0.18f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SNew(SDialogueGraphInitStatus, skipTextNode)
						]
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(2.0f)
					[
						inputWidget
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.Padding(18.0f, 8.0f)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("ResponsesOnly", "RESPONSES ONLY"))
						.Font(FCoreStyle::GetDefaultFontStyle("Regular", 9))
						.ColorAndOpacity(FLinearColor(0.72f, 0.58f, 0.28f))
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(2.0f)
					[
						outputWidget
					]
				]
			]
		]
	];
}

UDialogueGraphSkipTextNode* SDialogueGraphSkipTextNode::GetSkipTextNode() const
{
	return Cast<UDialogueGraphSkipTextNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphSkipTextNode::CreateSkipTextPin(UEdGraphPin* pin)
{
	TSharedPtr<SGraphPin> pinWidget = CreatePinWidget(pin);
	check(pinWidget.IsValid());
	pinWidget->SetOwner(SharedThis(this));
	pinWidget->SetShowLabel(false);
	if (pin->Direction == EGPD_Input)
	{
		InputPins.Add(pinWidget.ToSharedRef());
	}
	else
	{
		OutputPins.Add(pinWidget.ToSharedRef());
	}
	return pinWidget.ToSharedRef();
}

FSlateColor SDialogueGraphSkipTextNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(1.0f, 0.68f, 0.1f)
		: FLinearColor(0.72f, 0.43f, 0.035f);
}

#undef LOCTEXT_NAMESPACE
