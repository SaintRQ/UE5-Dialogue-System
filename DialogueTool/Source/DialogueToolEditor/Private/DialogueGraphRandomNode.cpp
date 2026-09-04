// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphRandomNode.h"

#include "DialogueAction.h"
#include "DialogueGraphInitNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphSkipTextNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueGraphUtilities.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphRandomNode"

namespace
{
	const FName randomPinCategory(TEXT("DialogueFlow"));
	const FName randomInputPinName(TEXT("Input"));

	FName GetRandomPinName(const int32 outputIndex)
	{
		return FName(*FString::Printf(TEXT("Output_%d"), outputIndex));
	}
}

void UDialogueGraphRandomNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, randomPinCategory, randomInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
	const FDialogueRandom* randomData = GetRandomData();
	if (!randomData)
	{
		return;
	}

	for (int32 outputIndex = 0; outputIndex < randomData->Outputs.Num(); ++outputIndex)
	{
		CreatePin(EGPD_Output, randomPinCategory, GetRandomPinName(outputIndex));
	}
}

void UDialogueGraphRandomNode::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (RandomNodeId != 0)
	{
		return;
	}

	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		RandomNodeId = dialogueObject->GenerateUniqueId();
		dialogueObject->AddDialogueRandom(RandomNodeId);
	}
}

void UDialogueGraphRandomNode::AutowireNewNode(UEdGraphPin* FromPin)
{
	if (FromPin)
	{
		UEdGraphPin* targetPin = FromPin->Direction == EGPD_Output ? GetInputPin() : GetRandomOutputPin(0);
		if (targetPin)
		{
			GetSchema()->TryCreateConnection(FromPin, targetPin);
		}
	}
}

void UDialogueGraphRandomNode::PrepareForCopying()
{
	Super::PrepareForCopying();
	if (const FDialogueRandom* randomData = GetRandomData())
	{
		ClipboardRandomData = *randomData;
		HasClipboardRandomData = true;
	}
}

void UDialogueGraphRandomNode::PostPasteNode()
{
	Super::PostPasteNode();
	PastedFromRandomNodeId = RandomNodeId;
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	Modify();
	RandomNodeId = dialogueObject->GenerateUniqueId();
	FDialogueRandom& randomData = dialogueObject->AddDialogueRandom(RandomNodeId);
	randomData = HasClipboardRandomData ? ClipboardRandomData : FDialogueRandom();
	randomData.EnsureMinimumOutputs();
	for (FDialogueRandomOutput& output : randomData.Outputs)
	{
		for (TObjectPtr<UDialogueAction>& action : output.Actions)
		{
			if (action)
			{
				action = DuplicateObject<UDialogueAction>(action.Get(), dialogueObject);
			}
		}
	}
	FinishCopying();
}

void UDialogueGraphRandomNode::ReconstructNode()
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

void UDialogueGraphRandomNode::PinConnectionListChanged(UEdGraphPin* Pin)
{
	Super::PinConnectionListChanged(Pin);
	if (!Pin)
	{
		return;
	}

	if (Pin->Direction == EGPD_Output)
	{
		SynchronizeOutput(Pin);
	}
	else
	{
		RefreshSourceNodes();
	}
}

void UDialogueGraphRandomNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	RefreshOutputConnections();
	RefreshSourceNodes();
}

void UDialogueGraphRandomNode::DestroyNode()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		dialogueObject->Modify();
		dialogueObject->RemoveDialogueRandom(RandomNodeId);
	}
	Super::DestroyNode();
	RefreshSourceNodes();
}

FText UDialogueGraphRandomNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("NodeTitle", "RANDOM");
}

FText UDialogueGraphRandomNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Randomly selects one outgoing branch with equal probability.\n"
		"At least two outputs are always available.");
}

FDialogueRandom* UDialogueGraphRandomNode::GetRandomData()
{
	if (UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueRandom(RandomNodeId);
	}
	return nullptr;
}

const FDialogueRandom* UDialogueGraphRandomNode::GetRandomData() const
{
	if (const UDialogueObject* dialogueObject = GetDialogueObject())
	{
		return dialogueObject->FindDialogueRandom(RandomNodeId);
	}
	return nullptr;
}

UEdGraphPin* UDialogueGraphRandomNode::GetInputPin() const
{
	return FindPin(randomInputPinName, EGPD_Input);
}

UEdGraphPin* UDialogueGraphRandomNode::GetRandomOutputPin(const int32 OutputIndex) const
{
	return FindPin(GetRandomPinName(OutputIndex), EGPD_Output);
}

int64 UDialogueGraphRandomNode::GetRandomNodeId() const
{
	return RandomNodeId;
}

int64 UDialogueGraphRandomNode::GetPastedFromRandomNodeId() const
{
	return PastedFromRandomNodeId;
}

void UDialogueGraphRandomNode::FinishCopying()
{
	ClipboardRandomData = FDialogueRandom();
	HasClipboardRandomData = false;
}

void UDialogueGraphRandomNode::RemapPastedConnections(const TMap<int64, int64>& PastedNodeIds)
{
	FDialogueRandom* randomData = GetRandomData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!randomData || !dialogueObject)
	{
		return;
	}

	dialogueObject->Modify();
	for (FDialogueRandomOutput& output : randomData->Outputs)
	{
		if (const int64* pastedNodeId = PastedNodeIds.Find(output.NextNode))
		{
			output.NextNode = *pastedNodeId;
		}
		else
		{
			output.NextNode = -1;
		}
	}
}

void UDialogueGraphRandomNode::AddOutput()
{
	FDialogueRandom* randomData = GetRandomData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!randomData || !dialogueObject)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("AddOutput", "Add Random Output"));
	dialogueObject->Modify();
	Modify();
	randomData->Outputs.AddDefaulted();
	NotifyRandomChanged(true);
}

void UDialogueGraphRandomNode::RemoveOutput(const int32 OutputIndex)
{
	FDialogueRandom* randomData = GetRandomData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	if (!randomData || !dialogueObject || randomData->Outputs.Num() <= 2
		|| !randomData->Outputs.IsValidIndex(OutputIndex))
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RemoveOutput", "Remove Random Output"));
	dialogueObject->Modify();
	Modify();
	if (UEdGraphPin* removedPin = GetRandomOutputPin(OutputIndex))
	{
		removedPin->BreakAllPinLinks();
		RemovePin(removedPin);
	}
	for (int32 oldIndex = OutputIndex + 1; oldIndex < randomData->Outputs.Num(); ++oldIndex)
	{
		if (UEdGraphPin* shiftedPin = GetRandomOutputPin(oldIndex))
		{
			shiftedPin->PinName = GetRandomPinName(oldIndex - 1);
		}
	}
	randomData->Outputs.RemoveAt(OutputIndex);
	NotifyRandomChanged(true);
}

void UDialogueGraphRandomNode::RefreshOutputConnections()
{
	for (UEdGraphPin* pin : Pins)
	{
		if (pin && pin->Direction == EGPD_Output)
		{
			SynchronizeOutput(pin);
		}
	}
}

UDialogueObject* UDialogueGraphRandomNode::GetDialogueObject() const
{
	return GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
}

void UDialogueGraphRandomNode::SynchronizeOutput(UEdGraphPin* Pin)
{
	FDialogueRandom* randomData = GetRandomData();
	UDialogueObject* dialogueObject = GetDialogueObject();
	const FString pinName = Pin ? Pin->PinName.ToString() : FString();
	const FString prefix(TEXT("Output_"));
	if (!randomData || !dialogueObject || !Pin || !pinName.StartsWith(prefix))
	{
		return;
	}

	const int32 outputIndex = FCString::Atoi(*pinName.RightChop(prefix.Len()));
	if (!randomData->Outputs.IsValidIndex(outputIndex))
	{
		return;
	}

	const FDialogueGraphResolvedConnection resolvedConnection = DialogueGraphUtilities::ResolveConnection(Pin);
	FDialogueRandomOutput& output = randomData->Outputs[outputIndex];
	if (output.NextNode != resolvedConnection.NextNodeId || output.Actions != resolvedConnection.Actions)
	{
		dialogueObject->Modify();
		output.NextNode = resolvedConnection.NextNodeId;
		output.Actions = resolvedConnection.Actions;
		dialogueObject->MarkPackageDirty();
	}
}

void UDialogueGraphRandomNode::RefreshSourceNodes() const
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
			else if (UDialogueGraphRandomNode* randomNode = Cast<UDialogueGraphRandomNode>(node);
				randomNode && randomNode != this)
			{
				randomNode->RefreshOutputConnections();
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

void UDialogueGraphRandomNode::NotifyRandomChanged(const bool ReconstructPins)
{
	Modify();
	if (ReconstructPins)
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
