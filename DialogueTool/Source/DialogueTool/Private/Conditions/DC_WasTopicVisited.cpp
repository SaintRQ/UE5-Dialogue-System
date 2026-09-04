#include "Conditions/DC_WasTopicVisited.h"

#include "DialogueManager.h"

bool UDC_WasTopicVisited::ExecuteCondition_Implementation(const TArray<UObject*>& Context) const
{
	const UDialogueManager* dialogueManager = UDialogueManager::GetFromContext(
		Context.IsEmpty() ? nullptr : Context[0]);
	return dialogueManager
		&& dialogueManager->GetEvaluatedResponseId() > 0
		&& dialogueManager->WasEvaluatedTopicVisited() == ConditionResult;
}
