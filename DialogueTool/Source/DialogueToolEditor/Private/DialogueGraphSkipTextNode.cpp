// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphSkipTextNode.h"

#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueGraphUtilities.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"

#define LOCTEXT_NAMESPACE "DialogueGraphSkipTextNode"

namespace
{
	const FName skipTextPinCategory(TEXT("DialogueFlow"));
	const FName skipTextInputPinName(TEXT("Input"));
	const FName skipTextOutputPinName(TEXT("Output"));
}

void UDialogueGraphSkipTextNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, skipTextPinCategory, skipTextInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
	CreatePin(EGPD_Output, skipTextPinCategory, skipTextOutputPinName);
}

void UDialogueGraphSkipTextNode::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (SkipTextNodeId != 0)
	{
		return;
	}

	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	SkipTextNodeId = dialogueObject->GenerateUniqueId();
	dialogueObject->AddDialogueSkipText(SkipTextNodeId);
}

void UDialogueGraphSkipTextNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin)
	{
		UEdGraphPin* targetPin = fromPin->Direction == EGPD_Output ? GetInputPin() : GetOutputPin();
		GetSchema()->TryCreateConnection(fromPin, targetPin);
	}
}

void UDialogueGraphSkipTextNode::PrepareForCopying()
{
	Super::PrepareForCopying();
	if (const FDialogueSkipText* skipTextData = GetSkipTextData())
	{
		ClipboardSkipTextData = *skipTextData;
		HasClipboardSkipTextData = true;
	}
}

void UDialogueGraphSkipTextNode::PostPasteNode()
{
	Super::PostPasteNode();
	PastedFromSkipTextNodeId = SkipTextNodeId;
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	Modify();
	SkipTextNodeId = dialogueObject->GenerateUniqueId();
	FDialogueSkipText& skipTextData = dialogueObject->AddDialogueSkipText(SkipTextNodeId);
	skipTextData = HasClipboardSkipTextData ? ClipboardSkipTextData : FDialogueSkipText();
	FinishCopying();
}

void UDialogueGraphSkipTextNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);
	if (!pin)
	{
		return;
	}

	if (pin->Direction == EGPD_Output)
	{
		RefreshOutputConnection();
	}
	else
	{
		RefreshSourceNodes();
	}
}

void UDialogueGraphSkipTextNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	RefreshOutputConnection();
	RefreshSourceNodes();
}

void UDialogueGraphSkipTextNode::DestroyNode()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		dialogueObject->RemoveDialogueSkipText(SkipTextNodeId);
	}

	Super::DestroyNode();
	RefreshSourceNodes();
}

FText UDialogueGraphSkipTextNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "SKIP TEXT");
}

FText UDialogueGraphSkipTextNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Keeps the currently displayed topic text and immediately shows the responses of the next topic.\n"
		"The next topic is still marked as visited, but its text, providers, and sounds are not played.\n"
		"If the next topic has no responses, it opens normally so dialogue flow cannot become stuck.");
}

FDialogueSkipText* UDialogueGraphSkipTextNode::GetSkipTextData()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueSkipText(SkipTextNodeId);
	}

	return nullptr;
}

const FDialogueSkipText* UDialogueGraphSkipTextNode::GetSkipTextData() const
{
	if (const UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueSkipText(SkipTextNodeId);
	}

	return nullptr;
}

UEdGraphPin* UDialogueGraphSkipTextNode::GetInputPin() const
{
	return FindPin(skipTextInputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphSkipTextNode::GetOutputPin() const
{
	return FindPin(skipTextOutputPinName, EGPD_Output);
}

int64 UDialogueGraphSkipTextNode::GetSkipTextNodeId() const
{
	return SkipTextNodeId;
}

int64 UDialogueGraphSkipTextNode::GetPastedFromSkipTextNodeId() const
{
	return PastedFromSkipTextNodeId;
}

void UDialogueGraphSkipTextNode::FinishCopying()
{
	ClipboardSkipTextData = FDialogueSkipText();
	HasClipboardSkipTextData = false;
}

void UDialogueGraphSkipTextNode::RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds)
{
	FDialogueSkipText* skipTextData = GetSkipTextData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!skipTextData || !dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	if (const int64* pastedNodeId = pastedNodeIds.Find(skipTextData->NextNode))
	{
		skipTextData->NextNode = *pastedNodeId;
	}
	else
	{
		skipTextData->NextNode = -1;
	}
}

void UDialogueGraphSkipTextNode::RefreshOutputConnection()
{
	FDialogueSkipText* skipTextData = GetSkipTextData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!skipTextData || !dialogueObject)
	{
		return;
	}

	const FDialogueGraphResolvedConnection resolvedConnection = DialogueGraphUtilities::ResolveConnection(GetOutputPin());
	if (skipTextData->NextNode != resolvedConnection.NextNodeId
		|| skipTextData->Actions != resolvedConnection.Actions)
	{
		dialogueObject->Modify();
		skipTextData->NextNode = resolvedConnection.NextNodeId;
		skipTextData->Actions = resolvedConnection.Actions;
		dialogueObject->MarkPackageDirty();
	}
}

UDialogueObject* UDialogueGraphSkipTextNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphSkipTextNode::RefreshSourceNodes() const
{
	if (const UEdGraph* graph = GetGraph())
	{
		for (UEdGraphNode* node : graph->Nodes)
		{
			if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(node))
			{
				dialogueNode->NodeConnectionListChanged();
			}
			else if (UDialogueGraphInitNode* initNode = Cast<UDialogueGraphInitNode>(node))
			{
				initNode->NodeConnectionListChanged();
			}
			else if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(node))
			{
				switcherNode->RefreshOutputConnections();
			}
			else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(node))
			{
				transitNode->RefreshOutputConnection();
			}
			else if (UDialogueGraphSkipTextNode* skipTextNode = Cast<UDialogueGraphSkipTextNode>(node);
				skipTextNode && skipTextNode != this)
			{
				skipTextNode->RefreshOutputConnection();
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
