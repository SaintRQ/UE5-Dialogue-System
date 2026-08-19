// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphInitNode.h"

#include "DialogueGraphInitNode.h"
#include "DialogueLibraryObject.h"
#include "EdGraph/EdGraph.h"
#include "Framework/Application/SlateApplication.h"
#include "SDialogueAddButton.h"
#include "SDialogueConditionPopup.h"
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
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphInitNode"

void SDialogueGraphInitNode::Construct(
	const FArguments& arguments,
	UDialogueGraphInitNode* initNode)
{
	GraphNode = initNode;
	SetCursor(EMouseCursor::CardinalCross);
	UpdateGraphNode();
}

void SDialogueGraphInitNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphInitNode* initNode = GetInitNode();
	const bool bLibrary = initNode && initNode->GetGraph()
		&& initNode->GetGraph()->GetTypedOuter<UDialogueLibraryObject>();
	const TArray<FDialogueInit>* initData = initNode ? initNode->GetInitData() : nullptr;
	const int32 initCount = initData ? initData->Num() : 0;
	const int32 addInitRow = initCount + 1;
	TSharedRef<SGridPanel> content = SNew(SGridPanel)
		.FillColumn(0, 1.0f);

	content->AddSlot(0, 0)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
		.BorderBackgroundColor(FLinearColor(0.015f, 0.075f, 0.24f))
		.Padding(12.0f, 8.0f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("InTitle", "IN"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 24))
				.ColorAndOpacity(FLinearColor(0.18f, 0.72f, 1.0f))
				.ShadowOffset(FVector2D(1.0f, 1.0f))
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Text(bLibrary
					? LOCTEXT("LibraryNodeTitle", "LIBRARY START")
					: LOCTEXT("NodeTitle", "DIALOGUE START"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
				.ColorAndOpacity(FLinearColor(0.65f, 0.82f, 1.0f))
			]
		]
	];

	content->AddSlot(0, 1, SGridPanel::Layer(0))
	.RowSpan(initCount + 1)
	.Padding(2.0f)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(FLinearColor(0.08f, 0.4f, 0.95f))
		.Padding(2.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
			.BorderBackgroundColor(FLinearColor(0.008f, 0.012f, 0.018f))
		]
	];

	if (initData)
	{
		for (int32 initIndex = 0; initIndex < initCount; ++initIndex)
		{
			TSharedRef<SHorizontalBox> initRow = SNew(SHorizontalBox);
			initRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(FText::AsNumber(initIndex + 1))
			];

			initRow->AddSlot()
			.FillWidth(1.0f)
			[
				SNew(SBox)
				.WidthOverride(280.0f)
				[
					SNew(SEditableTextBox)
					.Text(FText::FromName((*initData)[initIndex].Name))
					.HintText(bLibrary
						? LOCTEXT("LibraryInitNameHint", "Library entry name")
						: LOCTEXT("InitNameHint", "Initialization name"))
					.OnTextCommitted(this, &SDialogueGraphInitNode::OnInitNameCommitted, initIndex)
				]
			];

			initRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f, 0.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.ContentPadding(2.0f)
				.ToolTipText(LOCTEXT("InitConditionsTooltip", "Edit conditions for this initialization entry."))
				.OnClicked(this, &SDialogueGraphInitNode::OnOpenInitConditions, initIndex)
				[
					SNew(SImage)
					.Image(FAppStyle::GetBrush("Icons.Help"))
					.ColorAndOpacity(this, &SDialogueGraphInitNode::GetInitConditionIconColor, initIndex)
				]
			];

			initRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.IsEnabled(initCount > 1)
				.ToolTipText(LOCTEXT("RemoveInitTooltip", "Remove this initialization entry."))
				.OnClicked(this, &SDialogueGraphInitNode::OnRemoveInit, initIndex)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Remove", "-"))
				]
			];

			const int32 initRowIndex = initIndex + 1;
			content->AddSlot(0, initRowIndex, SGridPanel::Layer(1))
			.Padding(10.0f, 4.0f, 8.0f, 4.0f)
			[
				initRow
			];

			if (UEdGraphPin* outputPin = initNode->GetInitOutputPin(initIndex))
			{
				content->AddSlot(1, initRowIndex, SGridPanel::Layer(1))
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				[
					CreateInitPin(outputPin)
				];
			}
		}
	}

	content->AddSlot(0, addInitRow, SGridPanel::Layer(1))
	.HAlign(HAlign_Center)
	.Padding(10.0f, 6.0f, 8.0f, 10.0f)
	[
		SNew(SDialogueAddButton)
		.Color(FLinearColor(0.04f, 0.48f, 1.0f))
		.OnClicked(this, &SDialogueGraphInitNode::OnAddInit)
	];

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
		.BorderBackgroundColor(this, &SDialogueGraphInitNode::GetBorderColor)
		.Padding(3.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
			.BorderBackgroundColor(FLinearColor(0.015f, 0.035f, 0.09f))
			.Padding(0.0f)
			[
				content
			]
		]
	];
}

UDialogueGraphInitNode* SDialogueGraphInitNode::GetInitNode() const
{
	return Cast<UDialogueGraphInitNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphInitNode::CreateInitPin(UEdGraphPin* pin)
{
	TSharedPtr<SGraphPin> pinWidget = CreatePinWidget(pin);
	check(pinWidget.IsValid());
	pinWidget->SetOwner(SharedThis(this));
	pinWidget->SetShowLabel(false);
	OutputPins.Add(pinWidget.ToSharedRef());
	return pinWidget.ToSharedRef();
}

FSlateColor SDialogueGraphInitNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(0.12f, 0.7f, 1.0f)
		: FLinearColor(0.025f, 0.4f, 1.0f);
}

FSlateColor SDialogueGraphInitNode::GetInitConditionIconColor(int32 initIndex) const
{
	const UDialogueGraphInitNode* initNode = GetInitNode();
	const TArray<FDialogueInit>* initData = initNode ? initNode->GetInitData() : nullptr;
	const bool bHasConditions = initData && initData->IsValidIndex(initIndex)
		&& (*initData)[initIndex].Conditions.ContainsByPredicate(
			[](const TObjectPtr<UDialogueCondition>& condition)
			{
				return condition != nullptr;
			});
	return bHasConditions
		? FLinearColor(0.22f, 0.72f, 1.0f)
		: FLinearColor(0.5f, 0.53f, 0.58f, 0.4f);
}

FReply SDialogueGraphInitNode::OnAddInit()
{
	if (UDialogueGraphInitNode* initNode = GetInitNode())
	{
		initNode->AddInit();
		UpdateGraphNode();
	}

	return FReply::Handled();
}

FReply SDialogueGraphInitNode::OnRemoveInit(int32 initIndex)
{
	if (UDialogueGraphInitNode* initNode = GetInitNode())
	{
		initNode->RemoveInit(initIndex);
		UpdateGraphNode();
	}

	return FReply::Handled();
}

void SDialogueGraphInitNode::OnInitNameCommitted(
	const FText& text,
	ETextCommit::Type commitType,
	int32 initIndex)
{
	if (UDialogueGraphInitNode* initNode = GetInitNode())
	{
		initNode->SetInitName(initIndex, FName(*text.ToString()));
	}
}

FReply SDialogueGraphInitNode::OnOpenInitConditions(int32 initIndex)
{
	UDialogueGraphInitNode* initNode = GetInitNode();
	const TArray<FDialogueInit>* initData = initNode ? initNode->GetInitData() : nullptr;
	if (!initData || !initData->IsValidIndex(initIndex))
	{
		return FReply::Handled();
	}

	const TWeakObjectPtr<UDialogueGraphInitNode> weakNode = initNode;
	FSlateApplication::Get().PushMenu(
		AsShared(),
		FWidgetPath(),
		SNew(SDialogueConditionPopup)
		.ConditionCount_Lambda([weakNode, initIndex]()
		{
			const UDialogueGraphInitNode* node = weakNode.Get();
			const TArray<FDialogueInit>* data = node ? node->GetInitData() : nullptr;
			return data && data->IsValidIndex(initIndex) ? (*data)[initIndex].Conditions.Num() : 0;
		})
		.OnGetCondition_Lambda([weakNode, initIndex](int32 conditionIndex) -> UDialogueCondition*
		{
			const UDialogueGraphInitNode* node = weakNode.Get();
			const TArray<FDialogueInit>* data = node ? node->GetInitData() : nullptr;
			if (!data || !data->IsValidIndex(initIndex)
				|| !(*data)[initIndex].Conditions.IsValidIndex(conditionIndex))
			{
				return nullptr;
			}

			return (*data)[initIndex].Conditions[conditionIndex].Get();
		})
		.OnSetConditionClass_Lambda([weakNode, initIndex](const UClass* conditionClass, int32 conditionIndex)
		{
			if (UDialogueGraphInitNode* node = weakNode.Get())
			{
				node->SetInitConditionClass(initIndex, conditionIndex, conditionClass);
			}
		})
		.OnAddCondition_Lambda([weakNode, initIndex]()
		{
			if (UDialogueGraphInitNode* node = weakNode.Get())
			{
				node->AddInitCondition(initIndex);
			}
		})
		.OnRemoveCondition_Lambda([weakNode, initIndex](int32 conditionIndex)
		{
			if (UDialogueGraphInitNode* node = weakNode.Get())
			{
				node->RemoveInitCondition(initIndex, conditionIndex);
			}
		}),
		FSlateApplication::Get().GetCursorPos(),
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
