// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "DialogueRoot.h"
#include "Widgets/SCompoundWidget.h"

class UDialogueCondition;
struct FSlateRoundedBoxBrush;

DECLARE_DELEGATE_RetVal_OneParam(UDialogueCondition*, FOnGetDialogueCondition, int32);
DECLARE_DELEGATE_TwoParams(FOnSetDialogueConditionClass, const UClass*, int32);
DECLARE_DELEGATE(FOnAddDialogueCondition);
DECLARE_DELEGATE_OneParam(FOnRemoveDialogueCondition, int32);
DECLARE_DELEGATE_OneParam(FOnSetDialogueConditionMode, EDialogueConditionMode);

class DIALOGUETOOLEDITOR_API SDialogueConditionPopup final : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogueConditionPopup)
		: _ConditionCount(0)
		, _ConditionMode(EDialogueConditionMode::All)
	{
	}
		SLATE_ATTRIBUTE(int32, ConditionCount)
		SLATE_ATTRIBUTE(EDialogueConditionMode, ConditionMode)
		SLATE_EVENT(FOnGetDialogueCondition, OnGetCondition)
		SLATE_EVENT(FOnSetDialogueConditionClass, OnSetConditionClass)
		SLATE_EVENT(FOnAddDialogueCondition, OnAddCondition)
		SLATE_EVENT(FOnRemoveDialogueCondition, OnRemoveCondition)
		SLATE_EVENT(FOnSetDialogueConditionMode, OnSetConditionMode)
	SLATE_END_ARGS()

	// Constructs a reusable dialogue condition editor popup.
	void Construct(const FArguments& arguments);

private:

	// Rebuilds condition rows.
	void RefreshConditions();

	// Returns a condition instance.
	UDialogueCondition* GetCondition(int32 conditionIndex) const;

	// Returns the condition mode button background.
	const FSlateBrush* GetModeBrush() const;

	// Returns the condition mode button text.
	FText GetModeText() const;

	// Returns the condition mode button text color.
	FSlateColor GetModeTextColor() const;

	// Forwards a selected condition class.
	void OnConditionClassSet(const UClass* conditionClass, int32 conditionIndex);

	// Selects how conditions are combined.
	FReply OnConditionModeClicked();

	// Adds a condition row.
	FReply OnAddConditionClicked();

	// Removes a condition row.
	FReply OnRemoveConditionClicked(int32 conditionIndex);

	TAttribute<int32> ConditionCount;
	TAttribute<EDialogueConditionMode> ConditionMode;
	FOnGetDialogueCondition OnGetCondition;
	FOnSetDialogueConditionClass OnSetConditionClass;
	FOnAddDialogueCondition OnAddCondition;
	FOnRemoveDialogueCondition OnRemoveCondition;
	FOnSetDialogueConditionMode OnSetConditionMode;
	TSharedPtr<SVerticalBox> ConditionList;
	TSharedPtr<FSlateRoundedBoxBrush> AllModeBrush;
	TSharedPtr<FSlateRoundedBoxBrush> AnyModeBrush;
};
