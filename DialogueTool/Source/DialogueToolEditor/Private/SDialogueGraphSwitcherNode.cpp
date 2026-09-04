// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphSwitcherNode.h"

#include "DialogueCondition.h"
#include "DialogueGraphSwitcherNode.h"
#include "Framework/Application/SlateApplication.h"
#include "SDialogueAddButton.h"
#include "SDialogueConditionPopup.h"
#include "SDialogueGraphInitStatus.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphSwitcherNode"

void SDialogueGraphSwitcherNode::Construct(
	const FArguments& arguments,
	UDialogueGraphSwitcherNode* switcherNode)
{
	GraphNode = switcherNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(switcherNode ? switcherNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphSwitcherNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphSwitcherNode* switcherNode = GetSwitcherNode();
	const FDialogueSwitcher* switcherData = switcherNode ? switcherNode->GetSwitcherData() : nullptr;
	const int32 entryCount = switcherData ? switcherData->Conditions.Num() : 0;
	const int32 conditionCount = FMath::Max(0, entryCount - 1);
	TSharedRef<SGridPanel> content = SNew(SGridPanel)
		.FillColumn(0, 1.0f);

	if (switcherData)
	{
		for (int32 conditionIndex = 0; conditionIndex < conditionCount; ++conditionIndex)
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
			[
				SNew(SBox)
				.WidthOverride(280.0f)
				[
					SNew(SEditableTextBox)
					.Text(FText::FromName(switcherData->Conditions[conditionIndex].Name))
					.HintText(LOCTEXT("ConditionNameHint", "Condition name"))
					.OnTextCommitted(this, &SDialogueGraphSwitcherNode::OnConditionNameCommitted, conditionIndex)
				]
			];

			conditionRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f, 0.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.ContentPadding(2.0f)
				.ToolTipText(LOCTEXT("ConditionsTooltip", "Edit conditions for this switch entry."))
				.OnClicked(this, &SDialogueGraphSwitcherNode::OnOpenConditions, conditionIndex)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.Help"))
					.ColorAndOpacity(this, &SDialogueGraphSwitcherNode::GetConditionIconColor, conditionIndex)
				]
			];

			conditionRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.IsEnabled(conditionCount > 2)
				.ToolTipText(LOCTEXT("RemoveConditionTooltip", "Remove this switch condition."))
				.OnClicked(this, &SDialogueGraphSwitcherNode::OnRemoveCondition, conditionIndex)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Remove", "-"))
				]
			];

			const int32 conditionRowIndex = conditionIndex + 1;
			content->AddSlot(0, conditionRowIndex, SGridPanel::Layer(1))
			.Padding(10.0f, 4.0f, 8.0f, 4.0f)
			[
				conditionRow
			];

			if (UEdGraphPin* outputPin = switcherNode->GetConditionOutputPin(conditionIndex))
			{
				content->AddSlot(1, conditionRowIndex, SGridPanel::Layer(1))
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				[
					CreateSwitcherPin(outputPin)
				];
			}
		}
	}

	// Button
	content->AddSlot(0, conditionCount + 1, SGridPanel::Layer(1))
	.HAlign(HAlign_Center)
	.Padding(10.0f, 6.0f, 8.0f, 10.0f)
	[
		SNew(SDialogueAddButton)
		.Color(FLinearColor(0.56f, 0.12f, 0.92f, 0.5f))
		.OnClicked(this, &SDialogueGraphSwitcherNode::OnAddCondition)
	];

	const int32 defaultRow = conditionCount + 2;
	content->AddSlot(0, defaultRow, SGridPanel::Layer(1))
	.HAlign(HAlign_Right)
	.VAlign(VAlign_Center)
	.Padding(10.0f, 6.0f, 8.0f, 8.0f)
	[
		SNew(STextBlock)
		.Text(LOCTEXT("DefaultCondition", "DEFAULT"))
		.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		.ColorAndOpacity(FLinearColor(0.7f, 0.56f, 0.82f))
	];

	if (switcherNode && switcherNode->GetDefaultOutputPin())
	{
		content->AddSlot(1, defaultRow, SGridPanel::Layer(1))
		.VAlign(VAlign_Center)
		.Padding(2.0f)
		[
			CreateSwitcherPin(switcherNode->GetDefaultOutputPin())
		];
	}

	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	if (switcherNode && switcherNode->GetInputPin())
	{
		inputWidget = CreateSwitcherPin(switcherNode->GetInputPin());
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphSwitcherNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
			.BorderBackgroundColor(FLinearColor(0.035f, 0.012f, 0.06f))
			.Padding(0.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.18f, 0.025f, 0.32f))
					.Padding(10.0f, 7.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NodeTitle", "SWITCH"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
							.ColorAndOpacity(FLinearColor(0.8f, 0.52f, 1.0f))
							.Justification(ETextJustify::Center)
							.ShadowOffset(FVector2D(1.0f, 1.0f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SNew(SDialogueGraphInitStatus, switcherNode)
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
						.MinDesiredWidth(520.0f)
						[
							content
						]
					]
				]
			]
		]
	];
}

UDialogueGraphSwitcherNode* SDialogueGraphSwitcherNode::GetSwitcherNode() const
{
	return Cast<UDialogueGraphSwitcherNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphSwitcherNode::CreateSwitcherPin(UEdGraphPin* pin)
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

FSlateColor SDialogueGraphSwitcherNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(0.76f, 0.28f, 1.0f)
		: FLinearColor(0.48f, 0.08f, 0.82f);
}

FSlateColor SDialogueGraphSwitcherNode::GetConditionIconColor(int32 conditionIndex) const
{
	const UDialogueGraphSwitcherNode* switcherNode = GetSwitcherNode();
	const FDialogueSwitcher* switcherData = switcherNode ? switcherNode->GetSwitcherData() : nullptr;
	const bool bHasConditions = switcherData && switcherData->Conditions.IsValidIndex(conditionIndex)
		&& switcherData->Conditions[conditionIndex].Conditions.ContainsByPredicate(
			[](const TObjectPtr<UDialogueCondition>& condition)
			{
				return condition != nullptr;
			});
	return bHasConditions
		? FLinearColor(0.22f, 0.72f, 1.0f)
		: FLinearColor(0.5f, 0.53f, 0.58f, 0.4f);
}

FReply SDialogueGraphSwitcherNode::OnOpenConditions(int32 conditionIndex)
{
	UDialogueGraphSwitcherNode* switcherNode = GetSwitcherNode();
	const FDialogueSwitcher* switcherData = switcherNode ? switcherNode->GetSwitcherData() : nullptr;
	if (!switcherData || !switcherData->Conditions.IsValidIndex(conditionIndex))
	{
		return FReply::Handled();
	}

	const TWeakObjectPtr<UDialogueGraphSwitcherNode> weakNode = switcherNode;
	FSlateApplication::Get().PushMenu(
		AsShared(),
		FWidgetPath(),
		SNew(SDialogueConditionPopup)
		.ConditionCount_Lambda([weakNode, conditionIndex]()
		{
			const UDialogueGraphSwitcherNode* node = weakNode.Get();
			const FDialogueSwitcher* data = node ? node->GetSwitcherData() : nullptr;
			return data && data->Conditions.IsValidIndex(conditionIndex)
				? data->Conditions[conditionIndex].Conditions.Num()
				: 0;
		})
		.ConditionMode_Lambda([weakNode, conditionIndex]()
		{
			const UDialogueGraphSwitcherNode* node = weakNode.Get();
			const FDialogueSwitcher* data = node ? node->GetSwitcherData() : nullptr;
			return data && data->Conditions.IsValidIndex(conditionIndex)
				? data->Conditions[conditionIndex].ConditionMode
				: EDialogueConditionMode::All;
		})
		.OnGetCondition_Lambda([weakNode, conditionIndex](int32 requirementIndex) -> UDialogueCondition*
		{
			const UDialogueGraphSwitcherNode* node = weakNode.Get();
			const FDialogueSwitcher* data = node ? node->GetSwitcherData() : nullptr;
			if (!data || !data->Conditions.IsValidIndex(conditionIndex)
				|| !data->Conditions[conditionIndex].Conditions.IsValidIndex(requirementIndex))
			{
				return nullptr;
			}

			return data->Conditions[conditionIndex].Conditions[requirementIndex].Get();
		})
		.OnSetConditionClass_Lambda(
			[weakNode, conditionIndex](const UClass* conditionClass, int32 requirementIndex)
			{
				if (UDialogueGraphSwitcherNode* node = weakNode.Get())
				{
					node->SetConditionRequirementClass(conditionIndex, requirementIndex, conditionClass);
				}
			})
		.OnAddCondition_Lambda([weakNode, conditionIndex]()
		{
			if (UDialogueGraphSwitcherNode* node = weakNode.Get())
			{
				node->AddConditionRequirement(conditionIndex);
			}
		})
		.OnRemoveCondition_Lambda([weakNode, conditionIndex](int32 requirementIndex)
		{
			if (UDialogueGraphSwitcherNode* node = weakNode.Get())
			{
				node->RemoveConditionRequirement(conditionIndex, requirementIndex);
			}
		})
		.OnSetConditionMode_Lambda([weakNode, conditionIndex](EDialogueConditionMode conditionMode)
		{
			if (UDialogueGraphSwitcherNode* node = weakNode.Get())
			{
				node->SetConditionMode(conditionIndex, conditionMode);
			}
		}),
		FSlateApplication::Get().GetCursorPos(),
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

	return FReply::Handled();
}

FReply SDialogueGraphSwitcherNode::OnAddCondition()
{
	if (UDialogueGraphSwitcherNode* switcherNode = GetSwitcherNode())
	{
		switcherNode->AddCondition();
		UpdateGraphNode();
	}
	return FReply::Handled();
}

FReply SDialogueGraphSwitcherNode::OnRemoveCondition(int32 conditionIndex)
{
	if (UDialogueGraphSwitcherNode* switcherNode = GetSwitcherNode())
	{
		switcherNode->RemoveCondition(conditionIndex);
		UpdateGraphNode();
	}
	return FReply::Handled();
}

void SDialogueGraphSwitcherNode::OnConditionNameCommitted(
	const FText& text,
	ETextCommit::Type commitType,
	int32 conditionIndex)
{
	if (UDialogueGraphSwitcherNode* switcherNode = GetSwitcherNode())
	{
		switcherNode->SetConditionName(conditionIndex, FName(*text.ToString()));
	}
}

#undef LOCTEXT_NAMESPACE
