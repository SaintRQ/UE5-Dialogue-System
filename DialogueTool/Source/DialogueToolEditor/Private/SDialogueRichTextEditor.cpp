// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueRichTextEditor.h"

#include "DialogueToolSettings.h"
#include "Engine/DataTable.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#define LOCTEXT_NAMESPACE "SDialogueRichTextEditor"

void SDialogueRichTextEditor::Construct(const FArguments& arguments)
{
	OnDialogueTextCommitted = arguments._OnTextCommitted;
	SMultiLineEditableTextBox::Construct(
		SMultiLineEditableTextBox::FArguments()
		.Text(arguments._Text)
		.HintText(arguments._HintText)
		.AutoWrapText(arguments._AutoWrapText)
		.OnTextCommitted(arguments._OnTextCommitted)
		.ContextMenuExtender(FMenuExtensionDelegate::CreateSP(
			this,
			&SDialogueRichTextEditor::ExtendContextMenu)));
}

void SDialogueRichTextEditor::ExtendContextMenu(FMenuBuilder& menuBuilder)
{
	if (!AnyTextSelected())
	{
		return;
	}

	const UDialogueToolSettings* settings = GetDefault<UDialogueToolSettings>();
	UDataTable* styleSet = settings ? settings->RichTextStyleSet.LoadSynchronous() : nullptr;
	if (!styleSet)
	{
		return;
	}

	TArray<FName> rowNames = styleSet->GetRowNames();
	rowNames.Sort(FNameLexicalLess());
	menuBuilder.BeginSection("DialogueRichText", LOCTEXT("RichTextSection", "Rich Text Tags"));
	for (const FName rowName : rowNames)
	{
		const FString tagName = rowName.ToString();
		bool validTag = !tagName.IsEmpty();
		for (const TCHAR character : tagName)
		{
			if (!FChar::IsAlnum(character) && character != TEXT('_')
				&& character != TEXT('.') && character != TEXT('-'))
			{
				validTag = false;
				break;
			}
		}
		if (!validTag)
		{
			continue;
		}

		menuBuilder.AddMenuEntry(
			FText::FromName(rowName),
			FText::Format(
				LOCTEXT("ApplyRichTextTagTooltip", "Wrap the selected text in <{0}>...</>."),
				FText::FromName(rowName)),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &SDialogueRichTextEditor::ApplyRichTextTag, rowName),
				FCanExecuteAction::CreateSP(this, &SDialogueRichTextEditor::CanApplyRichTextTag)));
	}
	menuBuilder.EndSection();
}

void SDialogueRichTextEditor::ApplyRichTextTag(FName tagName)
{
	const FText selectedText = GetSelectedText();
	if (selectedText.IsEmpty() || tagName.IsNone())
	{
		return;
	}

	InsertTextAtCursor(FString::Printf(
		TEXT("<%s>%s</>"),
		*tagName.ToString(),
		*selectedText.ToString()));
	OnDialogueTextCommitted.ExecuteIfBound(GetText(), ETextCommit::Default);
}

bool SDialogueRichTextEditor::CanApplyRichTextTag() const
{
	return AnyTextSelected();
}

#undef LOCTEXT_NAMESPACE
