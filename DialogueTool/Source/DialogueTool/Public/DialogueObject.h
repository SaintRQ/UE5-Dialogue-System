// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DialogueRoot.h"
#include "UObject/Object.h"

#include "DialogueObject.generated.h"

class UEdGraph;

/** Stores dialogue data. */
UCLASS(BlueprintType)
class DIALOGUETOOL_API UDialogueObject : public UObject
{
	GENERATED_BODY()

public:
	// Restores required dialogue data after loading an asset.
	virtual void PostLoad() override;

	// Generates a compact positive unique identifier.
	int64 GenerateUniqueId() const;

	// Adds a dialogue node with the specified identifier.
	FDialogueNode& AddDialogueNode(int64 nodeId);

	// Finds mutable dialogue node data by identifier.
	FDialogueNode* FindDialogueNode(int64 nodeId);

	// Finds dialogue node data by identifier.
	const FDialogueNode* FindDialogueNode(int64 nodeId) const;

	// Removes dialogue node data by identifier.
	void RemoveDialogueNode(int64 nodeId);

	// Adds a dialogue switcher with the specified identifier.
	FDialogueSwitcher& AddDialogueSwitcher(int64 switcherId);

	// Finds mutable dialogue switcher data by identifier.
	FDialogueSwitcher* FindDialogueSwitcher(int64 switcherId);

	// Finds dialogue switcher data by identifier.
	const FDialogueSwitcher* FindDialogueSwitcher(int64 switcherId) const;

	// Removes dialogue switcher data by identifier.
	void RemoveDialogueSwitcher(int64 switcherId);

	// Adds a dialogue library transit with the specified identifier.
	FDialogueTransit& AddDialogueTransit(int64 transitId);

	// Finds mutable dialogue library transit data by identifier.
	FDialogueTransit* FindDialogueTransit(int64 transitId);

	// Finds dialogue library transit data by identifier.
	const FDialogueTransit* FindDialogueTransit(int64 transitId) const;

	// Removes dialogue library transit data by identifier.
	void RemoveDialogueTransit(int64 transitId);

	// Adds a skip-text transition with the specified identifier.
	FDialogueSkipText& AddDialogueSkipText(int64 skipTextId);

	// Finds mutable skip-text transition data by identifier.
	FDialogueSkipText* FindDialogueSkipText(int64 skipTextId);

	// Finds skip-text transition data by identifier.
	const FDialogueSkipText* FindDialogueSkipText(int64 skipTextId) const;

	// Removes skip-text transition data by identifier.
	void RemoveDialogueSkipText(int64 skipTextId);

	// Returns mutable dialogue initialization data.
	TArray<FDialogueInit>& GetDialogueInitData();

	// Returns dialogue initialization data.
	const TArray<FDialogueInit>& GetDialogueInitData() const;

#if WITH_EDITOR
	// Returns the graph used by the dialogue editor.
	UEdGraph* GetEditorGraph() const;

	// Sets the graph used by the dialogue editor.
	void SetEditorGraph(UEdGraph* newEditorGraph);
#endif

private:
	
	UPROPERTY()
	int64 RootID = {};
	
	UPROPERTY()
	TArray<FDialogueInit> DialogueInit;
	
	UPROPERTY()
	TMap<int64, FDialogueNode> DialogueNodes;

	UPROPERTY()
	TMap<int64, FDialogueSwitcher> DialogueSwitchers;

	UPROPERTY()
	TMap<int64, FDialogueTransit> DialogueTransits;

	UPROPERTY()
	TMap<int64, FDialogueSkipText> DialogueSkipTexts;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UEdGraph> EditorGraph = nullptr;
#endif
};
