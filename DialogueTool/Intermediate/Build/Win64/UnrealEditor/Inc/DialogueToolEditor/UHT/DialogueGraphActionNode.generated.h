// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueGraphActionNode.h"

#ifdef DIALOGUETOOLEDITOR_DialogueGraphActionNode_generated_h
#error "DialogueGraphActionNode.generated.h already included, missing '#pragma once' in DialogueGraphActionNode.h"
#endif
#define DIALOGUETOOLEDITOR_DialogueGraphActionNode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueGraphActionNode *************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphActionNode_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueGraphActionNode(); \
	friend struct Z_Construct_UClass_UDialogueGraphActionNode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphActionNode_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueGraphActionNode, UEdGraphNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueToolEditor"), Z_Construct_UClass_UDialogueGraphActionNode_NoRegister) \
	DECLARE_SERIALIZER(UDialogueGraphActionNode)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueGraphActionNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueGraphActionNode(UDialogueGraphActionNode&&) = delete; \
	UDialogueGraphActionNode(const UDialogueGraphActionNode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueGraphActionNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueGraphActionNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueGraphActionNode) \
	NO_API virtual ~UDialogueGraphActionNode();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h_11_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h_14_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueGraphActionNode;

// ********** End Class UDialogueGraphActionNode ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphActionNode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
