// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueManager.h"
#include "DialogueRoot.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueManager() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueAction_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueManager();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueManager_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueObject_NoRegister();
DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature();
DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature();
DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature();
DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueCache();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueResponse();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FDialogueTextUpdated **************************************************
struct Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics
{
	struct _Script_DialogueTool_eventDialogueTextUpdated_Parms
	{
		FText Text;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueTool_eventDialogueTextUpdated_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::NewProp_Text,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueTool, nullptr, "DialogueTextUpdated__DelegateSignature", Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueTextUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueTextUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueTextUpdated_DelegateWrapper(const FMulticastScriptDelegate& DialogueTextUpdated, FText const& Text)
{
	struct _Script_DialogueTool_eventDialogueTextUpdated_Parms
	{
		FText Text;
	};
	_Script_DialogueTool_eventDialogueTextUpdated_Parms Parms;
	Parms.Text=Text;
	DialogueTextUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueTextUpdated ****************************************************

// ********** Begin Delegate FDialogueResponsesUpdated *********************************************
struct Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics
{
	struct _Script_DialogueTool_eventDialogueResponsesUpdated_Parms
	{
		TArray<FDialogueResponse> Responses;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Responses_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Responses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Responses;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::NewProp_Responses_Inner = { "Responses", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueResponse, METADATA_PARAMS(0, nullptr) }; // 1685680349
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::NewProp_Responses = { "Responses", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueTool_eventDialogueResponsesUpdated_Parms, Responses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Responses_MetaData), NewProp_Responses_MetaData) }; // 1685680349
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::NewProp_Responses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::NewProp_Responses,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueTool, nullptr, "DialogueResponsesUpdated__DelegateSignature", Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueResponsesUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueResponsesUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueResponsesUpdated_DelegateWrapper(const FMulticastScriptDelegate& DialogueResponsesUpdated, TArray<FDialogueResponse> const& Responses)
{
	struct _Script_DialogueTool_eventDialogueResponsesUpdated_Parms
	{
		TArray<FDialogueResponse> Responses;
	};
	_Script_DialogueTool_eventDialogueResponsesUpdated_Parms Parms;
	Parms.Responses=Responses;
	DialogueResponsesUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueResponsesUpdated ***********************************************

// ********** Begin Delegate FDialogueFinished *****************************************************
struct Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics
{
	struct _Script_DialogueTool_eventDialogueFinished_Parms
	{
		FDialogueCache Cache;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cache_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Cache;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::NewProp_Cache = { "Cache", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueTool_eventDialogueFinished_Parms, Cache), Z_Construct_UScriptStruct_FDialogueCache, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cache_MetaData), NewProp_Cache_MetaData) }; // 750877882
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::NewProp_Cache,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueTool, nullptr, "DialogueFinished__DelegateSignature", Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueFinished_DelegateWrapper(const FMulticastScriptDelegate& DialogueFinished, FDialogueCache const& Cache)
{
	struct _Script_DialogueTool_eventDialogueFinished_Parms
	{
		FDialogueCache Cache;
	};
	_Script_DialogueTool_eventDialogueFinished_Parms Parms;
	Parms.Cache=Cache;
	DialogueFinished.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueFinished *******************************************************

// ********** Begin Delegate FDialogueSoundRequested ***********************************************
struct Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics
{
	struct _Script_DialogueTool_eventDialogueSoundRequested_Parms
	{
		USoundBase* Sound;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DialogueTool_eventDialogueSoundRequested_Parms, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::NewProp_Sound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DialogueTool, nullptr, "DialogueSoundRequested__DelegateSignature", Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueSoundRequested_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::_Script_DialogueTool_eventDialogueSoundRequested_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueSoundRequested_DelegateWrapper(const FMulticastScriptDelegate& DialogueSoundRequested, USoundBase* Sound)
{
	struct _Script_DialogueTool_eventDialogueSoundRequested_Parms
	{
		USoundBase* Sound;
	};
	_Script_DialogueTool_eventDialogueSoundRequested_Parms Parms;
	Parms.Sound=Sound;
	DialogueSoundRequested.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueSoundRequested *************************************************

// ********** Begin Class UDialogueManager Function ContinueDialogue *******************************
struct Z_Construct_UFunction_UDialogueManager_ContinueDialogue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Completes animated text or advances to the next dialogue text entry.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Completes animated text or advances to the next dialogue text entry." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueManager_ContinueDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueManager, nullptr, "ContinueDialogue", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_ContinueDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueManager_ContinueDialogue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueManager_ContinueDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueManager_ContinueDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueManager::execContinueDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ContinueDialogue();
	P_NATIVE_END;
}
// ********** End Class UDialogueManager Function ContinueDialogue *********************************

// ********** Begin Class UDialogueManager Function FinishDialogue *********************************
struct Z_Construct_UFunction_UDialogueManager_FinishDialogue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stops the active dialogue and broadcasts its completion.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stops the active dialogue and broadcasts its completion." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueManager_FinishDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueManager, nullptr, "FinishDialogue", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_FinishDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueManager_FinishDialogue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueManager_FinishDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueManager_FinishDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueManager::execFinishDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishDialogue();
	P_NATIVE_END;
}
// ********** End Class UDialogueManager Function FinishDialogue ***********************************

// ********** Begin Class UDialogueManager Function GetDialogueCache *******************************
struct Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics
{
	struct DialogueManager_eventGetDialogueCache_Parms
	{
		FDialogueCache ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Returns the cache currently used by dialogue playback.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the cache currently used by dialogue playback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueManager_eventGetDialogueCache_Parms, ReturnValue), Z_Construct_UScriptStruct_FDialogueCache, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 750877882
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueManager, nullptr, "GetDialogueCache", Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::DialogueManager_eventGetDialogueCache_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::DialogueManager_eventGetDialogueCache_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueManager_GetDialogueCache()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueManager_GetDialogueCache_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueManager::execGetDialogueCache)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDialogueCache*)Z_Param__Result=P_THIS->GetDialogueCache();
	P_NATIVE_END;
}
// ********** End Class UDialogueManager Function GetDialogueCache *********************************

// ********** Begin Class UDialogueManager Function IsWaitingForContinue ***************************
struct Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics
{
	struct DialogueManager_eventIsWaitingForContinue_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Returns whether dialogue playback is waiting for explicit continue input.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns whether dialogue playback is waiting for explicit continue input." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueManager_eventIsWaitingForContinue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueManager_eventIsWaitingForContinue_Parms), &Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueManager, nullptr, "IsWaitingForContinue", Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::DialogueManager_eventIsWaitingForContinue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::DialogueManager_eventIsWaitingForContinue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueManager::execIsWaitingForContinue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWaitingForContinue();
	P_NATIVE_END;
}
// ********** End Class UDialogueManager Function IsWaitingForContinue *****************************

// ********** Begin Class UDialogueManager Function SelectResponse *********************************
struct Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics
{
	struct DialogueManager_eventSelectResponse_Parms
	{
		int32 responseIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Selects a successful response by its displayed array index.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selects a successful response by its displayed array index." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_responseIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::NewProp_responseIndex = { "responseIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueManager_eventSelectResponse_Parms, responseIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::NewProp_responseIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueManager, nullptr, "SelectResponse", Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::DialogueManager_eventSelectResponse_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::DialogueManager_eventSelectResponse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueManager_SelectResponse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueManager_SelectResponse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueManager::execSelectResponse)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_responseIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectResponse(Z_Param_responseIndex);
	P_NATIVE_END;
}
// ********** End Class UDialogueManager Function SelectResponse ***********************************

// ********** Begin Class UDialogueManager Function StartDialogue **********************************
struct Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics
{
	struct DialogueManager_eventStartDialogue_Parms
	{
		UDialogueObject* dialogue;
		FDialogueCache cache;
		UObject* context;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Starts the first initialization entry whose conditions succeed.\n" },
#endif
		{ "CPP_Default_context", "None" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts the first initialization entry whose conditions succeed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cache_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_dialogue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_cache;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_dialogue = { "dialogue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueManager_eventStartDialogue_Parms, dialogue), Z_Construct_UClass_UDialogueObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_cache = { "cache", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueManager_eventStartDialogue_Parms, cache), Z_Construct_UScriptStruct_FDialogueCache, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cache_MetaData), NewProp_cache_MetaData) }; // 750877882
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueManager_eventStartDialogue_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueManager_eventStartDialogue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueManager_eventStartDialogue_Parms), &Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_dialogue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_cache,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueManager, nullptr, "StartDialogue", Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::DialogueManager_eventStartDialogue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::DialogueManager_eventStartDialogue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueManager_StartDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueManager_StartDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueManager::execStartDialogue)
{
	P_GET_OBJECT(UDialogueObject,Z_Param_dialogue);
	P_GET_STRUCT_REF(FDialogueCache,Z_Param_Out_cache);
	P_GET_OBJECT(UObject,Z_Param_context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartDialogue(Z_Param_dialogue,Z_Param_Out_cache,Z_Param_context);
	P_NATIVE_END;
}
// ********** End Class UDialogueManager Function StartDialogue ************************************

// ********** Begin Class UDialogueManager *********************************************************
void UDialogueManager::StaticRegisterNativesUDialogueManager()
{
	UClass* Class = UDialogueManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ContinueDialogue", &UDialogueManager::execContinueDialogue },
		{ "FinishDialogue", &UDialogueManager::execFinishDialogue },
		{ "GetDialogueCache", &UDialogueManager::execGetDialogueCache },
		{ "IsWaitingForContinue", &UDialogueManager::execIsWaitingForContinue },
		{ "SelectResponse", &UDialogueManager::execSelectResponse },
		{ "StartDialogue", &UDialogueManager::execStartDialogue },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueManager;
UClass* UDialogueManager::GetPrivateStaticClass()
{
	using TClass = UDialogueManager;
	if (!Z_Registration_Info_UClass_UDialogueManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueManager"),
			Z_Registration_Info_UClass_UDialogueManager.InnerSingleton,
			StaticRegisterNativesUDialogueManager,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UDialogueManager.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueManager_NoRegister()
{
	return UDialogueManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueManager.h" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnUpdateText_MetaData[] = {
		{ "Category", "Dialogue Tool|Events" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnUpdateResponses_MetaData[] = {
		{ "Category", "Dialogue Tool|Events" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDialogueFinished_MetaData[] = {
		{ "Category", "Dialogue Tool|Events" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaySound_MetaData[] = {
		{ "Category", "Dialogue Tool|Events" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveDialogue_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PendingActions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentResponses_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueCache_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousDialogue_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousReturnActions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUpdateText;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUpdateResponses;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDialogueFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaySound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveDialogue;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_DialogueContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PendingActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PendingActions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentResponses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentResponses;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueCache;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviousDialogue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviousReturnActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PreviousReturnActions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueManager_ContinueDialogue, "ContinueDialogue" }, // 1103045006
		{ &Z_Construct_UFunction_UDialogueManager_FinishDialogue, "FinishDialogue" }, // 366372134
		{ &Z_Construct_UFunction_UDialogueManager_GetDialogueCache, "GetDialogueCache" }, // 2766490315
		{ &Z_Construct_UFunction_UDialogueManager_IsWaitingForContinue, "IsWaitingForContinue" }, // 1376031000
		{ &Z_Construct_UFunction_UDialogueManager_SelectResponse, "SelectResponse" }, // 2656738373
		{ &Z_Construct_UFunction_UDialogueManager_StartDialogue, "StartDialogue" }, // 830084193
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnUpdateText = { "OnUpdateText", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, OnUpdateText), Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnUpdateText_MetaData), NewProp_OnUpdateText_MetaData) }; // 1065609865
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnUpdateResponses = { "OnUpdateResponses", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, OnUpdateResponses), Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnUpdateResponses_MetaData), NewProp_OnUpdateResponses_MetaData) }; // 2981190284
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnDialogueFinished = { "OnDialogueFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, OnDialogueFinished), Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDialogueFinished_MetaData), NewProp_OnDialogueFinished_MetaData) }; // 2054464080
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnPlaySound = { "OnPlaySound", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, OnPlaySound), Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlaySound_MetaData), NewProp_OnPlaySound_MetaData) }; // 2210178737
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_ActiveDialogue = { "ActiveDialogue", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, ActiveDialogue), Z_Construct_UClass_UDialogueObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveDialogue_MetaData), NewProp_ActiveDialogue_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_DialogueContext = { "DialogueContext", nullptr, (EPropertyFlags)0x0044000000002000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, DialogueContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueContext_MetaData), NewProp_DialogueContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_PendingActions_Inner = { "PendingActions", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_PendingActions = { "PendingActions", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, PendingActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PendingActions_MetaData), NewProp_PendingActions_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_CurrentResponses_Inner = { "CurrentResponses", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueResponse, METADATA_PARAMS(0, nullptr) }; // 1685680349
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_CurrentResponses = { "CurrentResponses", nullptr, (EPropertyFlags)0x0040008000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, CurrentResponses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentResponses_MetaData), NewProp_CurrentResponses_MetaData) }; // 1685680349
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_DialogueCache = { "DialogueCache", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, DialogueCache), Z_Construct_UScriptStruct_FDialogueCache, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueCache_MetaData), NewProp_DialogueCache_MetaData) }; // 750877882
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_PreviousDialogue = { "PreviousDialogue", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, PreviousDialogue), Z_Construct_UClass_UDialogueObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousDialogue_MetaData), NewProp_PreviousDialogue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_PreviousReturnActions_Inner = { "PreviousReturnActions", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_PreviousReturnActions = { "PreviousReturnActions", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, PreviousReturnActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousReturnActions_MetaData), NewProp_PreviousReturnActions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnUpdateText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnUpdateResponses,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnDialogueFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_OnPlaySound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_ActiveDialogue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_DialogueContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_PendingActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_PendingActions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_CurrentResponses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_CurrentResponses,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_DialogueCache,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_PreviousDialogue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_PreviousReturnActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_PreviousReturnActions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueManager_Statics::ClassParams = {
	&UDialogueManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDialogueManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueManager()
{
	if (!Z_Registration_Info_UClass_UDialogueManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueManager.OuterSingleton, Z_Construct_UClass_UDialogueManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueManager.OuterSingleton;
}
UDialogueManager::UDialogueManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueManager);
UDialogueManager::~UDialogueManager() {}
// ********** End Class UDialogueManager ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueManager, UDialogueManager::StaticClass, TEXT("UDialogueManager"), &Z_Registration_Info_UClass_UDialogueManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueManager), 503462171U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h__Script_DialogueTool_1605476536(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueManager_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
