// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueGraphInitNode.h"

#ifdef DIALOGUETOOLEDITOR_DialogueGraphInitNode_generated_h
#error "DialogueGraphInitNode.generated.h already included, missing '#pragma once' in DialogueGraphInitNode.h"
#endif
#define DIALOGUETOOLEDITOR_DialogueGraphInitNode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueGraphInitNode ***************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphInitNode_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueGraphInitNode(); \
	friend struct Z_Construct_UClass_UDialogueGraphInitNode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphInitNode_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueGraphInitNode, UEdGraphNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueToolEditor"), Z_Construct_UClass_UDialogueGraphInitNode_NoRegister) \
	DECLARE_SERIALIZER(UDialogueGraphInitNode)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueGraphInitNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueGraphInitNode(UDialogueGraphInitNode&&) = delete; \
	UDialogueGraphInitNode(const UDialogueGraphInitNode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueGraphInitNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueGraphInitNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueGraphInitNode) \
	NO_API virtual ~UDialogueGraphInitNode();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h_11_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h_14_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueGraphInitNode;

// ********** End Class UDialogueGraphInitNode *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
