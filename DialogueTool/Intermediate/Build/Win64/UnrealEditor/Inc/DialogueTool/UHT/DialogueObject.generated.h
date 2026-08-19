// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueObject.h"

#ifdef DIALOGUETOOL_DialogueObject_generated_h
#error "DialogueObject.generated.h already included, missing '#pragma once' in DialogueObject.h"
#endif
#define DIALOGUETOOL_DialogueObject_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueObject **********************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueObject_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueObject(); \
	friend struct Z_Construct_UClass_UDialogueObject_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueObject_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueObject_NoRegister) \
	DECLARE_SERIALIZER(UDialogueObject)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueObject(UDialogueObject&&) = delete; \
	UDialogueObject(const UDialogueObject&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueObject) \
	NO_API virtual ~UDialogueObject();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h_14_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h_17_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueObject;

// ********** End Class UDialogueObject ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
