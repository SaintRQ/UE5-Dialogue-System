// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueGraphNode.h"

#ifdef DIALOGUETOOLEDITOR_DialogueGraphNode_generated_h
#error "DialogueGraphNode.generated.h already included, missing '#pragma once' in DialogueGraphNode.h"
#endif
#define DIALOGUETOOLEDITOR_DialogueGraphNode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueGraphNode *******************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphNode_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueGraphNode(); \
	friend struct Z_Construct_UClass_UDialogueGraphNode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphNode_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueGraphNode, UEdGraphNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueToolEditor"), Z_Construct_UClass_UDialogueGraphNode_NoRegister) \
	DECLARE_SERIALIZER(UDialogueGraphNode)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueGraphNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueGraphNode(UDialogueGraphNode&&) = delete; \
	UDialogueGraphNode(const UDialogueGraphNode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueGraphNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueGraphNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueGraphNode) \
	NO_API virtual ~UDialogueGraphNode();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h_11_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h_14_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueGraphNode;

// ********** End Class UDialogueGraphNode *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
