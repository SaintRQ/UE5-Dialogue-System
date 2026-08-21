// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphActionNode.h"

#include "DialogueAction.h"
#include "DialogueGraphActionNode.h"
#include "SDialogueAddButton.h"
#include "SDialogueGraphInitStatus.h"
#include "SDialogueObjectEntry.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphActionNode"

void SDialogueGraphActionNode::Construct(
	const FArguments& arguments,
	UDialogueGraphActionNode* actionNode)
{
	GraphNode = actionNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(actionNode ? actionNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphActionNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphActionNode* actionNode = GetActionNode();
	TSharedRef<SVerticalBox> actionContent = SNew(SVerticalBox);
	
	if (actionNode)
	{
		const TArray<TObjectPtr<UDialogueAction>>& actions = actionNode->GetActions();
		for (int32 actionIndex = 0; actionIndex < actions.Num(); ++actionIndex)
		{
			actionContent->AddSlot()
			.AutoHeight()
			.Padding(4.0f, 2.0f)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0.0f, 0.0f, 6.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text(FText::AsNumber(actionIndex + 1))
				]

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SDialogueObjectEntry)
					.BaseClass(UDialogueAction::StaticClass())
					.Object_Lambda([this, actionIndex]() -> UObject*
					{
						return GetAction(actionIndex);
					})
					.OnSetClass(FOnSetDialogueObjectClass::CreateSP(
						this,
						&SDialogueGraphActionNode::OnActionClassSet,
						actionIndex))
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4.0f, 0.0f, 0.0f, 0.0f)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "SimpleButton")
					.IsEnabled(actions.Num() > 1)
					.ToolTipText(LOCTEXT("RemoveActionTooltip", "Remove this action class."))
					.OnClicked(this, &SDialogueGraphActionNode::OnRemoveAction, actionIndex)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("Remove", "-"))
					]
				]
			];
		}
	}

	actionContent->AddSlot()
	.AutoHeight()
	.HAlign(HAlign_Center)
	.Padding(4.0f)
	[
		SNew(SDialogueAddButton)
		.Color(FLinearColor(0.82f, 0.16f, 0.055f, 0.5))
		.OnClicked(this, &SDialogueGraphActionNode::OnAddAction)
	];

	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	TSharedRef<SWidget> outputWidget = SNullWidget::NullWidget;
	if (actionNode)
	{
		if (UEdGraphPin* inputPin = actionNode->GetInputPin())
		{
			inputWidget = CreateActionPin(inputPin);
		}
		if (UEdGraphPin* outputPin = actionNode->GetOutputPin())
		{
			outputWidget = CreateActionPin(outputPin);
		}
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphActionNode::GetBorderColor)
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
					.BorderBackgroundColor(FLinearColor(0.9f, 0.3f, 0.012f, 0.5))
					.Padding(8.0f, 6.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NodeTitle", "ACTIONS"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
							.ColorAndOpacity(FLinearColor(0.8f, 0.3f, 0.1f))
							.Justification(ETextJustify::Center)
							.ShadowOffset(FVector2D(1.0f, 1.0f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SNew(SDialogueGraphInitStatus, actionNode)
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
					.Padding(2.0f)
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
						.BorderBackgroundColor(FLinearColor(0.85f, 0.3f, 0.06f, 0))
						.Padding(2.0f)
						[
							SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
						.BorderBackgroundColor(FLinearColor(0.008f, 0.012f, 0.018f, 0))
						.Padding(6.0f)
						[
							SNew(SBox)
							.MinDesiredWidth(360.0f)
							[
								actionContent
							]
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
		]
	];
}

UDialogueGraphActionNode* SDialogueGraphActionNode::GetActionNode() const
{
	return Cast<UDialogueGraphActionNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphActionNode::CreateActionPin(UEdGraphPin* pin)
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

FSlateColor SDialogueGraphActionNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(1.0f, 0.12f, 0.06f)
		: FLinearColor(0.74f, 0.025f, 0.015f);
}

UDialogueAction* SDialogueGraphActionNode::GetAction(int32 actionIndex) const
{
	const UDialogueGraphActionNode* actionNode = GetActionNode();
	if (!actionNode)
	{
		return nullptr;
	}

	const TArray<TObjectPtr<UDialogueAction>>& actions = actionNode->GetActions();
	return actions.IsValidIndex(actionIndex) ? actions[actionIndex].Get() : nullptr;
}

void SDialogueGraphActionNode::OnActionClassSet(const UClass* actionClass, int32 actionIndex)
{
	if (UDialogueGraphActionNode* actionNode = GetActionNode())
	{
		actionNode->SetActionClass(actionIndex, actionClass);
	}
}

FReply SDialogueGraphActionNode::OnAddAction()
{
	if (UDialogueGraphActionNode* actionNode = GetActionNode())
	{
		actionNode->AddAction();
		UpdateGraphNode();
	}

	return FReply::Handled();
}

FReply SDialogueGraphActionNode::OnRemoveAction(int32 actionIndex)
{
	if (UDialogueGraphActionNode* actionNode = GetActionNode())
	{
		actionNode->RemoveAction(actionIndex);
		UpdateGraphNode();
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
