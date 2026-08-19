// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphInitStatus.h"

#include "DialogueGraphUtilities.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphInitStatus"

void SDialogueGraphInitStatus::Construct(const FArguments& arguments, UEdGraphNode* graphNode)
{
	GraphNode = graphNode;

	ChildSlot
	[
		SNew(SHorizontalBox)

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(16.0f)
			.HeightOverride(16.0f)
			.ToolTipText(this, &SDialogueGraphInitStatus::GetStatusTooltip)
			[
				SNew(SImage)
				.Image(FAppStyle::GetBrush("Sequencer.KeyCircle"))
				.ColorAndOpacity(this, &SDialogueGraphInitStatus::GetStatusColor)
			]
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(4.0f, 0.0f, 0.0f, 0.0f)
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "SimpleButton")
			.ContentPadding(0.0f)
			.ToolTipText(LOCTEXT("DeleteNodeTooltip", "Delete this node."))
			.OnClicked(this, &SDialogueGraphInitStatus::OnDeleteNode)
			[
				SNew(SBox)
				.WidthOverride(16.0f)
				.HeightOverride(16.0f)
				[
					SNew(SOverlay)

					+ SOverlay::Slot()
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("Sequencer.KeyCircle"))
						.ColorAndOpacity(FLinearColor(0.02f, 0.3f, 0.95f))
					]

					+ SOverlay::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("DeleteNodeIcon", "X"))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
						.ColorAndOpacity(FLinearColor::White)
					]
				]
			]
		]
	];
}

FSlateColor SDialogueGraphInitStatus::GetStatusColor() const
{
	return DialogueGraphUtilities::IsConnectedToInit(GraphNode.Get())
		? FLinearColor(0.08f, 1.0f, 0.2f)
		: FLinearColor(1.0f, 0.04f, 0.025f);
}

FText SDialogueGraphInitStatus::GetStatusTooltip() const
{
	return DialogueGraphUtilities::IsConnectedToInit(GraphNode.Get())
		? LOCTEXT("Connected", "Connected to the Dialogue Start node.")
		: LOCTEXT("Disconnected", "Not connected to the Dialogue Start node.");
}

FReply SDialogueGraphInitStatus::OnDeleteNode()
{
	UEdGraphNode* graphNode = GraphNode.Get();
	if (!graphNode || !graphNode->CanUserDeleteNode())
	{
		return FReply::Handled();
	}

	const FScopedTransaction transaction(LOCTEXT("DeleteNode", "Delete Dialogue Node"));
	if (UEdGraph* graph = graphNode->GetGraph())
	{
		graph->Modify();
	}
	graphNode->Modify();
	graphNode->DestroyNode();
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
