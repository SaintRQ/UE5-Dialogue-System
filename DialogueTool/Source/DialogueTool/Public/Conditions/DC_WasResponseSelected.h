#pragma once

#include "DialogueCondition.h"

#include "DC_WasResponseSelected.generated.h"

UCLASS(meta = (ToolTip = "Checks whether the response containing this condition has ever been selected."))
class DIALOGUETOOL_API UDC_WasResponseSelected final : public UDialogueCondition
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, Category = "Response")
	bool ConditionResult = false;

public:

	// Checks the selection memory of the response containing this condition.
	virtual bool ExecuteCondition_Implementation(UObject* context) const override;
};
