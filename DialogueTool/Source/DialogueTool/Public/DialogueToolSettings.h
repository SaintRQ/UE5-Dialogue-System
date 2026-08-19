// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "DialogueToolSettings.generated.h"

class UDataTable;

UCLASS(Config = Game, DefaultConfig, BlueprintType, meta = (DisplayName = "Dialogue Tool"))
class DIALOGUETOOL_API UDialogueToolSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	// Creates the dialogue tool settings section.
	UDialogueToolSettings();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta = (DisplayName = "Characters Per Second"))
	int32 CharactersPerSecond = 20;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text")
	FText ResponseEndDialogueText = FText::GetEmpty();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text")
	FText ResponseReturnDialogueText;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Rich Text",
		meta = (RequiredAssetDataTags = "RowStructure=/Script/UMG.RichTextStyleRow"))
	TSoftObjectPtr<UDataTable> RichTextStyleSet;
};
