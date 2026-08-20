// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueGraphResponseProviderNode.h"

#include "DialogueProvider.h"
#include "DialogueGraphNode.h"
#include "DialogueObject.h"
#include "EdGraph/EdGraph.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "DialogueGraphResponseProviderNode"

namespace
{
	const FName providerPinCategory(TEXT("DialogueResponseProvider"));
	const FName providerOutputPinName(TEXT("Provider"));
}

void UDialogueGraphResponseProviderNode::AllocateDefaultPins()
{
	CreatePin(EGPD_Output, providerPinCategory, providerOutputPinName);
}

void UDialogueGraphResponseProviderNode::AutowireNewNode(UEdGraphPin* fromPin)
{
	if (fromPin && fromPin->Direction == EGPD_Input)
	{
		GetSchema()->TryCreateConnection(GetOutputPin(), fromPin);
	}
}

void UDialogueGraphResponseProviderNode::PostPasteNode()
{
	Super::PostPasteNode();
	UDialogueObject* dialogueObject = GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
	if (DialogueProvider && dialogueObject)
	{
		Modify();
		DialogueProvider = DuplicateObject<UDialogueProvider>(DialogueProvider.Get(), dialogueObject);
		NotifyProviderChanged();
	}
}

void UDialogueGraphResponseProviderNode::PinConnectionListChanged(UEdGraphPin* pin)
{
	Super::PinConnectionListChanged(pin);
	RefreshDialogueNodes();
}

void UDialogueGraphResponseProviderNode::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	RefreshDialogueNodes();
}

void UDialogueGraphResponseProviderNode::DestroyNode()
{
	UEdGraph* graph = GetGraph();
	Super::DestroyNode();
	if (graph)
	{
		for (UEdGraphNode* node : graph->Nodes)
		{
			if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(node))
			{
				dialogueNode->RefreshProviders();
			}
		}
	}
}

FText UDialogueGraphResponseProviderNode::GetNodeTitle(ENodeTitleType::Type titleType) const
{
	return LOCTEXT("NodeTitle", "PROVIDER");
}

FText UDialogueGraphResponseProviderNode::GetTooltipText() const
{
	return LOCTEXT(
		"NodeTooltip",
		"Generates dynamic text for every connected topic text or standard response entry.\n"
		"The selected provider receives the dialogue context and current cache when the text is requested.\n"
		"Provider variables are stored in this node; custom and Finish/Return responses cannot use a Provider.");
}

UEdGraphPin* UDialogueGraphResponseProviderNode::GetOutputPin() const
{
	return FindPin(providerOutputPinName, EGPD_Output);
}

UClass* UDialogueGraphResponseProviderNode::GetResponseProviderClass() const
{
	return DialogueProvider ? DialogueProvider->GetClass() : nullptr;
}

UDialogueProvider* UDialogueGraphResponseProviderNode::GetDialogueProvider() const
{
	return DialogueProvider;
}

void UDialogueGraphResponseProviderNode::SetResponseProviderClass(const UClass* responseProviderClass)
{
	if (responseProviderClass && (!responseProviderClass->IsChildOf(UDialogueProvider::StaticClass())
		|| responseProviderClass->HasAnyClassFlags(CLASS_Abstract)))
	{
		return;
	}

	if ((DialogueProvider ? DialogueProvider->GetClass() : nullptr) == responseProviderClass)
	{
		return;
	}

	const FScopedTransaction transaction(LOCTEXT("SetResponseProvider", "Set Response Provider"));
	Modify();
	UDialogueObject* dialogueObject = GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr;
	DialogueProvider = responseProviderClass && dialogueObject
		? NewObject<UDialogueProvider>(
			dialogueObject,
			const_cast<UClass*>(responseProviderClass),
			NAME_None,
			RF_Transactional)
		: nullptr;
	NotifyProviderChanged();
}

void UDialogueGraphResponseProviderNode::RefreshDialogueNodes() const
{
	if (const UEdGraph* graph = GetGraph())
	{
		for (UEdGraphNode* node : graph->Nodes)
		{
			if (UDialogueGraphNode* dialogueNode = Cast<UDialogueGraphNode>(node))
			{
				dialogueNode->RefreshProviders();
			}
		}
	}
}

void UDialogueGraphResponseProviderNode::NotifyProviderChanged()
{
	RefreshDialogueNodes();
	if (UEdGraph* graph = GetGraph())
	{
		graph->NotifyNodeChanged(this);
	}

	if (UDialogueObject* dialogueObject = GetGraph() ? GetGraph()->GetTypedOuter<UDialogueObject>() : nullptr)
	{
		dialogueObject->MarkPackageDirty();
	}
}

#undef LOCTEXT_NAMESPACE
