// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphFinishNode.h"

#include "DialogueLibraryObject.h"
#include "EdGraph/EdGraph.h"
#include "Monologue/MonologueObject.h"

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
		: IsMonologueNode()
			? LOCTEXT("MonologueNodeTitle", "FINISH MONOLOGUE")
			: LOCTEXT("NodeTitle", "FINISH DIALOGUE");
}

FText UDialogueGraphFinishNode::GetTooltipText() const
{
	return IsReturnNode()
		? LOCTEXT(
			"ReturnNodeTooltip",
			"Completes the current dialogue library and returns to the dialogue that entered it.\n"
			"The Transit node then executes its Return actions and continues through its Return output.")
		: IsMonologueNode()
			? LOCTEXT(
				"MonologueNodeTooltip",
				"Finishes the active monologue after all preceding actions have executed.")
			: LOCTEXT(
				"NodeTooltip",
				"Finishes the active root dialogue after all preceding actions have executed.\n"
				"The dialogue manager updates the cache, clears playback state, and broadcasts the finish event.");
}

UEdGraphPin* UDialogueGraphFinishNode::GetInputPin() const
{
	return FindPin(finishInputPinName, EGPD_Input);
}

bool UDialogueGraphFinishNode::IsReturnNode() const
{
	return GetGraph() && GetGraph()->GetTypedOuter<UDialogueLibraryObject>();
}

bool UDialogueGraphFinishNode::IsMonologueNode() const
{
	return GetGraph() && UMonologueObject::IsMonologueAsset(GetGraph()->GetOuter());
}

#undef LOCTEXT_NAMESPACE
