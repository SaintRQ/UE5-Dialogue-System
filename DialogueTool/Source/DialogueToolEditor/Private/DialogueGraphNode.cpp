// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphNode.h"

#include "DialogueCondition.h"
#include "DialogueGraphUtilities.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphNode"

namespace
{
	const FName pinCategory(TEXT("DialogueFlow"));
	const FName inputPinName(TEXT("Input"));
	const FName defaultOutputPinName(TEXT("Output"));

	FName GetResponsePinName(int32 responseIndex)
	{
		return FName(*FString::Printf(TEXT("Response_%d"), responseIndex));
	}
}

void UDialogueGraphNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, pinCategory, inputPinName);
	inputPin->bDefaultValueIsIgnored = true;

	const FDialogueNode* dialogueData = GetDialogueData();
	if (!dialogueData || dialogueData->Response.IsEmpty())
	{
		CreatePin(EGPD_Output, pinCategory, defaultOutputPinName);
		return;
	}

	for (int32 responseIndex = 0; responseIndex < dialogueData->Response.Num(); ++responseIndex)
	{
		CreatePin(EGPD_Output, pinCategory, GetResponsePinName(responseIndex));
	}
}

void UDialogueGraphNode::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();

	if (DialogueNodeId != 0)
	{
		return;
	}

	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		DialogueNodeId = dialogueObject->GenerateUniqueId();
		dialogueObject->AddDialogueNode(DialogueNodeId);
	}
}

void UDialogueGraphNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin)
	{
		UEdGraphPin* targetPin = fromPin->Direction == EGPD_Output ? GetInputPin() : GetDefaultOutputPin();
		GetSchema()->TryCreateConnection(fromPin, targetPin);
	}
}

void UDialogueGraphNode::PrepareForCopying()
{
	Super::PrepareForCopying();

	if (const FDialogueNode* dialogueData = GetDialogueData())
	{
		ClipboardDialogueData = *dialogueData;
		HasClipboardDialogueData = true;
	}
}

void UDialogueGraphNode::PostPasteNode()
{
	Super::PostPasteNode();

	PastedFromDialogueNodeId = DialogueNodeId;
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		Modify();
		DialogueNodeId = dialogueObject->GenerateUniqueId();
		FDialogueNode& dialogueData = dialogueObject->AddDialogueNode(DialogueNodeId);
		dialogueData = HasClipboardDialogueData ? ClipboardDialogueData : FDialogueNode();
		if (dialogueData.RootText.IsEmpty())
		{
			dialogueData.RootText.Add(FText::GetEmpty());
		}
		for (FDialogueResponse& response : dialogueData.Response)
		{
			for (TObjectPtr<UDialogueCondition>& condition : response.Conditions)
			{
				if (condition)
				{
					condition = DuplicateObject<UDialogueCondition>(condition.Get(), dialogueObject);
				}
			}
		}
	}

	FinishCopying();
}

void UDialogueGraphNode::ReconstructNode()
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
		if (!newPin && linkedPin.Key == defaultOutputPinName)
		{
			newPin = GetResponseOutputPin(0);
		}

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

void UDialogueGraphNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);

	if (!pin || pin->Direction != EGPD_Output)
	{
		return;
	}

	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueData || !dialogueObject)
	{
		return;
	}

	int64* storedNextNodeId = nullptr;
	TArray<TObjectPtr<UDialogueAction>>* storedActions = nullptr;
	if (pin->PinName == defaultOutputPinName)
	{
		storedNextNodeId = &dialogueData->NextNode;
		storedActions = &dialogueData->Actions;
	}
	else
	{
		const FString pinName = pin->PinName.ToString();
		const FString prefix(TEXT("Response_"));
		if (pinName.StartsWith(prefix))
		{
			const int32 responseIndex = FCString::Atoi(*pinName.RightChop(prefix.Len()));
			if (dialogueData->Response.IsValidIndex(responseIndex))
			{
				storedNextNodeId = &dialogueData->Response[responseIndex].NextNode;
				storedActions = &dialogueData->Response[responseIndex].Actions;
			}
		}
	}

	if (!storedNextNodeId || !storedActions)
	{
		return;
	}

	const FDialogueGraphResolvedConnection resolvedConnection = DialogueGraphUtilities::ResolveConnection(pin);
	if (*storedNextNodeId != resolvedConnection.NextNodeId || *storedActions != resolvedConnection.Actions)
	{
		dialogueObject->Modify();
		*storedNextNodeId = resolvedConnection.NextNodeId;
		*storedActions = resolvedConnection.Actions;
		dialogueObject->MarkPackageDirty();
	}
}

void UDialogueGraphNode::NodeConnectionListChanged()
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

void UDialogueGraphNode::DestroyNode()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		dialogueObject->RemoveDialogueNode(DialogueNodeId);
	}

	Super::DestroyNode();
}

FText UDialogueGraphNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "TOPIC");
}

FText UDialogueGraphNode::GetTooltipText() const
{
	return LOCTEXT("NodeTooltip", "Dialogue topic text and responses that lead to other flow nodes.");
}

FDialogueNode* UDialogueGraphNode::GetDialogueData()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueNode(DialogueNodeId);
	}

	return nullptr;
}

const FDialogueNode* UDialogueGraphNode::GetDialogueData() const
{
	if (const UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueNode(DialogueNodeId);
	}

	return nullptr;
}

UEdGraphPin* UDialogueGraphNode::GetInputPin() const
{
	return FindPin(inputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphNode::GetDefaultOutputPin() const
{
	return FindPin(defaultOutputPinName, EGPD_Output);
}

UEdGraphPin* UDialogueGraphNode::GetResponseOutputPin(int32 responseIndex) const
{
	return FindPin(GetResponsePinName(responseIndex), EGPD_Output);
}

int64 UDialogueGraphNode::GetDialogueNodeId() const
{
	return DialogueNodeId;
}

int64 UDialogueGraphNode::GetPastedFromDialogueNodeId() const
{
	return PastedFromDialogueNodeId;
}

void UDialogueGraphNode::FinishCopying()
{
	ClipboardDialogueData = FDialogueNode();
	HasClipboardDialogueData = false;
}

void UDialogueGraphNode::RemapPastedConnections(const TMap<int64, int64>& pastedNodeIds)
{
	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueData || !dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	const auto remapNodeId = [&pastedNodeIds](int64& nextNodeId)
	{
		if (const int64* pastedNodeId = pastedNodeIds.Find(nextNodeId))
		{
			nextNodeId = *pastedNodeId;
		}
		else
		{
			nextNodeId = -1;
		}
	};

	remapNodeId(dialogueData->NextNode);
	for (FDialogueResponse& response : dialogueData->Response)
	{
		remapNodeId(response.NextNode);
	}

	NotifyDialogueChanged(false);
}

void UDialogueGraphNode::AddRootText()
{
	if (FDialogueNode* dialogueData = GetDialogueData())
	{
		const FScopedTransaction transaction(LOCTEXT("AddRootText", "Add Dialogue Text"));
		GetDialogueObject()->Modify();
		dialogueData->RootText.Add(FText::GetEmpty());
		NotifyDialogueChanged(false);
	}
}

void UDialogueGraphNode::RemoveRootText(int32 textIndex)
{
	FDialogueNode* dialogueData = GetDialogueData();
	if (!dialogueData || dialogueData->RootText.Num() <= 1 || !dialogueData->RootText.IsValidIndex(textIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveRootText", "Remove Dialogue Text"));
	GetDialogueObject()->Modify();
	dialogueData->RootText.RemoveAt(textIndex);
	NotifyDialogueChanged(false);
}

void UDialogueGraphNode::SetRootText(int32 textIndex, const FText& text)
{
	FDialogueNode* dialogueData = GetDialogueData();
	if (!dialogueData || !dialogueData->RootText.IsValidIndex(textIndex) || dialogueData->RootText[textIndex].EqualTo(text))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetRootText", "Edit Dialogue Text"));
	GetDialogueObject()->Modify();
	dialogueData->RootText[textIndex] = text;
	NotifyDialogueChanged(false);
}

void UDialogueGraphNode::AddResponse()
{
	if (FDialogueNode* dialogueData = GetDialogueData())
	{
		const FScopedTransaction transaction(LOCTEXT("AddResponse", "Add Dialogue Response"));
		GetDialogueObject()->Modify();
		const int32 finishIndex = dialogueData->Response.IndexOfByPredicate(
			[](const FDialogueResponse& response)
			{
				return response.FinishDialogue;
			});
		const int32 responseIndex = finishIndex == INDEX_NONE ? dialogueData->Response.Num() : finishIndex;
		for (int32 oldIndex = dialogueData->Response.Num() - 1; oldIndex >= responseIndex; --oldIndex)
		{
			if (UEdGraphPin* shiftedPin = GetResponseOutputPin(oldIndex))
			{
				shiftedPin->PinName = GetResponsePinName(oldIndex + 1);
			}
		}

		FDialogueResponse& response = dialogueData->Response.InsertDefaulted_GetRef(responseIndex);
		if (dialogueData->Response.Num() == 1)
		{
			response.NextNode = dialogueData->NextNode;
			response.Actions = MoveTemp(dialogueData->Actions);
			dialogueData->NextNode = -1;
		}
		NotifyDialogueChanged(true);
	}
}

void UDialogueGraphNode::AddFinishResponse()
{
	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueData || !dialogueObject || dialogueData->Response.ContainsByPredicate(
		[](const FDialogueResponse& response)
		{
			return response.FinishDialogue;
		}))
	{
		return;
	}

	const FScopedTransaction transaction(dialogueObject->IsA<UDialogueLibraryObject>()
		? LOCTEXT("AddReturnResponse", "Add Dialogue Return Response")
		: LOCTEXT("AddFinishResponse", "Add Finish Dialogue Response"));
	dialogueObject->Modify();
	UEdGraphPin* defaultOutputPin = GetDefaultOutputPin();
	if (defaultOutputPin && !defaultOutputPin->LinkedTo.IsEmpty()
		&& !DialogueGraphUtilities::IsValidFinishResponseTarget(defaultOutputPin->LinkedTo[0]->GetOwningNode()))
	{
		defaultOutputPin->BreakAllPinLinks();
	}

	FDialogueResponse& response = dialogueData->Response.AddDefaulted_GetRef();
	response.FinishDialogue = true;
	if (dialogueData->Response.Num() == 1)
	{
		response.NextNode = dialogueData->NextNode;
		response.Actions = MoveTemp(dialogueData->Actions);
		dialogueData->NextNode = -1;
	}
	NotifyDialogueChanged(true);
}

void UDialogueGraphNode::RemoveResponse(int32 responseIndex)
{
	FDialogueNode* dialogueData = GetDialogueData();
	if (!dialogueData || !dialogueData->Response.IsValidIndex(responseIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveResponse", "Remove Dialogue Response"));
	GetDialogueObject()->Modify();

	if (UEdGraphPin* removedPin = GetResponseOutputPin(responseIndex))
	{
		removedPin->BreakAllPinLinks();
		RemovePin(removedPin);
	}

	for (int32 oldIndex = responseIndex + 1; oldIndex < dialogueData->Response.Num(); ++oldIndex)
	{
		if (UEdGraphPin* shiftedPin = GetResponseOutputPin(oldIndex))
		{
			shiftedPin->PinName = GetResponsePinName(oldIndex - 1);
		}
	}

	dialogueData->Response.RemoveAt(responseIndex);
	NotifyDialogueChanged(true);
}

void UDialogueGraphNode::SetResponseText(int32 responseIndex, const FText& text)
{
	FDialogueNode* dialogueData = GetDialogueData();
	if (!dialogueData || !dialogueData->Response.IsValidIndex(responseIndex)
		|| dialogueData->Response[responseIndex].FinishDialogue
		|| dialogueData->Response[responseIndex].Response.EqualTo(text))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetResponseText", "Edit Dialogue Response"));
	GetDialogueObject()->Modify();
	dialogueData->Response[responseIndex].Response = text;
	NotifyDialogueChanged(false);
}

void UDialogueGraphNode::ToggleResponseAlwaysVisible(int32 responseIndex)
{
	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueData || !dialogueObject || !dialogueData->Response.IsValidIndex(responseIndex)
		|| dialogueData->Response[responseIndex].FinishDialogue)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("ToggleResponseAlwaysVisible", "Toggle Response Always Visible"));
	dialogueObject->Modify();
	dialogueData->Response[responseIndex].AlwaysVisible = !dialogueData->Response[responseIndex].AlwaysVisible;
	NotifyDialogueChanged(false);
}

void UDialogueGraphNode::AddResponseCondition(int32 responseIndex)
{
	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueData || !dialogueObject || !dialogueData->Response.IsValidIndex(responseIndex)
		|| dialogueData->Response[responseIndex].FinishDialogue)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("AddResponseCondition", "Add Dialogue Response Condition"));
	dialogueObject->Modify();
	dialogueData->Response[responseIndex].Conditions.Add(nullptr);
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphNode::RemoveResponseCondition(int32 responseIndex, int32 conditionIndex)
{
	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueData || !dialogueObject || !dialogueData->Response.IsValidIndex(responseIndex)
		|| dialogueData->Response[responseIndex].FinishDialogue
		|| !dialogueData->Response[responseIndex].Conditions.IsValidIndex(conditionIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveResponseCondition", "Remove Dialogue Response Condition"));
	dialogueObject->Modify();
	dialogueData->Response[responseIndex].Conditions.RemoveAt(conditionIndex);
	dialogueObject->MarkPackageDirty();
}

void UDialogueGraphNode::SetResponseConditionClass(
	int32 responseIndex,
	int32 conditionIndex,
	const UClass* conditionClass)
{
	FDialogueNode* dialogueData = GetDialogueData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (conditionClass && (!conditionClass->IsChildOf(UDialogueCondition::StaticClass())
		|| conditionClass->HasAnyClassFlags(CLASS_Abstract)))
	{
		return;
	}

	UDialogueCondition* currentCondition = dialogueData && dialogueData->Response.IsValidIndex(responseIndex)
		&& dialogueData->Response[responseIndex].Conditions.IsValidIndex(conditionIndex)
		? dialogueData->Response[responseIndex].Conditions[conditionIndex].Get()
		: nullptr;
	if (!dialogueData || !dialogueObject || !dialogueData->Response.IsValidIndex(responseIndex)
		|| dialogueData->Response[responseIndex].FinishDialogue
		|| !dialogueData->Response[responseIndex].Conditions.IsValidIndex(conditionIndex)
		|| (currentCondition ? currentCondition->GetClass() : nullptr) == conditionClass)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetResponseCondition", "Set Dialogue Response Condition"));
	dialogueObject->Modify();
	dialogueData->Response[responseIndex].Conditions[conditionIndex] = conditionClass
		? NewObject<UDialogueCondition>(dialogueObject, const_cast<UClass*>(conditionClass), NAME_None, RF_Transactional)
		: nullptr;
	dialogueObject->MarkPackageDirty();
}

UDialogueObject* UDialogueGraphNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphNode::NotifyDialogueChanged(bool bReconstructPins)
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
