// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Toolkits/AssetEditorToolkit.h"

class SGraphEditor;
class UDialogueObject;
class UEdGraphNode;
class IDetailsView;

class DIALOGUETOOLEDITOR_API FDialogueObjectEditor final : public FAssetEditorToolkit
{
public:

	// Initializes the dialogue graph editor.
	void InitDialogueObjectEditor(
		EToolkitMode::Type mode,
		const TSharedPtr<IToolkitHost>& toolkitHost,
		UDialogueObject* objectToEdit);

	// Returns the editor toolkit identifier.
	virtual FName GetToolkitFName() const override;

	// Returns the editor display name.
	virtual FText GetBaseToolkitName() const override;

	// Returns the world-centric tab prefix.
	virtual FString GetWorldCentricTabPrefix() const override;

	// Returns the world-centric tab color.
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

	// Registers dialogue editor tabs.
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& tabManager) override;

	// Unregisters dialogue editor tabs.
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& tabManager) override;

private:

	// Creates the dialogue graph tab.
	TSharedRef<SDockTab> SpawnGraphTab(const FSpawnTabArgs& arguments);

	// Creates the selected object details tab.
	TSharedRef<SDockTab> SpawnDetailsTab(const FSpawnTabArgs& arguments);

	// Updates the details panel from graph selection.
	void OnSelectedNodesChanged(const TSet<UObject*>& selectedNodes);

	// Applies an inline graph node title edit.
	void OnNodeTitleCommitted(const FText& text, ETextCommit::Type commitType, UEdGraphNode* node);

	// Deletes selected dialogue nodes.
	void DeleteSelectedNodes();

	// Returns whether selected dialogue nodes can be deleted.
	bool CanDeleteSelectedNodes() const;

	// Copies selected dialogue nodes to the clipboard.
	void CopySelectedNodes();

	// Returns whether selected dialogue nodes can be copied.
	bool CanCopySelectedNodes() const;

	// Pastes dialogue nodes at the graph cursor.
	void PasteNodes();

	// Pastes dialogue nodes at the specified graph location.
	void PasteNodesHere(const FVector2f& location);

	// Returns whether the clipboard contains graph nodes.
	bool CanPasteNodes() const;

	// Creates a resizable comment around selected graph nodes.
	void CreateComment();

	static const FName GraphTabId;
	static const FName DetailsTabId;

	TWeakObjectPtr<UDialogueObject> DialogueObject;
	TSharedPtr<SGraphEditor> GraphEditor;
	TSharedPtr<IDetailsView> DetailsView;
	TSharedPtr<FUICommandList> GraphEditorCommands;
};
