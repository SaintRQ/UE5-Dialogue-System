// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueObject.h"

#include "Hash/CityHash.h"
#include "Misc/Guid.h"

void FDialogueSwitcher::EnsureMinimumConditions()
{
	while (Conditions.Num() < 2)
	{
		FDialogueSwitcherCondition& condition = Conditions.AddDefaulted_GetRef();
		condition.Name = FName(*FString::Printf(TEXT("Condition %d"), Conditions.Num()));
	}
}

void UDialogueObject::PostLoad()
{
	Super::PostLoad();
	for (TPair<int64, FDialogueNode>& dialogueNode : DialogueNodes)
	{
		FDialogueNode& node = dialogueNode.Value;
		if (node.RootText.IsEmpty())
		{
			node.RootText.Add(FText::GetEmpty());
		}
		node.RootSounds.SetNum(node.RootText.Num());
		node.RootTextProviders.SetNum(node.RootText.Num());
		for (int32 textIndex = 0; textIndex < node.RootText.Num(); ++textIndex)
		{
			if (node.RootTextProviders[textIndex])
			{
				node.RootText[textIndex] = FText::GetEmpty();
			}
		}

		int32 finishIndex = INDEX_NONE;
		for (int32 responseIndex = 0; responseIndex < node.Response.Num();)
		{
			FDialogueResponse& response = node.Response[responseIndex];
			if (!response.CustomTextId.IsNone())
			{
				response.ResponseProvider = nullptr;
				response.Response = FText::GetEmpty();
			}
			else if (response.ResponseProvider)
			{
				response.Response = FText::GetEmpty();
			}

			if (!response.FinishDialogue)
			{
				++responseIndex;
				continue;
			}

			if (finishIndex != INDEX_NONE)
			{
				node.Response.RemoveAt(responseIndex);
				continue;
			}

			finishIndex = responseIndex++;
			response.Response = FText::GetEmpty();
			response.CustomTextId = NAME_None;
			response.ResponseProvider = nullptr;
			response.Conditions.Reset();
			response.AlwaysVisible = true;
			response.Visibility = EDialogueConditionVisibilityResult::VisibleSuccess;
		}

		if (finishIndex != INDEX_NONE && finishIndex != node.Response.Num() - 1)
		{
			FDialogueResponse finishResponse = MoveTemp(node.Response[finishIndex]);
			node.Response.RemoveAt(finishIndex);
			node.Response.Add(MoveTemp(finishResponse));
		}
	}
	for (TPair<int64, FDialogueSwitcher>& dialogueSwitcher : DialogueSwitchers)
	{
		dialogueSwitcher.Value.EnsureMinimumConditions();
	}
}

int64 UDialogueObject::GenerateUniqueId() const
{
	int64 id = 0;

	do
	{
		const FGuid guid = FGuid::NewGuid();
		id = static_cast<int64>(CityHash64(reinterpret_cast<const char*>(&guid), sizeof(guid)) & MAX_int64);
	}
	while (id == 0 || DialogueNodes.Contains(id) || DialogueSwitchers.Contains(id) || DialogueTransits.Contains(id));

	return id;
}

FDialogueNode& UDialogueObject::AddDialogueNode(int64 nodeId)
{
	FDialogueNode& dialogueNode = DialogueNodes.FindOrAdd(nodeId);
	if (dialogueNode.RootText.IsEmpty())
	{
		dialogueNode.RootText.Add(FText::GetEmpty());
	}
	dialogueNode.RootSounds.SetNum(dialogueNode.RootText.Num());
	dialogueNode.RootTextProviders.SetNum(dialogueNode.RootText.Num());
	return dialogueNode;
}

FDialogueNode* UDialogueObject::FindDialogueNode(int64 nodeId)
{
	return DialogueNodes.Find(nodeId);
}

const FDialogueNode* UDialogueObject::FindDialogueNode(int64 nodeId) const
{
	return DialogueNodes.Find(nodeId);
}

void UDialogueObject::RemoveDialogueNode(int64 nodeId)
{
	DialogueNodes.Remove(nodeId);
}

FDialogueSwitcher& UDialogueObject::AddDialogueSwitcher(int64 switcherId)
{
	FDialogueSwitcher& dialogueSwitcher = DialogueSwitchers.FindOrAdd(switcherId);
	dialogueSwitcher.EnsureMinimumConditions();
	return dialogueSwitcher;
}

FDialogueSwitcher* UDialogueObject::FindDialogueSwitcher(int64 switcherId)
{
	return DialogueSwitchers.Find(switcherId);
}

const FDialogueSwitcher* UDialogueObject::FindDialogueSwitcher(int64 switcherId) const
{
	return DialogueSwitchers.Find(switcherId);
}

void UDialogueObject::RemoveDialogueSwitcher(int64 switcherId)
{
	DialogueSwitchers.Remove(switcherId);
}

FDialogueTransit& UDialogueObject::AddDialogueTransit(int64 transitId)
{
	return DialogueTransits.FindOrAdd(transitId);
}

FDialogueTransit* UDialogueObject::FindDialogueTransit(int64 transitId)
{
	return DialogueTransits.Find(transitId);
}

const FDialogueTransit* UDialogueObject::FindDialogueTransit(int64 transitId) const
{
	return DialogueTransits.Find(transitId);
}

void UDialogueObject::RemoveDialogueTransit(int64 transitId)
{
	DialogueTransits.Remove(transitId);
}

TArray<FDialogueInit>& UDialogueObject::GetDialogueInitData()
{
	return DialogueInit;
}

const TArray<FDialogueInit>& UDialogueObject::GetDialogueInitData() const
{
	return DialogueInit;
}

#if WITH_EDITOR
UEdGraph* UDialogueObject::GetEditorGraph() const
{
	return EditorGraph;
}

void UDialogueObject::SetEditorGraph(UEdGraph* newEditorGraph)
{
	EditorGraph = newEditorGraph;
}
#endif
