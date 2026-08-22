// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphTransitNode.h"

#include "DialogueGraphInitNode.h"
#include "DialogueGraphLibrarySchema.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphSkipTextNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphUtilities.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphTransitNode"

namespace
{
	const FName transitPinCategory(TEXT("DialogueFlow"));
	const FName transitInputPinName(TEXT("Input"));
	const FName transitOutputPinName(TEXT("Return"));
}

void UDialogueGraphTransitNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, transitPinCategory, transitInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
	CreatePin(EGPD_Output, transitPinCategory, transitOutputPinName);
}

void UDialogueGraphTransitNode::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (TransitNodeId != 0)
	{
		return;
	}

	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject || dialogueObject->IsA<UDialogueLibraryObject>())
	{
		return;
	}

	dialogueObject->Modify();
	TransitNodeId = dialogueObject->GenerateUniqueId();
	dialogueObject->AddDialogueTransit(TransitNodeId);
}

void UDialogueGraphTransitNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin)
	{
		UEdGraphPin* targetPin = fromPin->Direction == EGPD_Output ? GetInputPin() : GetOutputPin();
		GetSchema()->TryCreateConnection(fromPin, targetPin);
	}
}

void UDialogueGraphTransitNode::PrepareForCopying()
{
	Super::PrepareForCopying();
	if (const FDialogueTransit* transitData = GetTransitData())
	{
		ClipboardTransitData = *transitData;
		HasClipboardTransitData = true;
	}
}

void UDialogueGraphTransitNode::PostPasteNode()
{
	Super::PostPasteNode();
	PastedFromTransitNodeId = TransitNodeId;
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject || dialogueObject->IsA<UDialogueLibraryObject>())
	{
		return;
	}

	dialogueObject->Modify();
	Modify();
	TransitNodeId = dialogueObject->GenerateUniqueId();
	FDialogueTransit& transitData = dialogueObject->AddDialogueTransit(TransitNodeId);
	transitData = HasClipboardTransitData ? ClipboardTransitData : FDialogueTransit();
	FinishCopying();
}

void UDialogueGraphTransitNode::PinConnectionListChanged(UEdGraphPin* pin)
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

void UDialogueGraphTransitNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	RefreshOutputConnection();
	RefreshSourceNodes();
}

void UDialogueGraphTransitNode::DestroyNode()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		dialogueObject->RemoveDialogueTransit(TransitNodeId);
	}

	Super::DestroyNode();
	RefreshSourceNodes();
}

bool UDialogueGraphTransitNode::CanCreateUnderSpecifiedSchema(const UEdGraphSchema* schema) const
{
	return schema && !schema->IsA<UDialogueGraphLibrarySchema>();
}

FText UDialogueGraphTransitNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "TRANSIT");
}

FText UDialogueGraphTransitNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Temporarily transfers execution from this dialogue into the selected dialogue library.\n"
		"The library chooses its first valid entry branch and runs until it reaches RETURN.\n"
		"After returning, the configured Return actions execute and flow continues through the Return output.");
}

FDialogueTransit* UDialogueGraphTransitNode::GetTransitData()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueTransit(TransitNodeId);
	}

	return nullptr;
}

const FDialogueTransit* UDialogueGraphTransitNode::GetTransitData() const
{
	if (const UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueTransit(TransitNodeId);
	}

	return nullptr;
}

UEdGraphPin* UDialogueGraphTransitNode::GetInputPin() const
{
	return FindPin(transitInputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphTransitNode::GetOutputPin() const
{
	return FindPin(transitOutputPinName, EGPD_Output);
}

int64 UDialogueGraphTransitNode::GetTransitNodeId() const
{
	return TransitNodeId;
}

int64 UDialogueGraphTransitNode::GetPastedFromTransitNodeId() const
{
	return PastedFromTransitNodeId;
}

void UDialogueGraphTransitNode::FinishCopying()
{
	ClipboardTransitData = FDialogueTransit();
	HasClipboardTransitData = false;
}

void UDialogueGraphTransitNode::RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds)
{
	FDialogueTransit* transitData = GetTransitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!transitData || !dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	if (const int64* pastedNodeId = pastedNodeIds.Find(transitData->ReturnNode))
	{
		transitData->ReturnNode = *pastedNodeId;
	}
	else
	{
		transitData->ReturnNode = -1;
	}
}

void UDialogueGraphTransitNode::SetDialogueLibrary(UDialogueLibraryObject* dialogueLibrary)
{
	FDialogueTransit* transitData = GetTransitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!transitData || !dialogueObject || transitData->DialogueLibrary == dialogueLibrary)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetDialogueLibrary", "Set Transit Dialogue Library"));
	dialogueObject->Modify();
	transitData->DialogueLibrary = dialogueLibrary;
	NotifyTransitChanged();
}

UDialogueObject* UDialogueGraphTransitNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphTransitNode::RefreshOutputConnection()
{
	FDialogueTransit* transitData = GetTransitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!transitData || !dialogueObject)
	{
		return;
	}

	const FDialogueGraphResolvedConnection resolvedConnection = DialogueGraphUtilities::ResolveConnection(GetOutputPin());
	if (transitData->ReturnNode != resolvedConnection.NextNodeId
		|| transitData->ReturnActions != resolvedConnection.Actions)
	{
		dialogueObject->Modify();
		transitData->ReturnNode = resolvedConnection.NextNodeId;
		transitData->ReturnActions = resolvedConnection.Actions;
		dialogueObject->MarkPackageDirty();
	}
}

void UDialogueGraphTransitNode::RefreshSourceNodes() const
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
			else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(node);
				transitNode && transitNode != this)
			{
				transitNode->RefreshOutputConnection();
			}
			else if (UDialogueGraphSkipTextNode* skipTextNode = Cast<UDialogueGraphSkipTextNode>(node))
			{
				skipTextNode->RefreshOutputConnection();
			}
		}
	}
}

void UDialogueGraphTransitNode::NotifyTransitChanged()
{
	Modify();
	if (UEdGraph* graph = GetGraph())
	{
		graph->NotifyNodeChanged(this);
	}

	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->MarkPackageDirty();
	}
}

#undef LOCTEXT_NAMESPACE
