// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphRerouteNode.h"

#include "DialogueGraphActionNode.h"
#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphRandomNode.h"
#include "DialogueGraphSkipTextNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"

#define LOCTEXT_NAMESPACE "DialogueGraphRerouteNode"

namespace
{
	const FName reroutePinCategory(TEXT("DialogueFlow"));
	const FName rerouteInputPinName(TEXT("Input"));
	const FName rerouteOutputPinName(TEXT("Output"));
}

void UDialogueGraphRerouteNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, reroutePinCategory, rerouteInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
	CreatePin(EGPD_Output, reroutePinCategory, rerouteOutputPinName);
}

void UDialogueGraphRerouteNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin)
	{
		UEdGraphPin* targetPin = fromPin->Direction == EGPD_Output ? GetInputPin() : GetOutputPin();
		GetSchema()->TryCreateConnection(fromPin, targetPin);
	}
}

void UDialogueGraphRerouteNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);
	TSet<const UEdGraphNode*> visitedNodes;
	RefreshUpstreamDialogueNodes(visitedNodes);
}

void UDialogueGraphRerouteNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	TSet<const UEdGraphNode*> visitedNodes;
	RefreshUpstreamDialogueNodes(visitedNodes);
}

bool UDialogueGraphRerouteNode::ShouldDrawNodeAsControlPointOnly(
	int32& outInputPinIndex,
	int32& outOutputPinIndex) const
{
	outInputPinIndex = 0;
	outOutputPinIndex = 1;
	return true;
}

FText UDialogueGraphRerouteNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "REROUTE");
}

FText UDialogueGraphRerouteNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Redirects a dialogue wire to keep the graph readable.\n"
		"This node has no runtime behavior and does not change execution order or dialogue data.");
}

UEdGraphPin* UDialogueGraphRerouteNode::GetInputPin() const
{
	return FindPin(rerouteInputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphRerouteNode::GetOutputPin() const
{
	return FindPin(rerouteOutputPinName, EGPD_Output);
}

void UDialogueGraphRerouteNode::RefreshUpstreamDialogueNodes(
	TSet<const UEdGraphNode*>& visitedNodes) const
{
	TFunction<void(const UEdGraphNode*)> refreshNode;
	refreshNode = [&visitedNodes, &refreshNode](const UEdGraphNode* node)
	{
		if (!node || visitedNodes.Contains(node))
		{
			return;
		}

		visitedNodes.Add(node);
		const UEdGraphPin* inputPin = nullptr;
		if (const UDialogueGraphRerouteNode* rerouteNode = Cast<UDialogueGraphRerouteNode>(node))
		{
			inputPin = rerouteNode->GetInputPin();
		}
		else if (const UDialogueGraphActionNode* actionNode = Cast<UDialogueGraphActionNode>(node))
		{
			inputPin = actionNode->GetInputPin();
		}

		if (!inputPin)
		{
			return;
		}

		for (UEdGraphPin* sourcePin : inputPin->LinkedTo)
		{
			if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(sourcePin->GetOwningNode()))
			{
				dialogueNode->PinConnectionListChanged(sourcePin);
			}
			else if (UDialogueGraphInitNode* initNode = Cast<UDialogueGraphInitNode>(sourcePin->GetOwningNode()))
			{
				initNode->PinConnectionListChanged(sourcePin);
			}
			else if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(sourcePin->GetOwningNode()))
			{
				switcherNode->PinConnectionListChanged(sourcePin);
			}
			else if (UDialogueGraphRandomNode* randomNode = Cast<UDialogueGraphRandomNode>(sourcePin->GetOwningNode()))
			{
				randomNode->PinConnectionListChanged(sourcePin);
			}
			else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(sourcePin->GetOwningNode()))
			{
				transitNode->PinConnectionListChanged(sourcePin);
			}
			else if (UDialogueGraphSkipTextNode* skipTextNode = Cast<UDialogueGraphSkipTextNode>(sourcePin->GetOwningNode()))
			{
				skipTextNode->PinConnectionListChanged(sourcePin);
			}
			else
			{
				refreshNode(sourcePin->GetOwningNode());
			}
		}
	};

	refreshNode(this);
}

#undef LOCTEXT_NAMESPACE
