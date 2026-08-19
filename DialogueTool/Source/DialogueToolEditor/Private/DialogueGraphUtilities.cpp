// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphUtilities.h"

#include "DialogueGraphActionNode.h"
#include "DialogueGraphFinishNode.h"
#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphRerouteNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"

namespace
{
	bool IsFinishResponseOutput(const UEdGraphPin* outputPin)
	{
		const UDialogueGraphNode* dialogueNode = outputPin
			? Cast<UDialogueGraphNode>(outputPin->GetOwningNode())
			: nullptr;
		const FDialogueNode* dialogueData = dialogueNode ? dialogueNode->GetDialogueData() : nullptr;
		if (!dialogueData || outputPin->Direction != EGPD_Output)
		{
			return false;
		}

		for (int32 responseIndex = 0; responseIndex < dialogueData->Response.Num(); ++responseIndex)
		{
			if (dialogueData->Response[responseIndex].FinishDialogue
				&& dialogueNode->GetResponseOutputPin(responseIndex) == outputPin)
			{
				return true;
			}
		}

		return false;
	}
}

FDialogueGraphResolvedConnection DialogueGraphUtilities::ResolveConnection(const UEdGraphPin* outputPin)
{
	FDialogueGraphResolvedConnection result;
	const UEdGraphPin* currentOutputPin = outputPin;
	TSet<const UEdGraphNode*> visitedNodes;

	while (currentOutputPin && !currentOutputPin->LinkedTo.IsEmpty())
	{
		const UEdGraphNode* linkedNode = currentOutputPin->LinkedTo[0]->GetOwningNode();
		if (!linkedNode || visitedNodes.Contains(linkedNode))
		{
			return result;
		}

		visitedNodes.Add(linkedNode);
		if (const UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(linkedNode))
		{
			result.NextNodeId = dialogueNode->GetDialogueNodeId();
			return result;
		}

		if (const UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(linkedNode))
		{
			result.NextNodeId = switcherNode->GetSwitcherNodeId();
			return result;
		}

		if (const UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(linkedNode))
		{
			result.NextNodeId = transitNode->GetTransitNodeId();
			return result;
		}

		if (linkedNode->IsA<UDialogueGraphFinishNode>())
		{
			result.NextNodeId = DialogueFinishNodeId;
			return result;
		}

		if (const UDialogueGraphRerouteNode* rerouteNode = Cast<UDialogueGraphRerouteNode>(linkedNode))
		{
			currentOutputPin = rerouteNode->GetOutputPin();
			continue;
		}

		if (const UDialogueGraphActionNode* actionNode = Cast<UDialogueGraphActionNode>(linkedNode))
		{
			for (UDialogueAction* action : actionNode->GetActions())
			{
				if (action)
				{
					result.Actions.Add(action);
				}
			}

			currentOutputPin = actionNode->GetOutputPin();
			continue;
		}

		return result;
	}

	return result;
}

bool DialogueGraphUtilities::IsConnectedToInit(const UEdGraphNode* node)
{
	TArray<const UEdGraphNode*> pendingNodes;
	TSet<const UEdGraphNode*> visitedNodes;
	pendingNodes.Add(node);

	while (!pendingNodes.IsEmpty())
	{
		const UEdGraphNode* currentNode = pendingNodes.Pop(EAllowShrinking::No);
		if (!currentNode || visitedNodes.Contains(currentNode))
		{
			continue;
		}

		visitedNodes.Add(currentNode);
		if (currentNode->IsA<UDialogueGraphInitNode>())
		{
			return true;
		}

		for (const UEdGraphPin* pin : currentNode->Pins)
		{
			if (!pin || pin->Direction != EGPD_Input)
			{
				continue;
			}

			for (const UEdGraphPin* sourcePin : pin->LinkedTo)
			{
				if (sourcePin && sourcePin->Direction == EGPD_Output)
				{
					pendingNodes.Add(sourcePin->GetOwningNode());
				}
			}
		}
	}

	return false;
}

bool DialogueGraphUtilities::IsFinishResponseFlow(const UEdGraphPin* outputPin)
{
	if (!outputPin || outputPin->Direction != EGPD_Output)
	{
		return false;
	}

	TArray<const UEdGraphPin*> pendingOutputs;
	TSet<const UEdGraphNode*> visitedNodes;
	pendingOutputs.Add(outputPin);
	while (!pendingOutputs.IsEmpty())
	{
		const UEdGraphPin* currentOutput = pendingOutputs.Pop(EAllowShrinking::No);
		if (IsFinishResponseOutput(currentOutput))
		{
			return true;
		}

		const UEdGraphNode* currentNode = currentOutput ? currentOutput->GetOwningNode() : nullptr;
		if (!currentNode || visitedNodes.Contains(currentNode))
		{
			continue;
		}

		visitedNodes.Add(currentNode);
		const UEdGraphPin* inputPin = nullptr;
		if (const UDialogueGraphActionNode* actionNode = Cast<UDialogueGraphActionNode>(currentNode))
		{
			inputPin = actionNode->GetInputPin();
		}
		else if (const UDialogueGraphRerouteNode* rerouteNode = Cast<UDialogueGraphRerouteNode>(currentNode))
		{
			inputPin = rerouteNode->GetInputPin();
		}

		if (!inputPin)
		{
			continue;
		}

		for (const UEdGraphPin* sourcePin : inputPin->LinkedTo)
		{
			if (sourcePin && sourcePin->Direction == EGPD_Output)
			{
				pendingOutputs.Add(sourcePin);
			}
		}
	}

	return false;
}

bool DialogueGraphUtilities::IsValidFinishResponseTarget(const UEdGraphNode* node)
{
	if (!node)
	{
		return false;
	}

	TArray<const UEdGraphNode*> pendingNodes;
	TSet<const UEdGraphNode*> visitedNodes;
	pendingNodes.Add(node);
	while (!pendingNodes.IsEmpty())
	{
		const UEdGraphNode* currentNode = pendingNodes.Pop(EAllowShrinking::No);
		if (!currentNode || visitedNodes.Contains(currentNode))
		{
			continue;
		}

		visitedNodes.Add(currentNode);
		const UEdGraphPin* outputPin = nullptr;
		if (const UDialogueGraphActionNode* actionNode = Cast<UDialogueGraphActionNode>(currentNode))
		{
			outputPin = actionNode->GetOutputPin();
		}
		else if (const UDialogueGraphRerouteNode* rerouteNode = Cast<UDialogueGraphRerouteNode>(currentNode))
		{
			outputPin = rerouteNode->GetOutputPin();
		}
		else
		{
			return false;
		}

		for (const UEdGraphPin* targetPin : outputPin->LinkedTo)
		{
			if (targetPin)
			{
				pendingNodes.Add(targetPin->GetOwningNode());
			}
		}
	}

	return true;
}
