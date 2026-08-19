// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UDialogueAction;
class UDialogueGraphNode;
class UEdGraphNode;
class UEdGraphPin;

struct DIALOGUETOOLEDITOR_API FDialogueGraphResolvedConnection
{
	int64 NextNodeId = -1;
	TArray<TObjectPtr<UDialogueAction>> Actions;
};

namespace DialogueGraphUtilities
{
	// Resolves actions and the final dialogue node reached by an output pin.
	DIALOGUETOOLEDITOR_API FDialogueGraphResolvedConnection ResolveConnection(const UEdGraphPin* outputPin);

	// Returns whether a graph node is reachable from the dialogue initialization node.
	DIALOGUETOOLEDITOR_API bool IsConnectedToInit(const UEdGraphNode* node);

	// Returns whether an output belongs to a finish-response action chain.
	DIALOGUETOOLEDITOR_API bool IsFinishResponseFlow(const UEdGraphPin* outputPin);

	// Returns whether a node and its downstream chain contain only actions and reroutes.
	DIALOGUETOOLEDITOR_API bool IsValidFinishResponseTarget(const UEdGraphNode* node);
}
