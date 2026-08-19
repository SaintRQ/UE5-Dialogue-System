// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueLibraryObject.h"

#ifdef DIALOGUETOOL_DialogueLibraryObject_generated_h
#error "DialogueLibraryObject.generated.h already included, missing '#pragma once' in DialogueLibraryObject.h"
#endif
#define DIALOGUETOOL_DialogueLibraryObject_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueLibraryObject ***************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueLibraryObject_NoRegister();

#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueLibraryObject(); \
	friend struct Z_Construct_UClass_UDialogueLibraryObject_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueLibraryObject_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueLibraryObject, UDialogueObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialogueTool"), Z_Construct_UClass_UDialogueLibraryObject_NoRegister) \
	DECLARE_SERIALIZER(UDialogueLibraryObject)


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueLibraryObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueLibraryObject(UDialogueLibraryObject&&) = delete; \
	UDialogueLibraryObject(const UDialogueLibraryObject&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueLibraryObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueLibraryObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueLibraryObject) \
	NO_API virtual ~UDialogueLibraryObject();


#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h_10_PROLOG
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h_13_INCLASS_NO_PURE_DECLS \
	FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueLibraryObject;

// ********** End Class UDialogueLibraryObject *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
