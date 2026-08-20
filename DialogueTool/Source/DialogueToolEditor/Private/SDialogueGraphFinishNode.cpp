// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphFinishNode.h"

#include "DialogueGraphFinishNode.h"
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

#define LOCTEXT_NAMESPACE "SDialogueGraphFinishNode"

void SDialogueGraphFinishNode::Construct(
	const FArguments& arguments,
	UDialogueGraphFinishNode* finishNode)
{
	GraphNode = finishNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(finishNode ? finishNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphFinishNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	UDialogueGraphFinishNode* finishNode = GetFinishNode();
	if (finishNode)
	{
		if (UEdGraphPin* inputPin = finishNode->GetInputPin())
		{
			inputWidget = CreateFinishPin(inputPin);
		}
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphFinishNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
			.BorderBackgroundColor(FLinearColor(0.08f, 0.008f, 0.004f))
			.Padding(0.0f)
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
				.AutoWidth()
				[
					SNew(SBox)
					.MinDesiredWidth(240.0f)
					.MinDesiredHeight(80.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(finishNode && finishNode->IsReturnNode()
								? LOCTEXT("ReturnNodeTitle", "RETURN")
								: LOCTEXT("NodeTitle", "FINISH DIALOGUE"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 13))
							.ColorAndOpacity(FLinearColor(1.0f, 0.32f, 0.16f))
							.ShadowOffset(FVector2D(1.0f, 1.0f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Top)
						.Padding(0.0f, 6.0f, 6.0f, 0.0f)
						[
							SNew(SDialogueGraphInitStatus, finishNode)
						]
					]
				]
			]
		]
	];
}

UDialogueGraphFinishNode* SDialogueGraphFinishNode::GetFinishNode() const
{
	return Cast<UDialogueGraphFinishNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphFinishNode::CreateFinishPin(UEdGraphPin* pin)
{
	TSharedPtr<SGraphPin> pinWidget = CreatePinWidget(pin);
	check(pinWidget.IsValid());
	pinWidget->SetOwner(SharedThis(this));
	pinWidget->SetShowLabel(false);
	InputPins.Add(pinWidget.ToSharedRef());
	return pinWidget.ToSharedRef();
}

FSlateColor SDialogueGraphFinishNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(1.0f, 0.22f, 0.08f)
		: FLinearColor(0.78f, 0.08f, 0.025f);
}

#undef LOCTEXT_NAMESPACE
