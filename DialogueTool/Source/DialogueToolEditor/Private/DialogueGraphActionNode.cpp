// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphActionNode.h"

#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphActionNode"

namespace
{
	const FName actionPinCategory(TEXT("DialogueFlow"));
	const FName actionInputPinName(TEXT("Input"));
	const FName actionOutputPinName(TEXT("Output"));
}

void UDialogueGraphActionNode::PostLoad()
{
	Super::PostLoad();
	if (Actions.IsEmpty())
	{
		Actions.Add(nullptr);
	}
}

void UDialogueGraphActionNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, actionPinCategory, actionInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
	CreatePin(EGPD_Output, actionPinCategory, actionOutputPinName);
}

void UDialogueGraphActionNode::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (Actions.IsEmpty())
	{
		Actions.Add(nullptr);
	}
}

void UDialogueGraphActionNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin)
	{
		UEdGraphPin* targetPin = fromPin->Direction == EGPD_Output ? GetInputPin() : GetOutputPin();
		GetSchema()->TryCreateConnection(fromPin, targetPin);
	}
}

void UDialogueGraphActionNode::PostPasteNode()
{
	Super::PostPasteNode();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject)
	{
		return;
	}

	Modify();
	for (TObjectPtr<UDialogueAction>& action : Actions)
	{
		if (action)
		{
			action = DuplicateObject<UDialogueAction>(action.Get(), dialogueObject);
		}
	}
	if (Actions.IsEmpty())
	{
		Actions.Add(nullptr);
	}
	NotifyActionsChanged();
}

void UDialogueGraphActionNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);
	RefreshDialogueNodes();
}

void UDialogueGraphActionNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	RefreshDialogueNodes();
}

void UDialogueGraphActionNode::DestroyNode()
{
	Super::DestroyNode();
	RefreshDialogueNodes();
}

FText UDialogueGraphActionNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "ACTIONS");
}

FText UDialogueGraphActionNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Executes the configured action instances from top to bottom when dialogue flow reaches this node.\n"
		"Every action exposes its editable variables directly in the node; empty entries are skipped.\n"
		"After the final action, execution continues through the output connection.");
}

UEdGraphPin* UDialogueGraphActionNode::GetInputPin() const
{
	return FindPin(actionInputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphActionNode::GetOutputPin() const
{
	return FindPin(actionOutputPinName, EGPD_Output);
}

const TArray<TObjectPtr<UDialogueAction>>& UDialogueGraphActionNode::GetActions() const
{
	return Actions;
}

void UDialogueGraphActionNode::AddAction()
{
	const FScopedTransaction transaction(LOCTEXT("AddAction", "Add Dialogue Action"));
	Modify();
	Actions.Add(nullptr);
	NotifyActionsChanged();
}

void UDialogueGraphActionNode::RemoveAction(int32 actionIndex)
{
	if (Actions.Num() <= 1 || !Actions.IsValidIndex(actionIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveAction", "Remove Dialogue Action"));
	Modify();
	Actions.RemoveAt(actionIndex);
	NotifyActionsChanged();
}

void UDialogueGraphActionNode::SetActionClass(int32 actionIndex, const UClass* actionClass)
{
	if (actionClass && (!actionClass->IsChildOf(UDialogueAction::StaticClass())
		|| actionClass->HasAnyClassFlags(CLASS_Abstract)))
	{
		return;
	}

	UDialogueAction* currentAction = Actions.IsValidIndex(actionIndex) ? Actions[actionIndex].Get() : nullptr;
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!Actions.IsValidIndex(actionIndex) || (actionClass && !dialogueObject)
		|| (currentAction ? currentAction->GetClass() : nullptr) == actionClass)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetAction", "Set Dialogue Action"));
	Modify();
	Actions[actionIndex] = actionClass && dialogueObject
		? NewObject<UDialogueAction>(dialogueObject, const_cast<UClass*>(actionClass), NAME_None, RF_Transactional)
		: nullptr;
	NotifyActionsChanged();
}

UDialogueObject* UDialogueGraphActionNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphActionNode::NotifyActionsChanged()
{
	RefreshDialogueNodes();

	if (UEdGraph* graph = GetGraph())
	{
		graph->NotifyNodeChanged(this);
	}

	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->MarkPackageDirty();
	}
}

void UDialogueGraphActionNode::RefreshDialogueNodes() const
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
		}
	}
}

#undef LOCTEXT_NAMESPACE
