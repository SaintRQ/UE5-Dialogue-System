// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueToolSettings.h"

#ifdef DIALOGUETOOL_DialogueToolSettings_generated_h
#error "DialogueToolSettings.generated.h already included, missing '#pragma once' in DialogueToolSettings.h"
#endif
#define DIALOGUETOOL_DialogueToolSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueToolSettings ****************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueToolSettings_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueToolSettings(); \
	friend struct Z_Construct_UClass_UDialogueToolSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueToolSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueToolSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueToolSettings_NoRegister) \
	DECLARE_SERIALIZER(UDialogueToolSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueToolSettings(UDialogueToolSettings&&) = delete; \
	UDialogueToolSettings(const UDialogueToolSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueToolSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueToolSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDialogueToolSettings) \
	NO_API virtual ~UDialogueToolSettings();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h_12_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h_15_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueToolSettings;

// ********** End Class UDialogueToolSettings ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
