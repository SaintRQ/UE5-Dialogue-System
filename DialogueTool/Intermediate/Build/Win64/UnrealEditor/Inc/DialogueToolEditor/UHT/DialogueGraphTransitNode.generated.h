// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueGraphTransitNode.h"

#ifdef DIALOGUETOOLEDITOR_DialogueGraphTransitNode_generated_h
#error "DialogueGraphTransitNode.generated.h already included, missing '#pragma once' in DialogueGraphTransitNode.h"
#endif
#define DIALOGUETOOLEDITOR_DialogueGraphTransitNode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueGraphTransitNode ************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphTransitNode_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueGraphTransitNode(); \
	friend struct Z_Construct_UClass_UDialogueGraphTransitNode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphTransitNode_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueGraphTransitNode, UEdGraphNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueToolEditor"), Z_Construct_UClass_UDialogueGraphTransitNode_NoRegister) \
	DECLARE_SERIALIZER(UDialogueGraphTransitNode)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueGraphTransitNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueGraphTransitNode(UDialogueGraphTransitNode&&) = delete; \
	UDialogueGraphTransitNode(const UDialogueGraphTransitNode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueGraphTransitNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueGraphTransitNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueGraphTransitNode) \
	NO_API virtual ~UDialogueGraphTransitNode();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h_13_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h_16_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueGraphTransitNode;

// ********** End Class UDialogueGraphTransitNode **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
