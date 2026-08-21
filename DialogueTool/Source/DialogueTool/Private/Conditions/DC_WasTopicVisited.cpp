#include "Conditions/DC_WasTopicVisited.h"

#include "DialogueManager.h"

bool UDC_WasTopicVisited::ExecuteCondition_Implementation(UObject* context) const
{
	const UDialogueManager* dialogueManager = UDialogueManager::GetFromContext(context);
	return dialogueManager
		&& dialogueManager->GetEvaluatedResponseId() > 0
		&& dialogueManager->WasEvaluatedTopicVisited() == ConditionResult;
}
