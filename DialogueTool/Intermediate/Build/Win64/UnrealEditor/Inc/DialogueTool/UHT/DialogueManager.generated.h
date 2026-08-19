// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueManager.h"

#ifdef DIALOGUETOOL_DialogueManager_generated_h
#error "DialogueManager.generated.h already included, missing '#pragma once' in DialogueManager.h"
#endif
#define DIALOGUETOOL_DialogueManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UDialogueObject;
class UObject;
struct FDialogueResponse;

// ********** Begin Delegate FDialogueTextUpdated **************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_16_DELEGATE \
DIALOGUETOOL_API void FDialogueTextUpdated_DelegateWrapper(const FMulticastScriptDelegate& DialogueTextUpdated, FText const& Text);


// ********** End Delegate FDialogueTextUpdated ****************************************************

// ********** Begin Delegate FDialogueResponsesUpdated *********************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_20_DELEGATE \
DIALOGUETOOL_API void FDialogueResponsesUpdated_DelegateWrapper(const FMulticastScriptDelegate& DialogueResponsesUpdated, TArray<FDialogueResponse> const& Responses);


// ********** End Delegate FDialogueResponsesUpdated ***********************************************

// ********** Begin Delegate FDialogueFinished *****************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_21_DELEGATE \
DIALOGUETOOL_API void FDialogueFinished_DelegateWrapper(const FMulticastScriptDelegate& DialogueFinished);


// ********** End Delegate FDialogueFinished *******************************************************

// ********** Begin Class UDialogueManager *********************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsWaitingForContinue); \
	DECLARE_FUNCTION(execFinishDialogue); \
	DECLARE_FUNCTION(execSelectResponse); \
	DECLARE_FUNCTION(execContinueDialogue); \
	DECLARE_FUNCTION(execStartDialogue);


DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueManager_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueManager(); \
	friend struct Z_Construct_UClass_UDialogueManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueManager_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueManager_NoRegister) \
	DECLARE_SERIALIZER(UDialogueManager)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueManager(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueManager(UDialogueManager&&) = delete; \
	UDialogueManager(const UDialogueManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDialogueManager) \
	NO_API virtual ~UDialogueManager();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_23_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueManager;

// ********** End Class UDialogueManager ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
