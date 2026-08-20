// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueObjectEditor.h"

#include "DialogueGraphInitNode.h"
#include "DialogueGraphLibrarySchema.h"
#include "DialogueGraphNode.h"
#include "DialogueGraphSchema.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueLibraryObject.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraphNode_Comment.h"
#include "EdGraphUtilities.h"
#include "Editor.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/GenericCommands.h"
#include "Framework/Commands/UICommandList.h"
#include "GraphEditor.h"
#include "GraphEditorActions.h"
#include "HAL/PlatformApplicationMisc.h"
#include "IDetailsView.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "DialogueObjectEditor"

const FName FDialogueObjectEditor::GraphTabId(TEXT("DialogueObjectEditor_Graph"));
const FName FDialogueObjectEditor::DetailsTabId(TEXT("DialogueObjectEditor_Details"));

void FDialogueObjectEditor::InitDialogueObjectEditor(
	EToolkitMode::Type mode,
	const TSharedPtr<IToolkitHost>& toolkitHost,
	UDialogueObject* objectToEdit)
{
	DialogueObject = objectToEdit;
	objectToEdit->SetFlags(RF_Transactional);
	GEditor->RegisterForUndo(this);
	UEdGraph* graph = objectToEdit->GetEditorGraph();
	const bool bLibrary = objectToEdit->IsA<UDialogueLibraryObject>();
	UClass* graphSchemaClass = bLibrary
		? UDialogueGraphLibrarySchema::StaticClass()
		: UDialogueGraphSchema::StaticClass();

	if (!graph)
	{
		objectToEdit->Modify();
		graph = NewObject<UEdGraph>(objectToEdit, TEXT("DialogueGraph"), RF_Transactional);
		graph->Schema = graphSchemaClass;
		graph->bEditable = true;
		objectToEdit->SetEditorGraph(graph);
		objectToEdit->MarkPackageDirty();
	}
	else if (graph->Schema != graphSchemaClass)
	{
		graph->Modify();
		graph->Schema = graphSchemaClass;
		objectToEdit->MarkPackageDirty();
	}

	UDialogueGraphInitNode* initNode = nullptr;
	for (UEdGraphNode* node : graph->Nodes)
	{
		if (UDialogueGraphInitNode* existingInitNode = Cast<UDialogueGraphInitNode>(node))
		{
			initNode = existingInitNode;
			break;
		}
	}

	bool bInitDataAdded = false;
	if (objectToEdit->GetDialogueInitData().IsEmpty())
	{
		objectToEdit->Modify();
		FDialogueInit& defaultInit = objectToEdit->GetDialogueInitData().AddDefaulted_GetRef();
		defaultInit.Name = TEXT("Default");
		bInitDataAdded = true;
	}

	const bool bInitNodeCreated = !initNode;
	if (bInitNodeCreated)
	{
		graph->Modify();
		initNode = CastChecked<UDialogueGraphInitNode>(FEdGraphSchemaAction_NewNode::CreateNode(
			graph,
			nullptr,
			FVector2f::ZeroVector,
			NewObject<UDialogueGraphInitNode>()));
	}
	else if (bInitDataAdded)
	{
		initNode->ReconstructNode();
	}

	if (bInitNodeCreated || bInitDataAdded)
	{
		objectToEdit->MarkPackageDirty();
	}

	GraphEditorCommands = MakeShared<FUICommandList>();
	GraphEditorCommands->MapAction(
		FGenericCommands::Get().Delete,
		FExecuteAction::CreateSP(this, &FDialogueObjectEditor::DeleteSelectedNodes),
		FCanExecuteAction::CreateSP(this, &FDialogueObjectEditor::CanDeleteSelectedNodes));
	GraphEditorCommands->MapAction(
		FGenericCommands::Get().Copy,
		FExecuteAction::CreateSP(this, &FDialogueObjectEditor::CopySelectedNodes),
		FCanExecuteAction::CreateSP(this, &FDialogueObjectEditor::CanCopySelectedNodes));
	GraphEditorCommands->MapAction(
		FGenericCommands::Get().Paste,
		FExecuteAction::CreateSP(this, &FDialogueObjectEditor::PasteNodes),
		FCanExecuteAction::CreateSP(this, &FDialogueObjectEditor::CanPasteNodes));
	GraphEditorCommands->MapAction(
		FGraphEditorCommands::Get().CreateComment,
		FExecuteAction::CreateSP(this, &FDialogueObjectEditor::CreateComment));

	FGraphAppearanceInfo appearance;
	appearance.CornerText = bLibrary
		? LOCTEXT("LibraryCornerText", "Dialogue Library")
		: LOCTEXT("CornerText", "Dialogue Tool");
	FDetailsViewArgs detailsViewArgs;
	detailsViewArgs.bHideSelectionTip = true;
	detailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	DetailsView = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor")
		.CreateDetailView(detailsViewArgs);
	DetailsView->SetObject(objectToEdit);

	SGraphEditor::FGraphEditorEvents graphEvents;
	graphEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(
		this,
		&FDialogueObjectEditor::OnSelectedNodesChanged);
	graphEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(
		this,
		&FDialogueObjectEditor::OnNodeTitleCommitted);

	GraphEditor = SNew(SGraphEditor)
		.AdditionalCommands(GraphEditorCommands)
		.Appearance(appearance)
		.GraphToEdit(graph)
		.GraphEvents(graphEvents)
		.IsEditable(true)
		.AssetEditorToolkit(SharedThis(this));

	if (bInitNodeCreated)
	{
		GraphEditor->JumpToNode(initNode, false, false);
	}

	const TSharedRef<FTabManager::FLayout> layout = FTabManager::NewLayout("Standalone_DialogueObjectEditor_Layout_v2")
		->AddArea(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Horizontal)
			->Split(
				FTabManager::NewStack()
				->AddTab(GraphTabId, ETabState::OpenedTab)
				->SetSizeCoefficient(0.78f)
				->SetHideTabWell(true))
			->Split(
				FTabManager::NewStack()
				->AddTab(DetailsTabId, ETabState::OpenedTab)
				->SetSizeCoefficient(0.22f)
				->SetHideTabWell(true)));

	InitAssetEditor(
		mode,
		toolkitHost,
		FName(TEXT("DialogueObjectEditorApp")),
		layout,
		true,
		true,
		objectToEdit);

	RegenerateMenusAndToolbars();
}

FName FDialogueObjectEditor::GetToolkitFName() const
{
	return FName(TEXT("DialogueObjectEditor"));
}

FText FDialogueObjectEditor::GetBaseToolkitName() const
{
	return DialogueObject.IsValid() && DialogueObject->IsA<UDialogueLibraryObject>()
		? LOCTEXT("LibraryEditorName", "Dialogue Library Editor")
		: LOCTEXT("EditorName", "Dialogue Editor");
}

FString FDialogueObjectEditor::GetWorldCentricTabPrefix() const
{
	return DialogueObject.IsValid() && DialogueObject->IsA<UDialogueLibraryObject>()
		? LOCTEXT("LibraryWorldCentricPrefix", "Dialogue Library ").ToString()
		: LOCTEXT("WorldCentricPrefix", "Dialogue ").ToString();
}

FLinearColor FDialogueObjectEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.1f, 0.45f, 1.0f, 0.5f);
}

void FDialogueObjectEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& tabManager)
{
	const bool bLibrary = DialogueObject.IsValid() && DialogueObject->IsA<UDialogueLibraryObject>();
	WorkspaceMenuCategory = tabManager->AddLocalWorkspaceMenuCategory(
		bLibrary
			? LOCTEXT("LibraryWorkspaceCategory", "Dialogue Library Editor")
			: LOCTEXT("WorkspaceCategory", "Dialogue Editor"));
	FAssetEditorToolkit::RegisterTabSpawners(tabManager);

	tabManager->RegisterTabSpawner(GraphTabId, FOnSpawnTab::CreateSP(this, &FDialogueObjectEditor::SpawnGraphTab))
		.SetDisplayName(bLibrary
			? LOCTEXT("LibraryGraphTab", "Library Graph")
			: LOCTEXT("GraphTab", "Dialogue Graph"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));

	tabManager->RegisterTabSpawner(DetailsTabId, FOnSpawnTab::CreateSP(this, &FDialogueObjectEditor::SpawnDetailsTab))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Details"));
}

void FDialogueObjectEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& tabManager)
{
	tabManager->UnregisterTabSpawner(GraphTabId);
	tabManager->UnregisterTabSpawner(DetailsTabId);
	FAssetEditorToolkit::UnregisterTabSpawners(tabManager);
}

void FDialogueObjectEditor::PostUndo(bool bSuccess)
{
	if (!bSuccess || !GraphEditor.IsValid())
	{
		return;
	}

	GraphEditor->ClearSelectionSet();
	GraphEditor->NotifyGraphChanged();
	FSlateApplication::Get().DismissAllMenus();
}

void FDialogueObjectEditor::PostRedo(bool bSuccess)
{
	PostUndo(bSuccess);
}

TSharedRef<SDockTab> FDialogueObjectEditor::SpawnGraphTab(const FSpawnTabArgs& arguments)
{
	check(arguments.GetTabId() == GraphTabId);

	return SNew(SDockTab)
		.Label(DialogueObject.IsValid() && DialogueObject->IsA<UDialogueLibraryObject>()
			? LOCTEXT("LibraryGraphTab", "Library Graph")
			: LOCTEXT("GraphTab", "Dialogue Graph"))
		[
			GraphEditor.ToSharedRef()
		];
}

TSharedRef<SDockTab> FDialogueObjectEditor::SpawnDetailsTab(const FSpawnTabArgs& arguments)
{
	check(arguments.GetTabId() == DetailsTabId);

	return SNew(SDockTab)
		.Label(LOCTEXT("DetailsTab", "Details"))
		[
			DetailsView.ToSharedRef()
		];
}

void FDialogueObjectEditor::OnSelectedNodesChanged(const TSet<UObject*>& selectedNodes)
{
	if (!DetailsView.IsValid())
	{
		return;
	}

	TArray<UObject*> objects;
	objects.Reserve(selectedNodes.Num());
	for (UObject* selectedNode : selectedNodes)
	{
		if (selectedNode)
		{
			objects.Add(selectedNode);
		}
	}

	if (objects.IsEmpty())
	{
		objects.Add(DialogueObject.Get());
	}

	DetailsView->SetObjects(objects);
}

void FDialogueObjectEditor::OnNodeTitleCommitted(
	const FText& text,
	ETextCommit::Type commitType,
	UEdGraphNode* node)
{
	if (!node)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("RenameNode", "Rename Dialogue Graph Node"));
	node->Modify();
	node->OnRenameNode(text.ToString());
	if (GraphEditor.IsValid())
	{
		GraphEditor->NotifyGraphChanged();
	}

	if (UDialogueObject* dialogueObject = DialogueObject.Get())
	{
		dialogueObject->MarkPackageDirty();
	}
}

void FDialogueObjectEditor::DeleteSelectedNodes()
{
	if (!GraphEditor.IsValid())
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("DeleteNodes", "Delete Dialogue Nodes"));
	const FGraphPanelSelectionSet selectedNodes = GraphEditor->GetSelectedNodes();
	GraphEditor->ClearSelectionSet();

	if (UEdGraph* graph = GraphEditor->GetCurrentGraph())
	{
		graph->Modify();
	}

	for (UObject* selectedObject : selectedNodes)
	{
		if (UEdGraphNode* node = Cast<UEdGraphNode>(selectedObject))
		{
			if (node->CanUserDeleteNode())
			{
				node->Modify();
				node->DestroyNode();
			}
		}
	}
}

bool FDialogueObjectEditor::CanDeleteSelectedNodes() const
{
	if (!GraphEditor.IsValid())
	{
		return false;
	}

	for (UObject* selectedObject : GraphEditor->GetSelectedNodes())
	{
		if (const UEdGraphNode* node = Cast<UEdGraphNode>(selectedObject))
		{
			if (node->CanUserDeleteNode())
			{
				return true;
			}
		}
	}

	return false;
}

void FDialogueObjectEditor::CopySelectedNodes()
{
	if (!GraphEditor.IsValid())
	{
		return;
	}

	FGraphPanelSelectionSet selectedNodes = GraphEditor->GetSelectedNodes();
	for (FGraphPanelSelectionSet::TIterator selectedNode(selectedNodes); selectedNode; ++selectedNode)
	{
		UEdGraphNode* node = Cast<UEdGraphNode>(*selectedNode);
		if (!node || !node->CanDuplicateNode())
		{
			selectedNode.RemoveCurrent();
			continue;
		}

		node->PrepareForCopying();
	}

	if (selectedNodes.IsEmpty())
	{
		return;
	}

	FString exportedText;
	FEdGraphUtilities::ExportNodesToText(selectedNodes, exportedText);
	FPlatformApplicationMisc::ClipboardCopy(*exportedText);

	for (UObject* selectedObject : selectedNodes)
	{
		if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(selectedObject))
		{
			dialogueNode->FinishCopying();
		}
		else if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(selectedObject))
		{
			switcherNode->FinishCopying();
		}
		else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(selectedObject))
		{
			transitNode->FinishCopying();
		}
	}
}

bool FDialogueObjectEditor::CanCopySelectedNodes() const
{
	if (!GraphEditor.IsValid())
	{
		return false;
	}

	for (UObject* selectedObject : GraphEditor->GetSelectedNodes())
	{
		if (const UEdGraphNode* node = Cast<UEdGraphNode>(selectedObject))
		{
			if (node->CanDuplicateNode())
			{
				return true;
			}
		}
	}

	return false;
}

void FDialogueObjectEditor::PasteNodes()
{
	if (GraphEditor.IsValid())
	{
		PasteNodesHere(GraphEditor->GetPasteLocation2f());
	}
}

void FDialogueObjectEditor::PasteNodesHere(const FVector2f& location)
{
	if (!GraphEditor.IsValid())
	{
		return;
	}

	UEdGraph* graph = GraphEditor->GetCurrentGraph();
	UDialogueObject* dialogueObject = DialogueObject.Get();
	if (!graph || !dialogueObject)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("PasteNodes", "Paste Dialogue Nodes"));
	graph->Modify();
	dialogueObject->Modify();
	GraphEditor->ClearSelectionSet();

	FString clipboardText;
	FPlatformApplicationMisc::ClipboardPaste(clipboardText);
	TSet<UEdGraphNode*> pastedNodes;
	FEdGraphUtilities::ImportNodesFromText(graph, clipboardText, pastedNodes);

	FVector2f averagePosition = FVector2f::ZeroVector;
	for (UEdGraphNode* pastedNode : pastedNodes)
	{
		averagePosition.X += pastedNode->NodePosX;
		averagePosition.Y += pastedNode->NodePosY;
	}

	if (pastedNodes.IsEmpty())
	{
		return;
	}

	averagePosition /= pastedNodes.Num();
	TMap<int64, int64> pastedNodeIds;
	for (UEdGraphNode* pastedNode : pastedNodes)
	{
		if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(pastedNode))
		{
			pastedNodeIds.Add(dialogueNode->GetPastedFromDialogueNodeId(), dialogueNode->GetDialogueNodeId());
		}
		else if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(pastedNode))
		{
			pastedNodeIds.Add(switcherNode->GetPastedFromSwitcherNodeId(), switcherNode->GetSwitcherNodeId());
		}
		else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(pastedNode))
		{
			pastedNodeIds.Add(transitNode->GetPastedFromTransitNodeId(), transitNode->GetTransitNodeId());
		}

		pastedNode->NodePosX = FMath::RoundToInt(pastedNode->NodePosX - averagePosition.X + location.X);
		pastedNode->NodePosY = FMath::RoundToInt(pastedNode->NodePosY - averagePosition.Y + location.Y);
		pastedNode->SnapToGrid(16);
		pastedNode->CreateNewGuid();
		GraphEditor->SetNodeSelection(pastedNode, true);
	}

	for (UEdGraphNode* pastedNode : pastedNodes)
	{
		if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(pastedNode))
		{
			dialogueNode->RemapPastedConnections(pastedNodeIds);
			dialogueNode->NodeConnectionListChanged();
		}
		else if (UDialogueGraphSwitcherNode* switcherNode = Cast<UDialogueGraphSwitcherNode>(pastedNode))
		{
			switcherNode->RemapPastedConnections(pastedNodeIds);
			switcherNode->NodeConnectionListChanged();
		}
		else if (UDialogueGraphTransitNode* transitNode = Cast<UDialogueGraphTransitNode>(pastedNode))
		{
			transitNode->RemapPastedConnections(pastedNodeIds);
			transitNode->NodeConnectionListChanged();
		}
	}

	GraphEditor->NotifyGraphChanged();
	dialogueObject->PostEditChange();
	dialogueObject->MarkPackageDirty();
}

bool FDialogueObjectEditor::CanPasteNodes() const
{
	if (!GraphEditor.IsValid())
	{
		return false;
	}

	FString clipboardText;
	FPlatformApplicationMisc::ClipboardPaste(clipboardText);
	return FEdGraphUtilities::CanImportNodesFromText(GraphEditor->GetCurrentGraph(), clipboardText);
}

void FDialogueObjectEditor::CreateComment()
{
	if (!GraphEditor.IsValid())
	{
		return;
	}

	UEdGraph* graph = GraphEditor->GetCurrentGraph();
	UDialogueObject* dialogueObject = DialogueObject.Get();
	if (!graph || !dialogueObject)
	{
		return;
	}

	UEdGraphNode_Comment* commentTemplate = NewObject<UEdGraphNode_Comment>();
	FVector2f location = GraphEditor->GetPasteLocation2f();
	FSlateRect bounds;
	if (GraphEditor->GetBoundsForSelectedNodes(bounds, 50.0f))
	{
		commentTemplate->SetBounds(bounds);
		location = FVector2f(bounds.Left, bounds.Top);
	}

	const FScopedTransaction transaction(LOCTEXT("CreateComment", "Create Dialogue Comment"));
	graph->Modify();
	FEdGraphSchemaAction_NewNode::SpawnNodeFromTemplate<UEdGraphNode_Comment>(
		graph,
		commentTemplate,
		location,
		true);
	GraphEditor->NotifyGraphChanged();
	dialogueObject->MarkPackageDirty();
}

#undef LOCTEXT_NAMESPACE
