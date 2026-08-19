// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam(FOnSetDialogueObjectClass, const UClass*);

class DIALOGUETOOLEDITOR_API SDialogueObjectEntry final : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SDialogueObjectEntry)
		: _BaseClass(UObject::StaticClass())
		, _Object(nullptr)
	{
	}
		SLATE_ARGUMENT(const UClass*, BaseClass)
		SLATE_ATTRIBUTE(UObject*, Object)
		SLATE_EVENT(FOnSetDialogueObjectClass, OnSetClass)
	SLATE_END_ARGS()

	// Constructs a class picker with inline instance properties.
	void Construct(const FArguments& arguments);

private:

	// Rebuilds the class picker and editable property widgets.
	void Refresh();

	// Returns the selected object class.
	const UClass* GetObjectClass() const;

	// Forwards the selected class and refreshes the property widgets.
	void OnObjectClassSet(const UClass* objectClass);

	const UClass* BaseClass = nullptr;
	TAttribute<UObject*> Object;
	FOnSetDialogueObjectClass OnSetClass;
	TSharedPtr<SHorizontalBox> Content;
};
