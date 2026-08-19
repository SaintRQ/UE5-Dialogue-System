// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueObjectEntry.h"

#include "ISinglePropertyView.h"
#include "Modules/ModuleManager.h"
#include "PropertyCustomizationHelpers.h"
#include "PropertyEditorModule.h"
#include "UObject/UnrealType.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"

void SDialogueObjectEntry::Construct(const FArguments& arguments)
{
	BaseClass = arguments._BaseClass;
	Object = arguments._Object;
	OnSetClass = arguments._OnSetClass;
	ChildSlot
	[
		SAssignNew(Content, SHorizontalBox)
	];
	Refresh();
}

void SDialogueObjectEntry::Refresh()
{
	Content->ClearChildren();
	Content->AddSlot()
	.AutoWidth()
	.VAlign(VAlign_Center)
	[
		SNew(SClassPropertyEntryBox)
		.MetaClass(BaseClass)
		.AllowAbstract(false)
		.AllowNone(true)
		.HideViewOptions(true)
		.ShowDisplayNames(true)
		.SelectedClass(TAttribute<const UClass*>::Create(
			TAttribute<const UClass*>::FGetter::CreateSP(this, &SDialogueObjectEntry::GetObjectClass)))
		.OnSetClass(FOnSetClass::CreateSP(this, &SDialogueObjectEntry::OnObjectClassSet))
	];

	Content->AddSlot()
	.FillWidth(1.0f)
	[
		SNullWidget::NullWidget
	];

	UObject* object = Object.Get();
	if (!object)
	{
		return;
	}

	FPropertyEditorModule& propertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	for (TFieldIterator<FProperty> property(object->GetClass(), EFieldIterationFlags::IncludeSuper); property; ++property)
	{
		if (!property->HasAnyPropertyFlags(CPF_Edit)
			|| property->HasAnyPropertyFlags(CPF_DisableEditOnInstance))
		{
			continue;
		}

		FSinglePropertyParams propertyParams;
		propertyParams.bHideAssetThumbnail = true;
		propertyParams.bHideResetToDefault = true;
		propertyParams.NamePlacement = EPropertyNamePlacement::Hidden;
		TSharedPtr<ISinglePropertyView> propertyView = propertyEditorModule.CreateSingleProperty(
			object,
			property->GetFName(),
			propertyParams);
		if (!propertyView.IsValid() || !propertyView->HasValidProperty())
		{
			continue;
		}

		const TWeakObjectPtr<UObject> weakObject = object;
		propertyView->SetOnPropertyValueChanged(FSimpleDelegate::CreateLambda([weakObject]()
		{
			if (UObject* changedObject = weakObject.Get())
			{
				changedObject->MarkPackageDirty();
			}
		}));
		Content->AddSlot()
		.AutoWidth()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(6.0f, 0.0f, 0.0f, 0.0f)
		[
			propertyView.ToSharedRef()
		];
	}
}

const UClass* SDialogueObjectEntry::GetObjectClass() const
{
	const UObject* object = Object.Get();
	return object ? object->GetClass() : nullptr;
}

void SDialogueObjectEntry::OnObjectClassSet(const UClass* objectClass)
{
	OnSetClass.ExecuteIfBound(objectClass);
	Refresh();
}
