// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueObjectFactory.h"

#ifdef DIALOGUETOOLEDITOR_DialogueObjectFactory_generated_h
#error "DialogueObjectFactory.generated.h already included, missing '#pragma once' in DialogueObjectFactory.h"
#endif
#define DIALOGUETOOLEDITOR_DialogueObjectFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueObjectFactory ***************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueObjectFactory_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueObjectFactory(); \
	friend struct Z_Construct_UClass_UDialogueObjectFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueObjectFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueObjectFactory, UFactory, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueToolEditor"), Z_Construct_UClass_UDialogueObjectFactory_NoRegister) \
	DECLARE_SERIALIZER(UDialogueObjectFactory)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueObjectFactory(UDialogueObjectFactory&&) = delete; \
	UDialogueObjectFactory(const UDialogueObjectFactory&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueObjectFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueObjectFactory); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDialogueObjectFactory) \
	NO_API virtual ~UDialogueObjectFactory();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h_10_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h_13_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueObjectFactory;

// ********** End Class UDialogueObjectFactory *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
