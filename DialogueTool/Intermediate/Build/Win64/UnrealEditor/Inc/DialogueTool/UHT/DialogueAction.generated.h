// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueAction.h"

#ifdef DIALOGUETOOL_DialogueAction_generated_h
#error "DialogueAction.generated.h already included, missing '#pragma once' in DialogueAction.h"
#endif
#define DIALOGUETOOL_DialogueAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UObject;

// ********** Begin Class UDialogueAction **********************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ExecuteAction_Implementation(UObject* context); \
	DECLARE_FUNCTION(execExecuteAction);


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_CALLBACK_WRAPPERS
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueAction_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueAction(); \
	friend struct Z_Construct_UClass_UDialogueAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueAction, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueAction_NoRegister) \
	DECLARE_SERIALIZER(UDialogueAction)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueAction(UDialogueAction&&) = delete; \
	UDialogueAction(const UDialogueAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueAction); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueAction) \
	NO_API virtual ~UDialogueAction();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_11_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_CALLBACK_WRAPPERS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueAction;

// ********** End Class UDialogueAction ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
