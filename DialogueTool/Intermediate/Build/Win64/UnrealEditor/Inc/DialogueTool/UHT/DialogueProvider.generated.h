// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueProvider.h"

#ifdef DIALOGUETOOL_DialogueProvider_generated_h
#error "DialogueProvider.generated.h already included, missing '#pragma once' in DialogueProvider.h"
#endif
#define DIALOGUETOOL_DialogueProvider_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UObject;
struct FDialogueCache;

// ********** Begin Class UDialogueProvider ********************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteProvider);


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_CALLBACK_WRAPPERS
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueProvider_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueProvider(); \
	friend struct Z_Construct_UClass_UDialogueProvider_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueProvider_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueProvider, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueProvider_NoRegister) \
	DECLARE_SERIALIZER(UDialogueProvider)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueProvider(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueProvider(UDialogueProvider&&) = delete; \
	UDialogueProvider(const UDialogueProvider&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueProvider); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueProvider); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueProvider) \
	NO_API virtual ~UDialogueProvider();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_10_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_CALLBACK_WRAPPERS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueProvider;

// ********** End Class UDialogueProvider **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
