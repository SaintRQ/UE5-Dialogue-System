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

	// Automatically continues after a fully revealed text when no response selection is waiting.
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta = (DisplayName = "Auto Continue"))
	bool AutoContinue = false;

	// Defines the delay before automatic continuation in seconds.
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta = (DisplayName = "Auto Continue Delay", EditCondition = "AutoContinue", ClampMin = "0.0", UIMin = "0.0"))
	float AutoContinueDelay = 1.0f;

	// Allows manual Continue input while automatic continuation is enabled.
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta = (DisplayName = "Allow Continue Click", EditCondition = "AutoContinue"))
	bool AllowContinueClick = true;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text", meta = (DisplayName = "Characters Per Second"))
	int32 CharactersPerSecond = 20;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text")
	FText ResponseEndDialogueText = FText::GetEmpty();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text")
	FText ResponseReturnDialogueText;
	
	// ID | Text
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text")
	TMap<FName, FText> ResponseCustomTextList; 
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta = (RequiredAssetDataTags = "RowStructure=/Script/UMG.RichTextStyleRow"))
	TSoftObjectPtr<UDataTable> RichTextStyleSet;
};
