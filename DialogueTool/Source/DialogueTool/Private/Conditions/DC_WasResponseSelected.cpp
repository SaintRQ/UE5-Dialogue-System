#include "Conditions/DC_WasResponseSelected.h"

#include "DialogueManager.h"

bool UDC_WasResponseSelected::ExecuteCondition_Implementation(const TArray<UObject*>& Context) const
{
	const UDialogueManager* dialogueManager = UDialogueManager::GetFromContext(
		Context.IsEmpty() ? nullptr : Context[0]);
	const int64 responseId = dialogueManager ? dialogueManager->GetEvaluatedResponseId() : 0;
	return responseId > 0
		&& dialogueManager->GetDialogueCache().ResponsesMemory.Contains(responseId) == ConditionResult;
}
