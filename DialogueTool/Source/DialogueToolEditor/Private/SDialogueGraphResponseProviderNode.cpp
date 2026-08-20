// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphResponseProviderNode.h"

#include "DialogueProvider.h"
#include "DialogueGraphResponseProviderNode.h"
#include "SDialogueGraphInitStatus.h"
#include "SDialogueObjectEntry.h"
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

#define LOCTEXT_NAMESPACE "SDialogueGraphResponseProviderNode"

void SDialogueGraphResponseProviderNode::Construct(
	const FArguments& arguments,
	UDialogueGraphResponseProviderNode* responseProviderNode)
{
	GraphNode = responseProviderNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(responseProviderNode ? responseProviderNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphResponseProviderNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphResponseProviderNode* responseProviderNode = GetResponseProviderNode();
	TSharedRef<SWidget> outputWidget = responseProviderNode && responseProviderNode->GetOutputPin()
		? CreateProviderPin(responseProviderNode->GetOutputPin())
		: SNullWidget::NullWidget;

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphResponseProviderNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
						.BorderBackgroundColor(FLinearColor(0.008f, 0.025f, 0.055f))
			.Padding(0.0f)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
						.BorderBackgroundColor(FLinearColor(0.025f, 0.2f, 0.38f))
						.Padding(8.0f, 6.0f)
						[
							SNew(SOverlay)

							+ SOverlay::Slot()
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("NodeTitle", "PROVIDER"))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
								.ColorAndOpacity(FLinearColor(0.4f, 0.82f, 1.0f))
								.Justification(ETextJustify::Center)
							]

							+ SOverlay::Slot()
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Center)
							[
								SNew(SDialogueGraphInitStatus, responseProviderNode)
								.ShowStatus(false)
							]
						]
					]

					+ SVerticalBox::Slot()
					.AutoHeight()
					.Padding(10.0f, 8.0f, 10.0f, 10.0f)
					[
						SNew(SBox)
						.MinDesiredWidth(280.0f)
						[
							SNew(SDialogueObjectEntry)
							.BaseClass(UDialogueProvider::StaticClass())
							.Object_Lambda([this]() -> UObject*
							{
								return GetDialogueProvider();
							})
							.OnSetClass(FOnSetDialogueObjectClass::CreateSP(
								this,
								&SDialogueGraphResponseProviderNode::OnResponseProviderClassChanged))
						]
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
	];
}

UDialogueGraphResponseProviderNode* SDialogueGraphResponseProviderNode::GetResponseProviderNode() const
{
	return Cast<UDialogueGraphResponseProviderNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphResponseProviderNode::CreateProviderPin(UEdGraphPin* pin)
{
	TSharedPtr<SGraphPin> pinWidget = CreatePinWidget(pin);
	check(pinWidget.IsValid());
	pinWidget->SetOwner(SharedThis(this));
	pinWidget->SetShowLabel(false);
	OutputPins.Add(pinWidget.ToSharedRef());
	return pinWidget.ToSharedRef();
}

UDialogueProvider* SDialogueGraphResponseProviderNode::GetDialogueProvider() const
{
	const UDialogueGraphResponseProviderNode* responseProviderNode = GetResponseProviderNode();
	return responseProviderNode ? responseProviderNode->GetDialogueProvider() : nullptr;
}

void SDialogueGraphResponseProviderNode::OnResponseProviderClassChanged(
	const UClass* responseProviderClass)
{
	if (UDialogueGraphResponseProviderNode* responseProviderNode = GetResponseProviderNode())
	{
		responseProviderNode->SetResponseProviderClass(responseProviderClass);
	}
}

FSlateColor SDialogueGraphResponseProviderNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(0.18f, 0.72f, 1.0f)
		: FLinearColor(0.04f, 0.48f, 0.78f);
}

#undef LOCTEXT_NAMESPACE
