// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphInitNode.h"

#include "DialogueCondition.h"
#include "DialogueGraphUtilities.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "Monologue/MonologueObject.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphInitNode"

namespace
{
	const FName initPinCategory(TEXT("DialogueFlow"));

	FName GetInitPinName(int32 initIndex)
	{
		return FName(*FString::Printf(TEXT("Init_%d"), initIndex));
	}
}

void UDialogueGraphInitNode::AllocateDefaultPins()
{
	const TArray<FDialogueInit>* initData = GetInitData();
	if (!initData)
	{
		return;
	}

	for (int32 initIndex = 0; initIndex < initData->Num(); ++initIndex)
	{
		CreatePin(EGPD_Output, initPinCategory, GetInitPinName(initIndex));
	}
}

void UDialogueGraphInitNode::ReconstructNode()
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
		UEdGraphPin* newPin = FindPin(linkedPin.Key, EGPD_Output);
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

void UDialogueGraphInitNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);
	if (!pin || pin->Direction != EGPD_Output)
	{
		return;
	}

	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	const FString pinName = pin->PinName.ToString();
	const FString prefix(TEXT("Init_"));
	if (!initData || !dialogueObject || !pinName.StartsWith(prefix))
	{
		return;
	}

	const int32 initIndex = FCString::Atoi(*pinName.RightChop(prefix.Len()));
	if (!initData->IsValidIndex(initIndex))
	{
		return;
	}

	const FDialogueGraphResolvedConnection resolvedConnection = DialogueGraphUtilities::ResolveConnection(pin);
	FDialogueInit& init = (*initData)[initIndex];
	if (init.NextNode != resolvedConnection.NextNodeId || init.Actions != resolvedConnection.Actions)
	{
		dialogueObject->Modify();
		init.NextNode = resolvedConnection.NextNodeId;
		init.Actions = resolvedConnection.Actions;
		dialogueObject->MarkPackageDirty();
	}
}

void UDialogueGraphInitNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	for (UEdGraphPin* pin : Pins)
	{
		if (pin && pin->Direction == EGPD_Output)
		{
			PinConnectionListChanged(pin);
		}
	}
}

bool UDialogueGraphInitNode::CanUserDeleteNode() const
{
	return false;
}

bool UDialogueGraphInitNode::CanDuplicateNode() const
{
	return false;
}

FText UDialogueGraphInitNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	const UDialogueObject* dialogueObject = GetDialogueObject();
	return dialogueObject && dialogueObject->IsA<UDialogueLibraryObject>()
		? LOCTEXT("LibraryNodeTitle", "LIBRARY START")
		: UMonologueObject::IsMonologueAsset(dialogueObject)
			? LOCTEXT("MonologueNodeTitle", "MONOLOGUE START")
			: LOCTEXT("NodeTitle", "DIALOGUE START");
}

FText UDialogueGraphInitNode::GetTooltipText() const
{
	const UDialogueObject* dialogueObject = GetDialogueObject();
	return dialogueObject && dialogueObject->IsA<UDialogueLibraryObject>()
		? LOCTEXT(
			"LibraryNodeTooltip",
			"Defines the entry branches of this dialogue library.\n"
			"Conditional branches are checked from top to bottom; Default is used when none match.\n"
			"Its actions execute in order before dialogue flow continues through the corresponding output.")
		: UMonologueObject::IsMonologueAsset(dialogueObject)
			? LOCTEXT(
				"MonologueNodeTooltip",
				"Defines the entry branches used when this monologue starts.\n"
				"Conditional branches are checked from top to bottom; Default is used when none match.\n"
				"Its actions execute in order before monologue flow continues through the corresponding output.")
			: LOCTEXT(
				"NodeTooltip",
				"Defines the entry branches used when this dialogue starts.\n"
				"Conditional branches are checked from top to bottom; Default is used when none match.\n"
				"Its actions execute in order before dialogue flow continues through the corresponding output.");
}

TArray<FDialogueInit>* UDialogueGraphInitNode::GetInitData()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return &dialogueObject->GetDialogueInitData();
	}

	return nullptr;
}

const TArray<FDialogueInit>* UDialogueGraphInitNode::GetInitData() const
{
	if (const UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return &dialogueObject->GetDialogueInitData();
	}

	return nullptr;
}

UEdGraphPin* UDialogueGraphInitNode::GetInitOutputPin(int32 initIndex) const
{
	return FindPin(GetInitPinName(initIndex), EGPD_Output);
}

UEdGraphPin* UDialogueGraphInitNode::GetDefaultOutputPin() const
{
	const TArray<FDialogueInit>* initData = GetInitData();
	return initData && !initData->IsEmpty() ? GetInitOutputPin(initData->Num() - 1) : nullptr;
}

void UDialogueGraphInitNode::AddInit()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		const FScopedTransaction transaction(LOCTEXT("AddInit", "Add Dialogue Start"));
		dialogueObject->Modify();
		Modify();
		TArray<FDialogueInit>& initData = dialogueObject->GetDialogueInitData();
		if (initData.IsEmpty())
		{
			initData.AddDefaulted_GetRef().Name = TEXT("Default");
		}
		const int32 defaultIndex = initData.Num() - 1;
		if (UEdGraphPin* defaultPin = GetDefaultOutputPin())
		{
			defaultPin->PinName = GetInitPinName(defaultIndex + 1);
		}
		FDialogueInit& init = initData.InsertDefaulted_GetRef(defaultIndex);
		init.Name = FName(*FString::Printf(TEXT("Condition %d"), initData.Num() - 1));
		NotifyInitChanged(true);
	}
}

void UDialogueGraphInitNode::RemoveInit(int32 initIndex)
{
	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!initData || !dialogueObject || initData->Num() <= 1 || !initData->IsValidIndex(initIndex)
		|| initIndex == initData->Num() - 1)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveInit", "Remove Dialogue Start"));
	dialogueObject->Modify();
	Modify();
	if (UEdGraphPin* removedPin = GetInitOutputPin(initIndex))
	{
		removedPin->BreakAllPinLinks();
		RemovePin(removedPin);
	}

	for (int32 oldIndex = initIndex + 1; oldIndex < initData->Num(); ++oldIndex)
	{
		if (UEdGraphPin* shiftedPin = GetInitOutputPin(oldIndex))
		{
			shiftedPin->PinName = GetInitPinName(oldIndex - 1);
		}
	}

	initData->RemoveAt(initIndex);
	NotifyInitChanged(true);
}

void UDialogueGraphInitNode::SetInitName(int32 initIndex, FName name)
{
	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!initData || !dialogueObject || !initData->IsValidIndex(initIndex) || (*initData)[initIndex].Name == name)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetInitName", "Set Dialogue Start Name"));
	dialogueObject->Modify();
	(*initData)[initIndex].Name = name;
	NotifyInitChanged(false);
}

void UDialogueGraphInitNode::AddInitCondition(int32 initIndex)
{
	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!initData || !dialogueObject || !initData->IsValidIndex(initIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("AddInitCondition", "Add Dialogue Start Condition"));
	dialogueObject->Modify();
	(*initData)[initIndex].Conditions.Add(nullptr);
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphInitNode::RemoveInitCondition(int32 initIndex, int32 conditionIndex)
{
	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!initData || !dialogueObject || !initData->IsValidIndex(initIndex)
		|| !(*initData)[initIndex].Conditions.IsValidIndex(conditionIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveInitCondition", "Remove Dialogue Start Condition"));
	dialogueObject->Modify();
	(*initData)[initIndex].Conditions.RemoveAt(conditionIndex);
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphInitNode::SetInitConditionClass(
	int32 initIndex,
	int32 conditionIndex,
	const UClass* conditionClass)
{
	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (conditionClass && (!conditionClass->IsChildOf(UDialogueCondition::StaticClass())
		|| conditionClass->HasAnyClassFlags(CLASS_Abstract)))
	{
		return;
	}

	UDialogueCondition* currentCondition = initData && initData->IsValidIndex(initIndex)
		&& (*initData)[initIndex].Conditions.IsValidIndex(conditionIndex)
		? (*initData)[initIndex].Conditions[conditionIndex].Get()
		: nullptr;
	if (!initData || !dialogueObject || !initData->IsValidIndex(initIndex)
		|| !(*initData)[initIndex].Conditions.IsValidIndex(conditionIndex)
		|| (currentCondition ? currentCondition->GetClass() : nullptr) == conditionClass)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetInitCondition", "Set Dialogue Start Condition"));
	dialogueObject->Modify();
	(*initData)[initIndex].Conditions[conditionIndex] = conditionClass
		? NewObject<UDialogueCondition>(dialogueObject, const_cast<UClass*>(conditionClass), NAME_None, RF_Transactional)
		: nullptr;
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphInitNode::SetInitConditionMode(
	const int32 InitIndex,
	const EDialogueConditionMode ConditionMode)
{
	TArray<FDialogueInit>* initData = GetInitData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!initData || !dialogueObject || !initData->IsValidIndex(InitIndex)
		|| (*initData)[InitIndex].ConditionMode == ConditionMode)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetInitConditionMode", "Set Dialogue Start Condition Mode"));
	dialogueObject->Modify();
	(*initData)[InitIndex].ConditionMode = ConditionMode;
	dialogueObject->MarkPackageDirty();
}

UDialogueObject* UDialogueGraphInitNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphInitNode::NotifyInitChanged(bool bReconstructPins)
{
	Modify();
	if (bReconstructPins)
	{
		ReconstructNode();
	}

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
