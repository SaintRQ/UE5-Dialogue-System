// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueGraphNode.h"

#include "AssetRegistry/AssetData.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphResponseProviderNode.h"
#include "DialogueLibraryObject.h"
#include "DialogueRoot.h"
#include "DialogueToolSettings.h"
#include "EdGraph/EdGraph.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PropertyCustomizationHelpers.h"
#include "SDialogueAddButton.h"
#include "SDialogueConditionPopup.h"
#include "SDialogueGraphInitStatus.h"
#include "SDialogueRichTextEditor.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "Sound/SoundBase.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SDialogueGraphNode"

void SDialogueGraphNode::Construct(const FArguments& arguments, UDialogueGraphNode* dialogueNode)
{
	GraphNode = dialogueNode;
	SetCursor(EMouseCursor::CardinalCross);
	SetToolTipText(dialogueNode ? dialogueNode->GetTooltipText() : FText::GetEmpty());
	UpdateGraphNode();
}

void SDialogueGraphNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

	UDialogueGraphNode* dialogueNode = GetDialogueNode();
	const bool bLibrary = dialogueNode && dialogueNode->GetGraph()
		&& dialogueNode->GetGraph()->GetTypedOuter<UDialogueLibraryObject>();
	
	const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
	bool bHasProvider = false;
	
	TSharedRef<SGridPanel> content = SNew(SGridPanel)
		.FillColumn(0, 1.0f);
	
	TSharedRef<SVerticalBox> textContent = SNew(SVerticalBox);
	
	const auto createSection = [](
		const TSharedRef<SVerticalBox>& sectionContent,
		const FLinearColor& borderColor) -> TSharedRef<SWidget>
	{
		return SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
			.BorderBackgroundColor(borderColor)
			.Padding(2.0f)
			[
				SNew(SBorder)
				.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
				.BorderBackgroundColor(FLinearColor(0.008f, 0.012f, 0.018f))
				.Padding(6.0f)
				[
					sectionContent
				]
			];
		
	};
	
	
	const auto createSoundButton = [this](bool response, int32 entryIndex) -> TSharedRef<SWidget>
	{
		return SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "SimpleButton")
			.ContentPadding(2.0f)
			.ToolTipText(LOCTEXT("SoundTooltip", "Select a sound for this entry."))
			.OnClicked(this, &SDialogueGraphNode::OnOpenSound, response, entryIndex)
			[
				SNew(SImage)
				.Image(FAppStyle::GetBrush("Sequencer.Tracks.Audio"))
				.ColorAndOpacity(this, &SDialogueGraphNode::GetSoundIconColor, response, entryIndex)
			];
	};

	textContent->AddSlot()
	.AutoHeight()
	.Padding(2.0f)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
		.BorderBackgroundColor(FLinearColor(0.04f, 0.34f, 0.12f))
		.Padding(6.0f, 4.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("RootTextSection", "Text"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
			.Justification(ETextJustify::Center)
		]
	];

	if (dialogueData)
	{
		for (int32 textIndex = 0; textIndex < dialogueData->RootText.Num(); ++textIndex)
		{
			UEdGraphPin* providerPin = dialogueNode->GetRootTextProviderInputPin(textIndex);
			const UDialogueGraphResponseProviderNode* providerNode = providerPin && !providerPin->LinkedTo.IsEmpty()
				? Cast<UDialogueGraphResponseProviderNode>(providerPin->LinkedTo[0]->GetOwningNode())
				: nullptr;
			const bool bProviderText = providerNode != nullptr;
			bHasProvider |= bProviderText;
			TSharedRef<SWidget> textEditor = SNew(SDialogueRichTextEditor)
				.Text(dialogueData->RootText[textIndex])
				.HintText(LOCTEXT("RootTextHint", "Dialogue text"))
				.AutoWrapText(true)
				.OnTextCommitted(this, &SDialogueGraphNode::OnRootTextCommitted, textIndex);
			if (bProviderText)
			{
				const UClass* providerClass = providerNode->GetResponseProviderClass();
				const FText providerText = providerClass
					? FText::Format(
						LOCTEXT("ProviderRootText", "Provider: {0}"),
						providerClass->GetDisplayNameText())
					: LOCTEXT("EmptyProviderRootText", "Provider");
				textEditor = SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.025f, 0.2f, 0.38f))
					.Padding(6.0f, 4.0f)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(providerText)
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						.ColorAndOpacity(FLinearColor(0.4f, 0.82f, 1.0f))
						.AutoWrapText(true)
					];
			}

			TSharedRef<SHorizontalBox> textRow = SNew(SHorizontalBox);
			if (providerPin)
			{
				textRow->AddSlot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0.0f, 0.0f, 4.0f, 0.0f)
				[
					CreateDialoguePin(providerPin)
				];
			}

			textRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(FText::AsNumber(textIndex + 1))
			];

			textRow->AddSlot()
			.FillWidth(1.0f)
			[
				SNew(SBox)
				.WidthOverride(280.0f)
				.MinDesiredHeight(48.0f)
				[
					textEditor
				]
			];

			textRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f, 0.0f, 0.0f)
			[
				createSoundButton(false, textIndex)
			];

			textRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f, 0.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.IsEnabled(dialogueData->RootText.Num() > 1)
				.ToolTipText(LOCTEXT("RemoveRootTextTooltip", "Remove this text entry."))
				.OnClicked(this, &SDialogueGraphNode::OnRemoveRootText, textIndex)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Remove", "-"))
				]
			];

			// Provider outline
			TSharedRef<SWidget> textRowWidget = textRow;
			if (bProviderText)
			{
				textRowWidget = SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
					.BorderBackgroundColor(FLinearColor(0.04f, 0.48f, 0.78f))
					.Padding(2.0f)
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
						.BorderBackgroundColor(FLinearColor(0.008f, 0.025f, 0.055f))
						.Padding(6.0f, 3.0f)
						[
							textRow
						]
					];
			}

			textContent->AddSlot()
			.AutoHeight()
			.Padding(2.0f)
			[
				textRowWidget
			];
		}
	}

	textContent->AddSlot()
	.AutoHeight()
	.HAlign(HAlign_Center)
	.Padding(2.0f, 4.0f, 2.0f, 2.0f)
	[
		SNew(SDialogueAddButton)
		.Color(FLinearColor(0.06f, 0.62f, 0.22f, 0.5f))
		.OnClicked(this, &SDialogueGraphNode::OnAddRootText)
	];

	content->AddSlot(0, 1)
	.Padding(2.0f)
	[
		createSection(textContent, FLinearColor(0.12f, 0.62f, 0.27f, 0))
	];

	const int32 responseCount = dialogueData ? dialogueData->Response.Num() : 0;
	const bool bHasFinishResponse = dialogueData && dialogueData->Response.ContainsByPredicate(
		[](const FDialogueResponse& response)
		{
			return response.FinishDialogue;
		});
	const int32 responseHeaderRow = 2;
	const int32 addResponseRow = responseHeaderRow + responseCount + 1;

	content->AddSlot(0, responseHeaderRow)
	.RowSpan(responseCount + 2)
	.Padding(2.0f)
	[
		createSection(SNew(SVerticalBox), FLinearColor(0.12f, 0.42f, 0.82f, 0))
	];
	 
	content->AddSlot(0, responseHeaderRow, SGridPanel::Layer(1))
	.Padding(10.0f, 10.0f, 8.0f, 2.0f)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
		.BorderBackgroundColor(FLinearColor(0.04f, 0.2f, 0.56f))
		.Padding(6.0f, 4.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ResponsesSection", "Response"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
			.Justification(ETextJustify::Center)
		]
	];

	if (dialogueData)
	{
		for (int32 responseIndex = 0; responseIndex < responseCount; ++responseIndex)
		{
			const bool bFinishResponse = dialogueData->Response[responseIndex].FinishDialogue;
			const FName customTextId = dialogueData->Response[responseIndex].CustomTextId;
			const bool bCustomResponse = !customTextId.IsNone();
			UEdGraphPin* providerPin = dialogueNode->GetResponseProviderInputPin(responseIndex);
			const UDialogueGraphResponseProviderNode* providerNode = providerPin && !providerPin->LinkedTo.IsEmpty()
				? Cast<UDialogueGraphResponseProviderNode>(providerPin->LinkedTo[0]->GetOwningNode())
				: nullptr;
			const bool bProviderResponse = providerNode != nullptr;
			bHasProvider |= bProviderResponse;
			TSharedRef<SHorizontalBox> responseRow = SNew(SHorizontalBox);
			if (providerPin)
			{
				responseRow->AddSlot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0.0f, 0.0f, 4.0f, 0.0f)
				[
					CreateDialoguePin(providerPin)
				];
			}

			responseRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(FText::AsNumber(responseIndex + 1))
			];

			TSharedRef<SWidget> responseText = SNew(SDialogueRichTextEditor)
				.Text(dialogueData->Response[responseIndex].Response)
				.HintText(LOCTEXT("ResponseTextHint", "Response text"))
				.AutoWrapText(true)
				.OnTextCommitted(this, &SDialogueGraphNode::OnResponseTextCommitted, responseIndex);
			if (bFinishResponse)
			{
				responseText = SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.38f, 0.055f, 0.025f))
					.Padding(6.0f, 4.0f)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text_Lambda([bLibrary]()
						{
							const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
							const FText text = bLibrary
								? settings->ResponseReturnDialogueText
								: settings->ResponseEndDialogueText;
							return text.IsEmpty()
								? (bLibrary
									? LOCTEXT("ReturnResponseText", "Return")
									: LOCTEXT("FinishResponseText", "Finish Dialogue"))
								: text;
						})
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						.ColorAndOpacity(FLinearColor(1.0f, 0.58f, 0.36f))
						.AutoWrapText(true)
					];
			}
			else if (bCustomResponse)
			{
				responseText = SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.018f, 0.28f, 0.1f))
					.Padding(6.0f, 4.0f)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text_Lambda([customTextId]()
						{
							const FText* customText = GetDefault<UDialogueToolSettings>()
								->ResponseCustomTextList.Find(customTextId);
							return customText
								? *customText
								: FText::Format(
									LOCTEXT("MissingCustomResponseText", "Missing custom text: {0}"),
									FText::FromName(customTextId));
						})
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						.ColorAndOpacity(FLinearColor(0.42f, 1.0f, 0.6f))
						.AutoWrapText(true)
					];
			}
			else if (bProviderResponse)
			{
				const UClass* providerClass = providerNode->GetResponseProviderClass();
				const FText providerText = providerClass
					? FText::Format(
						LOCTEXT("ProviderResponseText", "Provider: {0}"),
						providerClass->GetDisplayNameText())
					: LOCTEXT("EmptyProviderResponseText", "Provider");
				responseText = SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.025f, 0.2f, 0.38f))
					.Padding(6.0f, 4.0f)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(providerText)
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
						.ColorAndOpacity(FLinearColor(0.4f, 0.82f, 1.0f))
						.AutoWrapText(true)
					];
			}

			responseRow->AddSlot()
			.FillWidth(1.0f)
			.VAlign(VAlign_Center)
			[
				SNew(SBox)
				.WidthOverride(280.0f)
				.MinDesiredHeight(40.0f)
				[
					responseText
				]
			];

			if (!bFinishResponse)
			{
				responseRow->AddSlot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4.0f, 0.0f, 0.0f, 0.0f)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "SimpleButton")
					.ContentPadding(2.0f)
					.ToolTipText(LOCTEXT(
						"ResponseAlwaysVisibleTooltip",
						"When enabled, a response that fails its conditions remains visible but disabled. "
						"When disabled, a failed response is hidden."))
					.OnClicked(this, &SDialogueGraphNode::OnToggleResponseAlwaysVisible, responseIndex)
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("Level.VisibleIcon16x"))
						.ColorAndOpacity(
							this,
							&SDialogueGraphNode::GetResponseAlwaysVisibleIconColor,
							responseIndex)
					]
				];

				responseRow->AddSlot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(4.0f, 0.0f, 0.0f, 0.0f)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "SimpleButton")
					.ContentPadding(2.0f)
					.ToolTipText(LOCTEXT("ResponseConditionsTooltip", "Edit conditions for this response."))
					.OnClicked(this, &SDialogueGraphNode::OnOpenResponseConditions, responseIndex)
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("Icons.Help"))
						.ColorAndOpacity(this, &SDialogueGraphNode::GetResponseConditionIconColor, responseIndex)
					]
				];
			}

			responseRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f, 0.0f, 0.0f)
			[
				createSoundButton(true, responseIndex)
			];

			responseRow->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(4.0f, 0.0f)
			[
				SNew(SButton)
				.ButtonStyle(FAppStyle::Get(), "SimpleButton")
				.ToolTipText(LOCTEXT("RemoveResponseTooltip", "Remove this response."))
				.OnClicked(this, &SDialogueGraphNode::OnRemoveResponse, responseIndex)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Remove", "-"))
				]
			];

			const int32 responseRowIndex = responseHeaderRow + responseIndex + 1;
			TSharedRef<SWidget> responseRowWidget = responseRow;
			if (bFinishResponse || bCustomResponse || bProviderResponse)
			{
				responseRowWidget = SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
					.BorderBackgroundColor(bFinishResponse
						? FLinearColor(0.78f, 0.16f, 0.055f)
						: bCustomResponse
							? FLinearColor(0.04f, 0.7f, 0.24f)
							: FLinearColor(0.04f, 0.48f, 0.78f))
					.Padding(2.0f)
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
						.BorderBackgroundColor(bFinishResponse
							? FLinearColor(0.055f, 0.014f, 0.008f)
							: bCustomResponse
								? FLinearColor(0.006f, 0.04f, 0.018f)
								: FLinearColor(0.008f, 0.025f, 0.055f))
						.Padding(6.0f, 3.0f)
						[
							responseRow
						]
					];
			}

			content->AddSlot(0, responseRowIndex, SGridPanel::Layer(1))
			.Padding(10.0f, 2.0f, 8.0f, 2.0f)
			[
				responseRowWidget
			];

			if (UEdGraphPin* responsePin = dialogueNode->GetResponseOutputPin(responseIndex))
			{
				content->AddSlot(1, responseRowIndex, SGridPanel::Layer(1))
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				[
					CreateDialoguePin(responsePin)
				];
			}
		}
	}

	TSharedRef<SHorizontalBox> addResponseButtons = SNew(SHorizontalBox);
	addResponseButtons->AddSlot()
	.AutoWidth()
	.Padding(2.0f)
	[
		SNew(SDialogueAddButton)
		.Color(FLinearColor(0.06f, 0.38f, 0.92f, 0.5f))
		.OnClicked(this, &SDialogueGraphNode::OnAddResponse)
	];
	addResponseButtons->AddSlot()
	.AutoWidth()
	.Padding(2.0f)
	[
		SNew(SDialogueAddButton)
	    .Color(FLinearColor(0.04f, 0.7f, 0.24f, 0.5))
		.Text(LOCTEXT("AddCustom", "Add Custom"))
		.OnClicked(this, &SDialogueGraphNode::OnOpenCustomResponseMenu)
	];
	if (!bHasFinishResponse)
	{
		addResponseButtons->AddSlot()
		.AutoWidth()
		.Padding(2.0f)
		[
			SNew(SDialogueAddButton)
			.Color(FLinearColor(0.78f, 0.16f, 0.055f, 0.5))
			.Text(bLibrary
				? LOCTEXT("AddReturn", "Add Return")
				: LOCTEXT("AddFinish", "Add Finish"))
			.OnClicked(this, &SDialogueGraphNode::OnAddFinishResponse)
		];
	}

	content->AddSlot(0, addResponseRow, SGridPanel::Layer(1))
	.HAlign(HAlign_Center)
	.Padding(10.0f, 4.0f, 8.0f, 10.0f)
	[
		addResponseButtons
	];

	TSharedRef<SWidget> inputWidget = SNullWidget::NullWidget;
	if (dialogueNode && dialogueNode->GetInputPin())
	{
		inputWidget = CreateDialoguePin(dialogueNode->GetInputPin());
	}

	TSharedRef<SWidget> outputWidget = SNullWidget::NullWidget;
	if (dialogueNode && dialogueNode->GetDefaultOutputPin())
	{
		outputWidget = CreateDialoguePin(dialogueNode->GetDefaultOutputPin());
	}

	ContentScale.Bind(this, &SGraphNode::GetContentScale);
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Center)
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
		.BorderBackgroundColor(this, &SDialogueGraphNode::GetBorderColor)
		.Padding(2.0f)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
			.BorderBackgroundColor(FLinearColor(0.008f, 0.012f, 0.018f))
			.Padding(0.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Graph.Node.ColorSpill"))
					.BorderBackgroundColor(FLinearColor(0.115f, 0.525f, 0.54f, 0.5f))
					.Padding(8.0f, 6.0f)
					[
						SNew(SOverlay)

						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("NodeTitle", "TOPIC"))
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 12))
							.ColorAndOpacity(FLinearColor(0.115f, 0.525f, 0.54f))
							.Justification(ETextJustify::Center)
							.ShadowOffset(FVector2D(1.0f, 1.0f))
						]

						+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SNew(SDialogueGraphInitStatus, dialogueNode)
						]
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(bHasProvider ? VAlign_Top : VAlign_Center)
					.Padding(2.0f)
					[
						inputWidget
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						content
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

UDialogueGraphNode* SDialogueGraphNode::GetDialogueNode() const
{
	return Cast<UDialogueGraphNode>(GraphNode);
}

TSharedRef<SGraphPin> SDialogueGraphNode::CreateDialoguePin(UEdGraphPin* pin)
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

FSlateColor SDialogueGraphNode::GetBorderColor() const
{
	const TSharedPtr<SGraphPanel> ownerPanel = GetOwnerPanel();
	return ownerPanel.IsValid() && ownerPanel->SelectionManager.IsNodeSelected(GraphNode)
		? FLinearColor(0.1f, 1.0f, 0.3f)
		: FLinearColor(0.008f, 0.012f, 0.018f);
}

FSlateColor SDialogueGraphNode::GetResponseConditionIconColor(int32 responseIndex) const
{
	const UDialogueGraphNode* dialogueNode = GetDialogueNode();
	const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
	const bool bHasConditions = dialogueData && dialogueData->Response.IsValidIndex(responseIndex)
		&& dialogueData->Response[responseIndex].Conditions.ContainsByPredicate(
			[](const TObjectPtr<UDialogueCondition>& condition)
			{
				return condition != nullptr;
			});
	return bHasConditions
		? FLinearColor(0.22f, 0.72f, 1.0f)
		: FLinearColor(0.5f, 0.53f, 0.58f, 0.4f);
}

FSlateColor SDialogueGraphNode::GetResponseAlwaysVisibleIconColor(int32 responseIndex) const
{
	const UDialogueGraphNode* dialogueNode = GetDialogueNode();
	const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
	const bool bAlwaysVisible = dialogueData && dialogueData->Response.IsValidIndex(responseIndex)
		&& dialogueData->Response[responseIndex].AlwaysVisible;
	return bAlwaysVisible
		? FLinearColor(0.22f, 0.72f, 1.0f)
		: FLinearColor(0.5f, 0.53f, 0.58f, 0.4f);
}

FSlateColor SDialogueGraphNode::GetSoundIconColor(bool response, int32 entryIndex) const
{
	const UDialogueGraphNode* dialogueNode = GetDialogueNode();
	const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
	const bool bHasSound = dialogueData && (response
		? dialogueData->Response.IsValidIndex(entryIndex)
			&& !dialogueData->Response[entryIndex].Sound.IsNull()
		: dialogueData->RootSounds.IsValidIndex(entryIndex)
			&& !dialogueData->RootSounds[entryIndex].IsNull());
	return bHasSound
		? FLinearColor(0.22f, 0.72f, 1.0f)
		: FLinearColor(0.5f, 0.53f, 0.58f, 0.4f);
}

FReply SDialogueGraphNode::OnAddRootText()
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->AddRootText();
		UpdateGraphNode();
	}

	return FReply::Handled();
}

FReply SDialogueGraphNode::OnRemoveRootText(int32 textIndex)
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->RemoveRootText(textIndex);
		UpdateGraphNode();
	}

	return FReply::Handled();
}

void SDialogueGraphNode::OnRootTextCommitted(const FText& text, ETextCommit::Type commitType, int32 textIndex)
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->SetRootText(textIndex, text);
	}
}

FReply SDialogueGraphNode::OnAddResponse()
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->AddResponse();
		UpdateGraphNode();
	}

	return FReply::Handled();
}

FReply SDialogueGraphNode::OnOpenCustomResponseMenu()
{
	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	TArray<FName> customTextIds;
	settings->ResponseCustomTextList.GenerateKeyArray(customTextIds);
	customTextIds.Sort([](const FName& left, const FName& right)
	{
		return left.LexicalLess(right);
	});

	FMenuBuilder menuBuilder(true, nullptr);
	if (customTextIds.IsEmpty())
	{
		menuBuilder.AddMenuEntry(
			LOCTEXT("NoCustomText", "No custom text configured"),
			FText::GetEmpty(),
			FSlateIcon(),
			FUIAction(
				FExecuteAction(),
				FCanExecuteAction::CreateLambda([]()
				{
					return false;
				})));
	}
	else
	{
		for (const FName customTextId : customTextIds)
		{
			menuBuilder.AddMenuEntry(
				FText::FromName(customTextId),
				settings->ResponseCustomTextList.FindChecked(customTextId),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateSP(
					this,
					&SDialogueGraphNode::OnAddCustomResponse,
					customTextId)));
		}
	}

	FSlateApplication::Get().PushMenu(
		AsShared(),
		FWidgetPath(),
		menuBuilder.MakeWidget(),
		FSlateApplication::Get().GetCursorPos(),
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
	return FReply::Handled();
}

void SDialogueGraphNode::OnAddCustomResponse(FName customTextId)
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->AddResponse(customTextId);
		UpdateGraphNode();
	}
}

FReply SDialogueGraphNode::OnAddFinishResponse()
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->AddFinishResponse();
		UpdateGraphNode();
	}

	return FReply::Handled();
}

FReply SDialogueGraphNode::OnRemoveResponse(int32 responseIndex)
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->RemoveResponse(responseIndex);
		UpdateGraphNode();
	}

	return FReply::Handled();
}

FReply SDialogueGraphNode::OnOpenResponseConditions(int32 responseIndex)
{
	UDialogueGraphNode* dialogueNode = GetDialogueNode();
	const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
	if (dialogueData && dialogueData->Response.IsValidIndex(responseIndex))
	{
		const TWeakObjectPtr<UDialogueGraphNode> weakNode = dialogueNode;
		FSlateApplication::Get().PushMenu(
			AsShared(),
			FWidgetPath(),
			SNew(SDialogueConditionPopup)
			.ConditionCount_Lambda([weakNode, responseIndex]()
			{
				const UDialogueGraphNode* node = weakNode.Get();
				const FDialogueNode* data = node ? node->GetDialogueData() : nullptr;
				return data && data->Response.IsValidIndex(responseIndex)
					? data->Response[responseIndex].Conditions.Num()
					: 0;
			})
			.OnGetCondition_Lambda([weakNode, responseIndex](int32 conditionIndex) -> UDialogueCondition*
			{
				const UDialogueGraphNode* node = weakNode.Get();
				const FDialogueNode* data = node ? node->GetDialogueData() : nullptr;
				if (!data || !data->Response.IsValidIndex(responseIndex)
					|| !data->Response[responseIndex].Conditions.IsValidIndex(conditionIndex))
				{
					return nullptr;
				}

				return data->Response[responseIndex].Conditions[conditionIndex].Get();
			})
			.OnSetConditionClass_Lambda([weakNode, responseIndex](const UClass* conditionClass, int32 conditionIndex)
			{
				if (UDialogueGraphNode* node = weakNode.Get())
				{
					node->SetResponseConditionClass(responseIndex, conditionIndex, conditionClass);
				}
			})
			.OnAddCondition_Lambda([weakNode, responseIndex]()
			{
				if (UDialogueGraphNode* node = weakNode.Get())
				{
					node->AddResponseCondition(responseIndex);
				}
			})
			.OnRemoveCondition_Lambda([weakNode, responseIndex](int32 conditionIndex)
			{
				if (UDialogueGraphNode* node = weakNode.Get())
				{
					node->RemoveResponseCondition(responseIndex, conditionIndex);
				}
			}),
			FSlateApplication::Get().GetCursorPos(),
			FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
	}

	return FReply::Handled();
}

FReply SDialogueGraphNode::OnOpenSound(bool response, int32 entryIndex)
{
	UDialogueGraphNode* dialogueNode = GetDialogueNode();
	const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
	if (!dialogueData || (response
		? !dialogueData->Response.IsValidIndex(entryIndex)
		: !dialogueData->RootText.IsValidIndex(entryIndex)))
	{
		return FReply::Handled();
	}

	const TWeakObjectPtr<UDialogueGraphNode> weakNode = dialogueNode;
	FSlateApplication::Get().PushMenu(
		AsShared(),
		FWidgetPath(),
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("Menu.Background"))
		.Padding(8.0f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(2.0f, 2.0f, 2.0f, 6.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SoundTitle", "Sound"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBox)
				.WidthOverride(360.0f)
				[
					SNew(SObjectPropertyEntryBox)
					.AllowedClass(USoundBase::StaticClass())
					.ObjectPath_Lambda([weakNode, response, entryIndex]()
					{
						const UDialogueGraphNode* node = weakNode.Get();
						const FDialogueNode* data = node ? node->GetDialogueData() : nullptr;
						if (!data)
						{
							return FString();
						}

						if (response)
						{
							return data->Response.IsValidIndex(entryIndex)
								? data->Response[entryIndex].Sound.ToSoftObjectPath().ToString()
								: FString();
						}

						return data->RootSounds.IsValidIndex(entryIndex)
							? data->RootSounds[entryIndex].ToSoftObjectPath().ToString()
							: FString();
					})
					.OnObjectChanged_Lambda([weakNode, response, entryIndex](const FAssetData& assetData)
					{
						if (UDialogueGraphNode* node = weakNode.Get())
						{
							const TSoftObjectPtr<USoundBase> sound(assetData.GetSoftObjectPath());
							if (response)
							{
								node->SetResponseSound(entryIndex, sound);
							}
							else
							{
								node->SetRootSound(entryIndex, sound);
							}
						}
					})
					.AllowClear(true)
					.DisplayBrowse(true)
					.DisplayUseSelected(true)
				]
			]
		],
		FSlateApplication::Get().GetCursorPos(),
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

	return FReply::Handled();
}

FReply SDialogueGraphNode::OnToggleResponseAlwaysVisible(int32 responseIndex)
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->ToggleResponseAlwaysVisible(responseIndex);
	}

	return FReply::Handled();
}

void SDialogueGraphNode::OnResponseTextCommitted(const FText& text, ETextCommit::Type commitType, int32 responseIndex)
{
	if (UDialogueGraphNode* dialogueNode = GetDialogueNode())
	{
		dialogueNode->SetResponseText(responseIndex, text);
	}
}

#undef LOCTEXT_NAMESPACE
