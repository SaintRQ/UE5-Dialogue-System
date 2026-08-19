// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphFinishNode.h"

#include "DialogueLibraryObject.h"
#include "EdGraph/EdGraph.h"

#define LOCTEXT_NAMESPACE "DialogueGraphFinishNode"

namespace
{
	const FName finishPinCategory(TEXT("DialogueFlow"));
	const FName finishInputPinName(TEXT("Input"));
}

void UDialogueGraphFinishNode::AllocateDefaultPins()
{
	UEdGraphPin* inputPin = CreatePin(EGPD_Input, finishPinCategory, finishInputPinName);
	inputPin->bDefaultValueIsIgnored = true;
}

void UDialogueGraphFinishNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin && fromPin->Direction == EGPD_Output)
	{
		GetSchema()->TryCreateConnection(fromPin, GetInputPin());
	}
}

FText UDialogueGraphFinishNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return IsReturnNode()
		? LOCTEXT("ReturnNodeTitle", "RETURN")
		: LOCTEXT("NodeTitle", "FINISH DIALOGUE");
}

FText UDialogueGraphFinishNode::GetTooltipText() const
{
	return IsReturnNode()
		? LOCTEXT("ReturnNodeTooltip", "Returns to the calling dialogue after all preceding actions execute.")
		: LOCTEXT("NodeTooltip", "Finishes the active dialogue after all preceding actions execute.");
}

UEdGraphPin* UDialogueGraphFinishNode::GetInputPin() const
{
	return FindPin(finishInputPinName, EGPD_Input);
}

bool UDialogueGraphFinishNode::IsReturnNode() const
{
	return GetGraph() && GetGraph()->GetTypedOuter<UDialogueLibraryObject>();
}

#undef LOCTEXT_NAMESPACE
