// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphTransitNode.h"

#include "AssetRegistry/AssetData.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueLibraryObject.h"
#include "PropertyCustomizationHelpers.h"
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

#define LOCTEXT_NAMESPACE "SDialogueGraphTransitNode"

void SDialogueGraphTransitNode::Construct(
	const FArguments& arguments,
	UDialogueGraphTransitNode* transitNode)
{
	GraphNode = transitNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(transitNode ? transitNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphTransitNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphTransitNode* transitNode = GetTransitNode();
	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	TSharedRef<SWidget> outputWidget = SNullWidget::NullWidget;
	if (transitNode)
	{
		if (UEdGraphPin* inputPin = transitNode->GetInputPin())
		{
			inputWidget = CreateTransitPin(inputPin);
		}
		if (UEdGraphPin* outputPin = transitNode->GetOutputPin())
		{
			outputWidget = CreateTransitPin(outputPin);
		}
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphTransitNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
			.BorderBackgroundColor(FLinearColor(0.055f, 0.018f, 0.09f))
			.Padding(0.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.24f, 0.055f, 0.42f))
					.Padding(8.0f, 6.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NodeTitle", "TRANSIT"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
							.ColorAndOpacity(FLinearColor(0.8f, 0.52f, 1.0f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SNew(SDialogueGraphInitStatus, transitNode)
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
					.Padding(10.0f, 8.0f, 10.0f, 10.0f)
					[
						SNew(SBox)
						.WidthOverride(280.0f)
						[
							SNew(SObjectPropertyEntryBox)
							.AllowedClass(UDialogueLibraryObject::StaticClass())
							.ObjectPath(this, &SDialogueGraphTransitNode::GetDialogueLibraryPath)
							.OnObjectChanged(this, &SDialogueGraphTransitNode::OnDialogueLibraryChanged)
							.AllowClear(true)
							.DisplayBrowse(true)
							.DisplayUseSelected(true)
						]
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

UDialogueGraphTransitNode* SDialogueGraphTransitNode::GetTransitNode() const
{
	return Cast<UDialogueGraphTransitNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphTransitNode::CreateTransitPin(UEdGraphPin* pin)
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

FString SDialogueGraphTransitNode::GetDialogueLibraryPath() const
{
	const UDialogueGraphTransitNode* transitNode = GetTransitNode();
	const FDialogueTransit* transitData = transitNode ? transitNode->GetTransitData() : nullptr;
	return transitData && transitData->DialogueLibrary
		? transitData->DialogueLibrary->GetPathName()
		: FString();
}

void SDialogueGraphTransitNode::OnDialogueLibraryChanged(const FAssetData& assetData)
{
	if (UDialogueGraphTransitNode* transitNode = GetTransitNode())
	{
		transitNode->SetDialogueLibrary(Cast<UDialogueLibraryObject>(assetData.GetAsset()));
	}
}

FSlateColor SDialogueGraphTransitNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(0.72f, 0.24f, 1.0f)
		: FLinearColor(0.42f, 0.08f, 0.72f);
}

#undef LOCTEXT_NAMESPACE
