#include "Conditions/DC_WasResponseSelected.h"

#include "DialogueManager.h"

bool UDC_WasResponseSelected::ExecuteCondition_Implementation(UObject* context) const
{
	const UDialogueManager* dialogueManager = UDialogueManager::GetFromContext(context);
	const int64 responseId = dialogueManager ? dialogueManager->GetEvaluatedResponseId() : 0;
	return responseId > 0
		&& dialogueManager->GetDialogueCache().ResponsesMemory.Contains(responseId) == ConditionResult;
}
