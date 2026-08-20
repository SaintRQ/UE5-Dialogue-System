// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphNodeFactory.h"

#include "DialogueGraphActionNode.h"
#include "DialogueGraphFinishNode.h"
#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphRerouteNode.h"
#include "DialogueGraphResponseProviderNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"
#include "SDialogueGraphActionNode.h"
#include "SDialogueGraphFinishNode.h"
#include "SDialogueGraphInitNode.h"
#include "SDialogueGraphNode.h"
#include "SDialogueGraphResponseProviderNode.h"
#include "SDialogueGraphSwitcherNode.h"
#include "SDialogueGraphTransitNode.h"
#include "SGraphNodeKnot.h"

TSharedPtr<SGraphNode> FDialogueGraphNodeFactory::CreateNode(UEdGraphNode* node) const
{
	if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(node))
	{
		return SNew(SDialogueGraphNode, dialogueNode);
	}

	if (UDialogueGraphInitNode* initNode = Cast<UDialogueGraphInitNode>(node))
	{
		return SNew(SDialogueGraphInitNode, initNode);
	}

	if (UDialogueGraphActionNode* actionNode = Cast<UDialogueGraphActionNode>(node))
	{
		return SNew(SDialogueGraphActionNode, actionNode);
	}

	if (UDialogueGraphFinishNode* finishNode = Cast<UDialogueGraphFinishNode>(node))
	{
		return SNew(SDialogueGraphFinishNode, finishNode);
	}

	if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(node))
	{
		return SNew(SDialogueGraphSwitcherNode, switcherNode);
	}

	if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(node))
	{
		return SNew(SDialogueGraphTransitNode, transitNode);
	}

	if (UDialogueGraphRerouteNode* rerouteNode = Cast<UDialogueGraphRerouteNode>(node))
	{
		return SNew(SGraphNodeKnot, rerouteNode);
	}

	if (UDialogueGraphResponseProviderNode* responseProviderNode = Cast<UDialogueGraphResponseProviderNode>(node))
	{
		return SNew(SDialogueGraphResponseProviderNode, responseProviderNode);
	}

	return nullptr;
}
