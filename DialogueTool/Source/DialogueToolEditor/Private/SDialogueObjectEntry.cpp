// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueObjectEntry.h"

#include "ISinglePropertyView.h"
#include "Modules/ModuleManager.h"
#include "PropertyHandle.h"
#include "PropertyCustomizationHelpers.h"
#include "PropertyEditorModule.h"
#include "SDialogueRichTextEditor.h"
#include "UObject/UnrealType.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SNullWidget.h"

void SDialogueObjectEntry::Construct(const FArguments& arguments)
{
	BaseClass = arguments._BaseClass;
	Object = arguments._Object;
	RichTextProperties = arguments._RichTextProperties;
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
	PropertyViews.Reset();
	UObject* object = Object.Get();
	TSharedRef<SClassPropertyEntryBox> classPicker =
		SNew(SClassPropertyEntryBox)
		.MetaClass(BaseClass)
		.AllowAbstract(false)
		.AllowNone(true)
		.HideViewOptions(true)
		.ShowDisplayNames(true)
		.SelectedClass(TAttribute<const UClass*>::Create(
			TAttribute<const UClass*>::FGetter::CreateSP(this, &SDialogueObjectEntry::GetObjectClass)))
		.OnSetClass(FOnSetClass::CreateSP(this, &SDialogueObjectEntry::OnObjectClassSet));
	if (object)
	{
		const FText classTooltip = object->GetClass()->GetToolTipText();
		TArray<TSharedRef<SWidget>> widgets{classPicker};
		for (int32 widgetIndex = 0; widgetIndex < widgets.Num(); ++widgetIndex)
		{
			const TSharedRef<SWidget>& widget = widgets[widgetIndex];
			widget->SetToolTipText(classTooltip);
			FChildren* children = widget->GetChildren();
			for (int32 childIndex = 0; childIndex < children->Num(); ++childIndex)
			{
				widgets.Add(children->GetChildAt(childIndex));
			}
		}
	}

	Content->AddSlot()
	.AutoWidth()
	.VAlign(VAlign_Center)
	[
		classPicker
	];

	Content->AddSlot()
	.FillWidth(1.0f)
	[
		SNullWidget::NullWidget
	];

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
		propertyParams.NamePlacement = EPropertyNamePlacement::Left;
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
		TSharedRef<SWidget> propertyWidget = propertyView.ToSharedRef();
		const TSharedPtr<IPropertyHandle> propertyHandle = propertyView->GetPropertyHandle();
		if (RichTextProperties && CastField<FTextProperty>(*property) && propertyHandle.IsValid())
		{
			PropertyViews.Add(propertyView);
			FText propertyText;
			propertyHandle->GetValue(propertyText);
			propertyWidget = SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					propertyHandle->CreatePropertyNameWidget()
				]

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.Padding(4.0f, 0.0f, 0.0f, 0.0f)
				[
					SNew(SDialogueRichTextEditor)
					.Text(propertyText)
					.AutoWrapText(true)
					.OnTextCommitted_Lambda([propertyHandle](const FText& text, ETextCommit::Type)
					{
						FText currentText;
						if (propertyHandle->GetValue(currentText) == FPropertyAccess::Success
							&& currentText.EqualTo(text))
						{
							return;
						}

						propertyHandle->SetValue(text);
					})
				];
		}
		const float minWidth = property->GetFloatMetaData(TEXT("DialogueMinWidth"));
		if (minWidth > 0.0f)
		{
			propertyWidget = SNew(SBox)
				.MinDesiredWidth(minWidth)
				[propertyWidget];
		}
		Content->AddSlot()
		.AutoWidth()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(6.0f, 0.0f, 0.0f, 0.0f)
		[
			propertyWidget
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
