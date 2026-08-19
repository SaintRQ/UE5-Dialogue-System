// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphSchema.h"

#include "DialogueGraphActionNode.h"
#include "DialogueGraphFinishNode.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphRerouteNode.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueGraphUtilities.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "ConnectionDrawingPolicy.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphSchema"

namespace
{
	class FDialogueConnectionDrawingPolicy final : public FConnectionDrawingPolicy
	{
	public:

		FDialogueConnectionDrawingPolicy(
			const int32 backLayerId,
			const int32 frontLayerId,
			const float zoomFactor,
			const FSlateRect& clippingRect,
			FSlateWindowElementList& drawElements)
			: FConnectionDrawingPolicy(
				backLayerId,
				frontLayerId,
				zoomFactor,
				clippingRect,
				drawElements)
		{
			ArrowImage = nullptr;
			ArrowRadius = FVector2D::ZeroVector;
		}

		virtual void DetermineWiringStyle(
			UEdGraphPin* outputPin,
			UEdGraphPin* inputPin,
			FConnectionParams& params) override
		{
			FConnectionDrawingPolicy::DetermineWiringStyle(outputPin, inputPin, params);
			if (UDialogueGraphRerouteNode* outputReroute = Cast<UDialogueGraphRerouteNode>(outputPin->GetOwningNode());
				outputReroute && ShouldReverseTangent(outputReroute))
			{
				params.StartDirection = EGPD_Input;
			}
			if (UDialogueGraphRerouteNode* inputReroute = inputPin
				? Cast<UDialogueGraphRerouteNode>(inputPin->GetOwningNode())
				: nullptr;
				inputReroute && ShouldReverseTangent(inputReroute))
			{
				params.EndDirection = EGPD_Output;
			}
		}

	private:

		bool FindPinCenter(UEdGraphPin* pin, FVector2f& outCenter) const
		{
			const TSharedPtr<SGraphPin>* pinWidget = PinToPinWidgetMap.Find(pin);
			if (!pinWidget || !PinGeometries)
			{
				return false;
			}

			const FArrangedWidget* pinGeometry = PinGeometries->Find(pinWidget->ToSharedRef());
			if (!pinGeometry)
			{
				return false;
			}

			outCenter = FGeometryHelper::CenterOf(pinGeometry->Geometry);
			return true;
		}

		bool GetAverageConnectedPosition(
			UDialogueGraphRerouteNode* rerouteNode,
			const EEdGraphPinDirection direction,
			FVector2f& outPosition) const
		{
			const UEdGraphPin* pin = direction == EGPD_Input
				? rerouteNode->GetInputPin()
				: rerouteNode->GetOutputPin();
			FVector2f position = FVector2f::ZeroVector;
			int32 positionCount = 0;
			for (UEdGraphPin* linkedPin : pin->LinkedTo)
			{
				FVector2f linkedPosition;
				if (FindPinCenter(linkedPin, linkedPosition))
				{
					position += linkedPosition;
					++positionCount;
				}
			}

			if (positionCount == 0)
			{
				return false;
			}

			outPosition = position / static_cast<float>(positionCount);
			return true;
		}

		bool ShouldReverseTangent(UDialogueGraphRerouteNode* rerouteNode)
		{
			if (const bool* reversed = ReversedReroutes.Find(rerouteNode))
			{
				return *reversed;
			}

			FVector2f inputPosition;
			FVector2f outputPosition;
			FVector2f centerPosition;
			const bool hasCenter = FindPinCenter(rerouteNode->GetOutputPin(), centerPosition);
			const bool hasInput = GetAverageConnectedPosition(rerouteNode, EGPD_Input, inputPosition);
			const bool hasOutput = GetAverageConnectedPosition(rerouteNode, EGPD_Output, outputPosition);
			bool reversed = false;
			if (hasInput && hasOutput)
			{
				reversed = outputPosition.X < inputPosition.X;
			}
			else if (hasCenter && hasInput)
			{
				reversed = centerPosition.X < inputPosition.X;
			}
			else if (hasCenter && hasOutput)
			{
				reversed = outputPosition.X < centerPosition.X;
			}

			ReversedReroutes.Add(rerouteNode, reversed);
			return reversed;
		}

		TMap<TObjectPtr<UDialogueGraphRerouteNode>, bool> ReversedReroutes;
	};
}

void UDialogueGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& contextMenuBuilder) const
{
	const bool bLibraryGraph = contextMenuBuilder.CurrentGraph
		&& contextMenuBuilder.CurrentGraph->GetTypedOuter<UDialogueLibraryObject>();
	const auto addTransitAction = [&contextMenuBuilder, bLibraryGraph]()
	{
		if (bLibraryGraph)
		{
			return;
		}

		const TSharedRef<FEdGraphSchemaAction_NewNode> transitAction = MakeShared<FEdGraphSchemaAction_NewNode>(
			FText::GetEmpty(),
			LOCTEXT("AddTransitNode", "Add Transit"),
			LOCTEXT("AddTransitNodeTooltip", "Enters a dialogue library and returns to this dialogue."),
			0);
		transitAction->NodeTemplate = NewObject<UDialogueGraphTransitNode>();
		contextMenuBuilder.AddAction(transitAction);
	};

	if (contextMenuBuilder.FromPin)
	{
		const bool bFinishResponseFlow = contextMenuBuilder.FromPin->Direction == EGPD_Output
			&& DialogueGraphUtilities::IsFinishResponseFlow(contextMenuBuilder.FromPin);
		if (!bFinishResponseFlow)
		{
			const TSharedRef<FEdGraphSchemaAction_NewNode> topicAction = MakeShared<FEdGraphSchemaAction_NewNode>(
				FText::GetEmpty(),
				LOCTEXT("AddTopicNodeFromPin", "Add Topic"),
				LOCTEXT("AddTopicNodeFromPinTooltip", "Adds and connects a dialogue topic."),
				0);
			topicAction->NodeTemplate = NewObject<UDialogueGraphNode>();
			contextMenuBuilder.AddAction(topicAction);
		}

		const TSharedRef<FEdGraphSchemaAction_NewNode> actionNodeAction = MakeShared<FEdGraphSchemaAction_NewNode>(
			FText::GetEmpty(),
			LOCTEXT("AddActionsNodeFromPin", "Add Actions"),
			LOCTEXT("AddActionsNodeFromPinTooltip", "Adds an action chain to this dialogue connection."),
			0);
		actionNodeAction->NodeTemplate = NewObject<UDialogueGraphActionNode>();
		contextMenuBuilder.AddAction(actionNodeAction);

		if (!bFinishResponseFlow)
		{
			const TSharedRef<FEdGraphSchemaAction_NewNode> switcherAction = MakeShared<FEdGraphSchemaAction_NewNode>(
				FText::GetEmpty(),
				LOCTEXT("AddSwitcherNodeFromPin", "Add Switch"),
				LOCTEXT("AddSwitcherNodeFromPinTooltip", "Adds a conditional dialogue switch."),
				0);
			switcherAction->NodeTemplate = NewObject<UDialogueGraphSwitcherNode>();
			contextMenuBuilder.AddAction(switcherAction);

			addTransitAction();
		}

		if (contextMenuBuilder.FromPin->Direction == EGPD_Output && !bFinishResponseFlow)
		{
			const TSharedRef<FEdGraphSchemaAction_NewNode> finishAction = MakeShared<FEdGraphSchemaAction_NewNode>(
				FText::GetEmpty(),
				bLibraryGraph
					? LOCTEXT("AddReturnNodeFromPin", "Add Return")
					: LOCTEXT("AddFinishNodeFromPin", "Add Finish Dialogue"),
				bLibraryGraph
					? LOCTEXT("AddReturnNodeFromPinTooltip", "Adds a node that returns to the calling dialogue.")
					: LOCTEXT("AddFinishNodeFromPinTooltip", "Adds and connects a terminal dialogue node."),
				0);
			finishAction->NodeTemplate = NewObject<UDialogueGraphFinishNode>();
			contextMenuBuilder.AddAction(finishAction);
		}

		const TSharedRef<FEdGraphSchemaAction_NewNode> rerouteAction = MakeShared<FEdGraphSchemaAction_NewNode>(
			FText::GetEmpty(),
			LOCTEXT("AddRerouteNode", "Add Reroute"),
			LOCTEXT("AddRerouteNodeTooltip", "Adds a control point for dialogue connections."),
			0);
		rerouteAction->NodeTemplate = NewObject<UDialogueGraphRerouteNode>();
		contextMenuBuilder.AddAction(rerouteAction);
		return;
	}

	const TSharedRef<FEdGraphSchemaAction_NewNode> topicAction = MakeShared<FEdGraphSchemaAction_NewNode>(
		FText::GetEmpty(),
		LOCTEXT("AddTopicNode", "Add Topic"),
		LOCTEXT("AddTopicNodeTooltip", "Adds a dialogue topic to the graph."),
		0);
	topicAction->NodeTemplate = NewObject<UDialogueGraphNode>();
	contextMenuBuilder.AddAction(topicAction);

	const TSharedRef<FEdGraphSchemaAction_NewNode> actionNodeAction = MakeShared<FEdGraphSchemaAction_NewNode>(
		FText::GetEmpty(),
		LOCTEXT("AddActionsNode", "Add Actions"),
		LOCTEXT("AddActionsNodeTooltip", "Adds an action chain node to the graph."),
		0);
	actionNodeAction->NodeTemplate = NewObject<UDialogueGraphActionNode>();
	contextMenuBuilder.AddAction(actionNodeAction);

	const TSharedRef<FEdGraphSchemaAction_NewNode> switcherAction = MakeShared<FEdGraphSchemaAction_NewNode>(
		FText::GetEmpty(),
		LOCTEXT("AddSwitcherNode", "Add Switch"),
		LOCTEXT("AddSwitcherNodeTooltip", "Adds a conditional dialogue switch."),
		0);
	switcherAction->NodeTemplate = NewObject<UDialogueGraphSwitcherNode>();
	contextMenuBuilder.AddAction(switcherAction);

	addTransitAction();

	const TSharedRef<FEdGraphSchemaAction_NewNode> finishAction = MakeShared<FEdGraphSchemaAction_NewNode>(
		FText::GetEmpty(),
		bLibraryGraph
			? LOCTEXT("AddReturnNode", "Add Return")
			: LOCTEXT("AddFinishNode", "Add Finish Dialogue"),
		bLibraryGraph
			? LOCTEXT("AddReturnNodeTooltip", "Adds a terminal node that returns to the calling dialogue.")
			: LOCTEXT("AddFinishNodeTooltip", "Adds a terminal node that finishes dialogue playback."),
		0);
	finishAction->NodeTemplate = NewObject<UDialogueGraphFinishNode>();
	contextMenuBuilder.AddAction(finishAction);
}

const FPinConnectionResponse UDialogueGraphSchema::CanCreateConnection(
	const UEdGraphPin* pinA,
	const UEdGraphPin* pinB) const
{
	if (!pinA || !pinB || pinA->GetOwningNode() == pinB->GetOwningNode())
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("SameNode", "A node cannot connect to itself."));
	}

	if (pinA->Direction == pinB->Direction)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("SameDirection", "Connect an output to an input."));
	}

	const UEdGraphPin* outputPin = pinA->Direction == EGPD_Output ? pinA : pinB;
	const UEdGraphPin* inputPin = outputPin == pinA ? pinB : pinA;
	if (DialogueGraphUtilities::IsFinishResponseFlow(outputPin)
		&& !DialogueGraphUtilities::IsValidFinishResponseTarget(inputPin->GetOwningNode()))
	{
		return FPinConnectionResponse(
			CONNECT_RESPONSE_DISALLOW,
			LOCTEXT(
				"InvalidFinishResponseTarget",
				"A terminal response can connect only through Actions nodes."));
	}

	if (outputPin->LinkedTo.Contains(inputPin))
	{
		return FPinConnectionResponse(
			CONNECT_RESPONSE_DISALLOW,
			LOCTEXT("AlreadyConnected", "These dialogue pins are already connected."));
	}

	if (!outputPin->LinkedTo.IsEmpty())
	{
		return FPinConnectionResponse(
			outputPin == pinA ? CONNECT_RESPONSE_BREAK_OTHERS_A : CONNECT_RESPONSE_BREAK_OTHERS_B,
			LOCTEXT("ReplaceConnection", "Replace the existing dialogue connection."));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, LOCTEXT("Connect", "Connect dialogue nodes."));
}

void UDialogueGraphSchema::OnPinConnectionDoubleCicked(
	UEdGraphPin* pinA,
	UEdGraphPin* pinB,
	const FVector2f& graphPosition) const
{
	if (!pinA || !pinB)
	{
		return;
	}

	UEdGraph* graph = pinA->GetOwningNode()->GetGraph();
	if (!graph || graph != pinB->GetOwningNode()->GetGraph() || !graph->bEditable)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("CreateRerouteNodeOnWire", "Create Dialogue Reroute Node"));
	graph->Modify();
	pinA->Modify();
	pinB->Modify();

	const FVector2f rerouteSize(42.0f, 24.0f);
	UDialogueGraphRerouteNode* rerouteNode = CastChecked<UDialogueGraphRerouteNode>(
		FEdGraphSchemaAction_NewNode::CreateNode(
			graph,
			nullptr,
			graphPosition - rerouteSize * 0.5f,
			NewObject<UDialogueGraphRerouteNode>()));

	pinA->BreakLinkTo(pinB);
	pinA->MakeLinkTo(pinA->Direction == EGPD_Output ? rerouteNode->GetInputPin() : rerouteNode->GetOutputPin());
	pinB->MakeLinkTo(pinB->Direction == EGPD_Output ? rerouteNode->GetInputPin() : rerouteNode->GetOutputPin());

	pinA->GetOwningNode()->PinConnectionListChanged(pinA);
	pinB->GetOwningNode()->PinConnectionListChanged(pinB);
	rerouteNode->PinConnectionListChanged(rerouteNode->GetInputPin());
	rerouteNode->PinConnectionListChanged(rerouteNode->GetOutputPin());
	graph->NotifyGraphChanged();

	if (UDialogueObject* dialogueObject = graph->GetTypedOuter<UDialogueObject>())
	{
		dialogueObject->MarkPackageDirty();
	}
}

FConnectionDrawingPolicy* UDialogueGraphSchema::CreateConnectionDrawingPolicy(
	const int32 backLayerId,
	const int32 frontLayerId,
	const float zoomFactor,
	const FSlateRect& clippingRect,
	FSlateWindowElementList& drawElements,
	UEdGraph* graph) const
{
	return new FDialogueConnectionDrawingPolicy(
		backLayerId,
		frontLayerId,
		zoomFactor,
		clippingRect,
		drawElements);
}

FLinearColor UDialogueGraphSchema::GetPinTypeColor(const FEdGraphPinType& pinType) const
{
	return FLinearColor::White;
}

#undef LOCTEXT_NAMESPACE
