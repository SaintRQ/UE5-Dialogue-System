// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueRoot.h"

#ifdef DIALOGUETOOL_DialogueRoot_generated_h
#error "DialogueRoot.generated.h already included, missing '#pragma once' in DialogueRoot.h"
#endif
#define DIALOGUETOOL_DialogueRoot_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FDialogueSwitcherCondition ****************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h_24_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics; \
	DIALOGUETOOL_API static class UScriptStruct* StaticStruct();


struct FDialogueSwitcherCondition;
// ********** End ScriptStruct FDialogueSwitcherCondition ******************************************

// ********** Begin ScriptStruct FDialogueSwitcher *************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h_42_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueSwitcher_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDialogueSwitcher;
// ********** End ScriptStruct FDialogueSwitcher ***************************************************

// ********** Begin ScriptStruct FDialogueTransit **************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h_54_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueTransit_Statics; \
	DIALOGUETOOL_API static class UScriptStruct* StaticStruct();


struct FDialogueTransit;
// ********** End ScriptStruct FDialogueTransit ****************************************************

// ********** Begin ScriptStruct FDialogueInit *****************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h_69_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueInit_Statics; \
	DIALOGUETOOL_API static class UScriptStruct* StaticStruct();


struct FDialogueInit;
// ********** End ScriptStruct FDialogueInit *******************************************************

// ********** Begin ScriptStruct FDialogueResponse *************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h_87_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueResponse_Statics; \
	DIALOGUETOOL_API static class UScriptStruct* StaticStruct();


struct FDialogueResponse;
// ********** End ScriptStruct FDialogueResponse ***************************************************

// ********** Begin ScriptStruct FDialogueNode *****************************************************
#define FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h_115_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDialogueNode_Statics; \
	DIALOGUETOOL_API static class UScriptStruct* StaticStruct();


struct FDialogueNode;
// ********** End ScriptStruct FDialogueNode *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h

// ********** Begin Enum EDialogueConditionVisibilityResult ****************************************
#define FOREACH_ENUM_EDIALOGUECONDITIONVISIBILITYRESULT(op) \
	op(EDialogueConditionVisibilityResult::VisibleSuccess) \
	op(EDialogueConditionVisibilityResult::VisibleFailure) \
	op(EDialogueConditionVisibilityResult::Invisible) 

enum class EDialogueConditionVisibilityResult : uint8;
template<> struct TIsUEnumClass<EDialogueConditionVisibilityResult> { enum { Value = true }; };
template<> DIALOGUETOOL_API UEnum* StaticEnum<EDialogueConditionVisibilityResult>();
// ********** End Enum EDialogueConditionVisibilityResult ******************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
