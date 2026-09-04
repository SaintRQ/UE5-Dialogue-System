// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphRandomNode.h"

#include "DialogueGraphRandomNode.h"
#include "SDialogueAddButton.h"
#include "SDialogueGraphInitStatus.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphRandomNode"

void SDialogueGraphRandomNode::Construct(
	const FArguments& Arguments,
	UDialogueGraphRandomNode* RandomNode)
{
	GraphNode = RandomNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(RandomNode ? RandomNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphRandomNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphRandomNode* randomNode = GetRandomNode();
	const FDialogueRandom* randomData = randomNode ? randomNode->GetRandomData() : nullptr;
	const int32 outputCount = randomData ? randomData->Outputs.Num() : 0;
	TSharedRef<SGridPanel> content = SNew(SGridPanel)
		.FillColumn(0, 1.0f);

	for (int32 outputIndex = 0; outputIndex < outputCount; ++outputIndex)
	{
		content->AddSlot(0, outputIndex, SGridPanel::Layer(1))
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(12.0f, 5.0f, 4.0f, 5.0f)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::Format(LOCTEXT("OutputLabel", "OUTPUT {0}"), outputIndex + 1))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
				.ColorAndOpacity(FLinearColor(0.42f, 0.82f, 0.7f))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(8.0f, 0.0f, 0.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.IsEnabled(outputCount > 2)
				.ContentPadding(2.0f)
				.ToolTipText(LOCTEXT("RemoveOutputTooltip", "Remove this random output."))
				.OnClicked(this, &SDialogueGraphRandomNode::OnRemoveOutput, outputIndex)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Remove", "-"))
				]
			]
		];

		if (UEdGraphPin* outputPin = randomNode->GetRandomOutputPin(outputIndex))
		{
			content->AddSlot(1, outputIndex, SGridPanel::Layer(1))
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				CreateRandomPin(outputPin)
			];
		}
	}

	content->AddSlot(0, outputCount, SGridPanel::Layer(1))
	.HAlign(HAlign_Center)
	.Padding(10.0f, 6.0f, 8.0f, 10.0f)
	[
		SNew(SDialogueAddButton)
		.Color(FLinearColor(0.08f, 0.62f, 0.45f, 0.55f))
		.OnClicked(this, &SDialogueGraphRandomNode::OnAddOutput)
	];

	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	if (randomNode && randomNode->GetInputPin())
	{
		inputWidget = CreateRandomPin(randomNode->GetInputPin());
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphRandomNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
			.BorderBackgroundColor(FLinearColor(0.01f, 0.055f, 0.042f))
			.Padding(0.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.025f, 0.3f, 0.21f))
					.Padding(10.0f, 7.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NodeTitle", "RANDOM"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
							.ColorAndOpacity(FLinearColor(0.35f, 0.96f, 0.72f))
							.ShadowOffset(FVector2D(1.0f, 1.0f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SNew(SDialogueGraphInitStatus, randomNode)
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
					[
						SNew(SBox)
						.MinDesiredWidth(220.0f)
						[
							content
						]
					]
				]
			]
		]
	];
}

UDialogueGraphRandomNode* SDialogueGraphRandomNode::GetRandomNode() const
{
	return Cast<UDialogueGraphRandomNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphRandomNode::CreateRandomPin(UEdGraphPin* Pin)
{
	TSharedPtr<SGraphPin> pinWidget = CreatePinWidget(Pin);
	check(pinWidget.IsValid());
	pinWidget->SetOwner(SharedThis(this));
	pinWidget->SetShowLabel(false);
	if (Pin->Direction == EGPD_Input)
	{
		InputPins.Add(pinWidget.ToSharedRef());
	}
	else
	{
		OutputPins.Add(pinWidget.ToSharedRef());
	}
	return pinWidget.ToSharedRef();
}

FSlateColor SDialogueGraphRandomNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(0.22f, 1.0f, 0.7f)
		: FLinearColor(0.04f, 0.62f, 0.43f);
}

FReply SDialogueGraphRandomNode::OnAddOutput()
{
	if (UDialogueGraphRandomNode* randomNode = GetRandomNode())
	{
		randomNode->AddOutput();
		UpdateGraphNode();
	}
	return FReply::Handled();
}

FReply SDialogueGraphRandomNode::OnRemoveOutput(const int32 OutputIndex)
{
	if (UDialogueGraphRandomNode* randomNode = GetRandomNode())
	{
		randomNode->RemoveOutput(OutputIndex);
		UpdateGraphNode();
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
