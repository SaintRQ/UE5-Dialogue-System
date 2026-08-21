#pragma once

#include "DialogueCondition.h"

#include "DC_WasTopicVisited.generated.h"

UCLASS(meta = (ToolTip = "Checks whether the topic containing this response was visited before its current entry."))
class DIALOGUETOOL_API UDC_WasTopicVisited final : public UDialogueCondition
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, Category = "Topic")
	bool ConditionResult = false;

public:

	// Checks the previous-visit state of the topic containing this response.
	virtual bool ExecuteCondition_Implementation(UObject* context) const override;
};
