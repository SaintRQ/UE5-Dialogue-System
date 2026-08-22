// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphSwitcherNode.h"

#include "DialogueCondition.h"
#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphSkipTextNode.h"
#include "DialogueGraphUtilities.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphSwitcherNode"

namespace
{
	const FName switcherPinCategory(TEXT("DialogueFlow"));
	const FName switcherInputPinName(TEXT("Input"));

	FName GetConditionPinName(int32 conditionIndex)
	{
		return FName(*FString::Printf(TEXT("Condition_%d"), conditionIndex));
	}
}

void UDialogueGraphSwitcherNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, switcherPinCategory, switcherInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
	const FDialogueSwitcher* switcherData = GetSwitcherData();
	if (!switcherData)
	{
		return;
	}

	for (int32 conditionIndex = 0; conditionIndex < switcherData->Conditions.Num(); ++conditionIndex)
	{
		CreatePin(EGPD_Output, switcherPinCategory, GetConditionPinName(conditionIndex));
	}
}

void UDialogueGraphSwitcherNode::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (SwitcherNodeId != 0)
	{
		return;
	}

	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		SwitcherNodeId = dialogueObject->GenerateUniqueId();
		dialogueObject->AddDialogueSwitcher(SwitcherNodeId);
	}
}

void UDialogueGraphSwitcherNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin)
	{
		UEdGraphPin* targetPin = fromPin->Direction == EGPD_Output ? GetInputPin() : GetConditionOutputPin(0);
		GetSchema()->TryCreateConnection(fromPin, targetPin);
	}
}

void UDialogueGraphSwitcherNode::PrepareForCopying()
{
	Super::PrepareForCopying();
	if (const FDialogueSwitcher* switcherData = GetSwitcherData())
	{
		ClipboardSwitcherData = *switcherData;
		HasClipboardSwitcherData = true;
	}
}

void UDialogueGraphSwitcherNode::PostPasteNode()
{
	Super::PostPasteNode();
	PastedFromSwitcherNodeId = SwitcherNodeId;
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	Modify();
	SwitcherNodeId = dialogueObject->GenerateUniqueId();
	FDialogueSwitcher& switcherData = dialogueObject->AddDialogueSwitcher(SwitcherNodeId);
	switcherData = HasClipboardSwitcherData ? ClipboardSwitcherData : FDialogueSwitcher();
	switcherData.EnsureMinimumConditions();
	for (FDialogueSwitcherCondition& condition : switcherData.Conditions)
	{
		for (TObjectPtr<UDialogueCondition>& requirement : condition.Conditions)
		{
			if (requirement)
			{
				requirement = DuplicateObject<UDialogueCondition>(requirement.Get(), dialogueObject);
			}
		}
	}
	FinishCopying();
}

void UDialogueGraphSwitcherNode::ReconstructNode()
{
	TMap<FName, TArray<UEdGraphPin*>> linkedPins;
	for (UEdGraphPin* pin : Pins)
	{
		if (pin && !pin->LinkedTo.IsEmpty())
		{
			linkedPins.Add(pin->PinName, pin->LinkedTo);
		}
	}

	while (!Pins.IsEmpty())
	{
		Pins[0]->BreakAllPinLinks();
		RemovePin(Pins[0]);
	}
	AllocateDefaultPins();

	for (const TPair<FName, TArray<UEdGraphPin*>>& linkedPin : linkedPins)
	{
		UEdGraphPin* newPin = FindPin(linkedPin.Key);
		if (!newPin)
		{
			continue;
		}

		for (UEdGraphPin* targetPin : linkedPin.Value)
		{
			if (targetPin)
			{
				newPin->MakeLinkTo(targetPin);
			}
		}
	}
}

void UDialogueGraphSwitcherNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);
	if (!pin)
	{
		return;
	}

	if (pin->Direction == EGPD_Output)
	{
		SynchronizeOutput(pin);
	}
	else
	{
		RefreshSourceNodes();
	}
}

void UDialogueGraphSwitcherNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	RefreshOutputConnections();
	RefreshSourceNodes();
}

void UDialogueGraphSwitcherNode::DestroyNode()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		dialogueObject->RemoveDialogueSwitcher(SwitcherNodeId);
	}
	Super::DestroyNode();
	RefreshSourceNodes();
}

FText UDialogueGraphSwitcherNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "SWITCH");
}

FText UDialogueGraphSwitcherNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Selects one outgoing dialogue branch using its condition lists.\n"
		"Branches are evaluated from top to bottom, and only the first branch whose conditions all pass is used.\n"
		"That branch's actions execute in order before flow continues through its output.");
}

FDialogueSwitcher* UDialogueGraphSwitcherNode::GetSwitcherData()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueSwitcher(SwitcherNodeId);
	}
	return nullptr;
}

const FDialogueSwitcher* UDialogueGraphSwitcherNode::GetSwitcherData() const
{
	if (const UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueSwitcher(SwitcherNodeId);
	}
	return nullptr;
}

UEdGraphPin* UDialogueGraphSwitcherNode::GetInputPin() const
{
	return FindPin(switcherInputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphSwitcherNode::GetConditionOutputPin(int32 conditionIndex) const
{
	return FindPin(GetConditionPinName(conditionIndex), EGPD_Output);
}

int64 UDialogueGraphSwitcherNode::GetSwitcherNodeId() const
{
	return SwitcherNodeId;
}

int64 UDialogueGraphSwitcherNode::GetPastedFromSwitcherNodeId() const
{
	return PastedFromSwitcherNodeId;
}

void UDialogueGraphSwitcherNode::FinishCopying()
{
	ClipboardSwitcherData = FDialogueSwitcher();
	HasClipboardSwitcherData = false;
}

void UDialogueGraphSwitcherNode::RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!switcherData || !dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	for (FDialogueSwitcherCondition& condition : switcherData->Conditions)
	{
		if (const int64* pastedNodeId = pastedNodeIds.Find(condition.NextNode))
		{
			condition.NextNode = *pastedNodeId;
		}
		else
		{
			condition.NextNode = -1;
		}
	}
}

void UDialogueGraphSwitcherNode::AddCondition()
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!switcherData || !dialogueObject)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("AddCondition", "Add Switch Condition"));
	dialogueObject->Modify();
	Modify();
	FDialogueSwitcherCondition& condition = switcherData->Conditions.AddDefaulted_GetRef();
	condition.Name = FName(*FString::Printf(TEXT("Condition %d"), switcherData->Conditions.Num()));
	NotifySwitcherChanged(true);
}

void UDialogueGraphSwitcherNode::RemoveCondition(int32 conditionIndex)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!switcherData || !dialogueObject || switcherData->Conditions.Num() <= 2
		|| !switcherData->Conditions.IsValidIndex(conditionIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveCondition", "Remove Switch Condition"));
	dialogueObject->Modify();
	Modify();
	if (UEdGraphPin* removedPin = GetConditionOutputPin(conditionIndex))
	{
		removedPin->BreakAllPinLinks();
		RemovePin(removedPin);
	}
	for (int32 oldIndex = conditionIndex + 1; oldIndex < switcherData->Conditions.Num(); ++oldIndex)
	{
		if (UEdGraphPin* shiftedPin = GetConditionOutputPin(oldIndex))
		{
			shiftedPin->PinName = GetConditionPinName(oldIndex - 1);
		}
	}
	switcherData->Conditions.RemoveAt(conditionIndex);
	NotifySwitcherChanged(true);
}

void UDialogueGraphSwitcherNode::SetConditionName(int32 conditionIndex, FName name)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!switcherData || !dialogueObject || !switcherData->Conditions.IsValidIndex(conditionIndex)
		|| switcherData->Conditions[conditionIndex].Name == name)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetConditionName", "Set Switch Condition Name"));
	dialogueObject->Modify();
	switcherData->Conditions[conditionIndex].Name = name;
	NotifySwitcherChanged(false);
}

void UDialogueGraphSwitcherNode::AddConditionRequirement(int32 conditionIndex)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!switcherData || !dialogueObject || !switcherData->Conditions.IsValidIndex(conditionIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("AddConditionRequirement", "Add Switch Condition Requirement"));
	dialogueObject->Modify();
	switcherData->Conditions[conditionIndex].Conditions.Add(nullptr);
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphSwitcherNode::RemoveConditionRequirement(int32 conditionIndex, int32 requirementIndex)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!switcherData || !dialogueObject || !switcherData->Conditions.IsValidIndex(conditionIndex)
		|| !switcherData->Conditions[conditionIndex].Conditions.IsValidIndex(requirementIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveConditionRequirement", "Remove Switch Condition Requirement"));
	dialogueObject->Modify();
	switcherData->Conditions[conditionIndex].Conditions.RemoveAt(requirementIndex);
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphSwitcherNode::SetConditionRequirementClass(
	int32 conditionIndex,
	int32 requirementIndex,
	const UClass* conditionClass)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (conditionClass && (!conditionClass->IsChildOf(UDialogueCondition::StaticClass())
		|| conditionClass->HasAnyClassFlags(CLASS_Abstract)))
	{
		return;
	}

	UDialogueCondition* currentCondition = switcherData && switcherData->Conditions.IsValidIndex(conditionIndex)
		&& switcherData->Conditions[conditionIndex].Conditions.IsValidIndex(requirementIndex)
		? switcherData->Conditions[conditionIndex].Conditions[requirementIndex].Get()
		: nullptr;
	if (!switcherData || !dialogueObject || !switcherData->Conditions.IsValidIndex(conditionIndex)
		|| !switcherData->Conditions[conditionIndex].Conditions.IsValidIndex(requirementIndex)
		|| (currentCondition ? currentCondition->GetClass() : nullptr) == conditionClass)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetConditionRequirement", "Set Switch Condition Requirement"));
	dialogueObject->Modify();
	switcherData->Conditions[conditionIndex].Conditions[requirementIndex] = conditionClass
		? NewObject<UDialogueCondition>(dialogueObject, const_cast<UClass*>(conditionClass), NAME_None, RF_Transactional)
		: nullptr;
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphSwitcherNode::RefreshOutputConnections()
{
	for (UEdGraphPin* pin : Pins)
	{
		if (pin && pin->Direction == EGPD_Output)
		{
			SynchronizeOutput(pin);
		}
	}
}

UDialogueObject* UDialogueGraphSwitcherNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphSwitcherNode::SynchronizeOutput(UEdGraphPin* pin)
{
	FDialogueSwitcher* switcherData = GetSwitcherData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	const FString pinName = pin ? pin->PinName.ToString() : FString();
	const FString prefix(TEXT("Condition_"));
	if (!switcherData || !dialogueObject || !pin || !pinName.StartsWith(prefix))
	{
		return;
	}

	const int32 conditionIndex = FCString::Atoi(*pinName.RightChop(prefix.Len()));
	if (!switcherData->Conditions.IsValidIndex(conditionIndex))
	{
		return;
	}

	const FDialogueGraphResolvedConnection resolvedConnection = DialogueGraphUtilities::ResolveConnection(pin);
	FDialogueSwitcherCondition& condition = switcherData->Conditions[conditionIndex];
	if (condition.NextNode != resolvedConnection.NextNodeId || condition.Actions != resolvedConnection.Actions)
	{
		dialogueObject->Modify();
		condition.NextNode = resolvedConnection.NextNodeId;
		condition.Actions = resolvedConnection.Actions;
		dialogueObject->MarkPackageDirty();
	}
}

void UDialogueGraphSwitcherNode::RefreshSourceNodes() const
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
			else if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(node);
				switcherNode && switcherNode != this)
			{
				switcherNode->RefreshOutputConnections();
			}
			else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(node))
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

void UDialogueGraphSwitcherNode::NotifySwitcherChanged(bool bReconstructPins)
{
	Modify();
	if (bReconstructPins)
	{
		ReconstructNode();
	}
	RefreshOutputConnections();
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
