// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"

#include "DialogueGraphSchema.generated.h"

UCLASS()
class DIALOGUETOOLEDITOR_API UDialogueGraphSchema : public UEdGraphSchema
{
	GENERATED_BODY()

public:

	// Adds dialogue node creation to the empty graph context menu.
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& contextMenuBuilder) const override;

	// Validates dialogue flow connections.
	virtual const FPinConnectionResponse CanCreateConnection(
		const UEdGraphPin* pinA,
		const UEdGraphPin* pinB) const override;

	// Inserts a reroute node into a double-clicked dialogue connection.
	virtual void OnPinConnectionDoubleCicked(
		UEdGraphPin* pinA,
		UEdGraphPin* pinB,
		const FVector2f& graphPosition) const override;

	// Creates Blueprint-style dialogue connections without arrowheads.
	virtual FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(
		int32 backLayerId,
		int32 frontLayerId,
		float zoomFactor,
		const FSlateRect& clippingRect,
		FSlateWindowElementList& drawElements,
		UEdGraph* graph) const override;

	// Returns the color used by dialogue flow pins.
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& pinType) const override;
};
