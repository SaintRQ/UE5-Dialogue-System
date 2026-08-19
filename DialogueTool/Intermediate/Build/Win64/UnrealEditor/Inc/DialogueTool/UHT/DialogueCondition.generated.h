// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueCondition.h"

#ifdef DIALOGUETOOL_DialogueCondition_generated_h
#error "DialogueCondition.generated.h already included, missing '#pragma once' in DialogueCondition.h"
#endif
#define DIALOGUETOOL_DialogueCondition_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UObject;

// ********** Begin Class UDialogueCondition *******************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ExecuteCondition_Implementation(UObject* context) const; \
	DECLARE_FUNCTION(execExecuteCondition);


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_CALLBACK_WRAPPERS
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueCondition(); \
	friend struct Z_Construct_UClass_UDialogueCondition_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueCondition, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueCondition_NoRegister) \
	DECLARE_SERIALIZER(UDialogueCondition)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueCondition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueCondition(UDialogueCondition&&) = delete; \
	UDialogueCondition(const UDialogueCondition&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueCondition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueCondition); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueCondition) \
	NO_API virtual ~UDialogueCondition();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_10_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_CALLBACK_WRAPPERS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueCondition;

// ********** End Class UDialogueCondition *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
