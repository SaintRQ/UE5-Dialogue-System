// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueRoot() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueAction_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueLibraryObject_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueProvider_NoRegister();
DIALOGUETOOL_API UEnum* Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueCache();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueInit();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueNode();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueResponse();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSwitcher();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSwitcherCondition();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueTransit();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EDialogueConditionVisibilityResult ****************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult;
static UEnum* EDialogueConditionVisibilityResult_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("EDialogueConditionVisibilityResult"));
	}
	return Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult.OuterSingleton;
}
template<> DIALOGUETOOL_API UEnum* StaticEnum<EDialogueConditionVisibilityResult>()
{
	return EDialogueConditionVisibilityResult_StaticEnum();
}
struct Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
		{ "VisibleFailure.Name", "EDialogueConditionVisibilityResult::VisibleFailure" },
		{ "VisibleSuccess.Name", "EDialogueConditionVisibilityResult::VisibleSuccess" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueConditionVisibilityResult::VisibleSuccess", (int64)EDialogueConditionVisibilityResult::VisibleSuccess },
		{ "EDialogueConditionVisibilityResult::VisibleFailure", (int64)EDialogueConditionVisibilityResult::VisibleFailure },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	"EDialogueConditionVisibilityResult",
	"EDialogueConditionVisibilityResult",
	Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult()
{
	if (!Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult.InnerSingleton, Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult.InnerSingleton;
}
// ********** End Enum EDialogueConditionVisibilityResult ******************************************

// ********** Begin ScriptStruct FDialogueCache ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueCache;
class UScriptStruct* FDialogueCache::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueCache.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueCache.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueCache, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueCache"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueCache.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueCache_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsFirstTalk_MetaData[] = {
		{ "Category", "DialogueCache" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopicsMemory_MetaData[] = {
		{ "Category", "DialogueCache" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResponsesMemory_MetaData[] = {
		{ "Category", "DialogueCache" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static void NewProp_IsFirstTalk_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsFirstTalk;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TopicsMemory_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_TopicsMemory;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ResponsesMemory_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_ResponsesMemory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueCache>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_IsFirstTalk_SetBit(void* Obj)
{
	((FDialogueCache*)Obj)->IsFirstTalk = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_IsFirstTalk = { "IsFirstTalk", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueCache), &Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_IsFirstTalk_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsFirstTalk_MetaData), NewProp_IsFirstTalk_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_TopicsMemory_ElementProp = { "TopicsMemory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_TopicsMemory = { "TopicsMemory", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueCache, TopicsMemory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopicsMemory_MetaData), NewProp_TopicsMemory_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_ResponsesMemory_ElementProp = { "ResponsesMemory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_ResponsesMemory = { "ResponsesMemory", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueCache, ResponsesMemory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResponsesMemory_MetaData), NewProp_ResponsesMemory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueCache_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_IsFirstTalk,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_TopicsMemory_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_TopicsMemory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_ResponsesMemory_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueCache_Statics::NewProp_ResponsesMemory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueCache_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueCache_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueCache",
	Z_Construct_UScriptStruct_FDialogueCache_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueCache_Statics::PropPointers),
	sizeof(FDialogueCache),
	alignof(FDialogueCache),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueCache_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueCache_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueCache()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueCache.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueCache.InnerSingleton, Z_Construct_UScriptStruct_FDialogueCache_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueCache.InnerSingleton;
}
// ********** End ScriptStruct FDialogueCache ******************************************************

// ********** Begin ScriptStruct FDialogueSwitcherCondition ****************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition;
class UScriptStruct* FDialogueSwitcherCondition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueSwitcherCondition, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueSwitcherCondition"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Conditions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Conditions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NextNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueSwitcherCondition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSwitcherCondition, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Conditions_Inner = { "Conditions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueCondition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_Inner_MetaData), NewProp_Conditions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Conditions = { "Conditions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSwitcherCondition, Conditions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_MetaData), NewProp_Conditions_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_Inner_MetaData), NewProp_Actions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSwitcherCondition, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_MetaData), NewProp_Actions_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_NextNode = { "NextNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSwitcherCondition, NextNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextNode_MetaData), NewProp_NextNode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Conditions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Conditions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Actions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_Actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewProp_NextNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueSwitcherCondition",
	Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::PropPointers),
	sizeof(FDialogueSwitcherCondition),
	alignof(FDialogueSwitcherCondition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueSwitcherCondition()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition.InnerSingleton, Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition.InnerSingleton;
}
// ********** End ScriptStruct FDialogueSwitcherCondition ******************************************

// ********** Begin ScriptStruct FDialogueSwitcher *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueSwitcher;
class UScriptStruct* FDialogueSwitcher::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueSwitcher.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueSwitcher.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueSwitcher, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueSwitcher"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueSwitcher.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueSwitcher_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Conditions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Conditions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueSwitcher>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::NewProp_Conditions_Inner = { "Conditions", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueSwitcherCondition, METADATA_PARAMS(0, nullptr) }; // 2143429039
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::NewProp_Conditions = { "Conditions", nullptr, (EPropertyFlags)0x0010008000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueSwitcher, Conditions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_MetaData), NewProp_Conditions_MetaData) }; // 2143429039
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::NewProp_Conditions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::NewProp_Conditions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueSwitcher",
	Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::PropPointers),
	sizeof(FDialogueSwitcher),
	alignof(FDialogueSwitcher),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueSwitcher()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueSwitcher.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueSwitcher.InnerSingleton, Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueSwitcher.InnerSingleton;
}
// ********** End ScriptStruct FDialogueSwitcher ***************************************************

// ********** Begin ScriptStruct FDialogueTransit **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueTransit;
class UScriptStruct* FDialogueTransit::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueTransit.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueTransit.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueTransit, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueTransit"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueTransit.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueTransit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueLibrary_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnActions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnActions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DialogueLibrary;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnActions;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueTransit>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_DialogueLibrary = { "DialogueLibrary", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueTransit, DialogueLibrary), Z_Construct_UClass_UDialogueLibraryObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueLibrary_MetaData), NewProp_DialogueLibrary_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_ReturnActions_Inner = { "ReturnActions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnActions_Inner_MetaData), NewProp_ReturnActions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_ReturnActions = { "ReturnActions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueTransit, ReturnActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnActions_MetaData), NewProp_ReturnActions_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_ReturnNode = { "ReturnNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueTransit, ReturnNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnNode_MetaData), NewProp_ReturnNode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueTransit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_DialogueLibrary,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_ReturnActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_ReturnActions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewProp_ReturnNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueTransit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueTransit_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueTransit",
	Z_Construct_UScriptStruct_FDialogueTransit_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueTransit_Statics::PropPointers),
	sizeof(FDialogueTransit),
	alignof(FDialogueTransit),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueTransit_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueTransit_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueTransit()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueTransit.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueTransit.InnerSingleton, Z_Construct_UScriptStruct_FDialogueTransit_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueTransit.InnerSingleton;
}
// ********** End ScriptStruct FDialogueTransit ****************************************************

// ********** Begin ScriptStruct FDialogueInit *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueInit;
class UScriptStruct* FDialogueInit::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueInit.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueInit.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueInit, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueInit"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueInit.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueInit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Conditions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Conditions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NextNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueInit>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueInit, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Conditions_Inner = { "Conditions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueCondition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_Inner_MetaData), NewProp_Conditions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Conditions = { "Conditions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueInit, Conditions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_MetaData), NewProp_Conditions_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_Inner_MetaData), NewProp_Actions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueInit, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_MetaData), NewProp_Actions_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_NextNode = { "NextNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueInit, NextNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextNode_MetaData), NewProp_NextNode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueInit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Conditions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Conditions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Actions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_Actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueInit_Statics::NewProp_NextNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueInit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueInit_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueInit",
	Z_Construct_UScriptStruct_FDialogueInit_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueInit_Statics::PropPointers),
	sizeof(FDialogueInit),
	alignof(FDialogueInit),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueInit_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueInit_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueInit()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueInit.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueInit.InnerSingleton, Z_Construct_UScriptStruct_FDialogueInit_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueInit.InnerSingleton;
}
// ********** End ScriptStruct FDialogueInit *******************************************************

// ********** Begin ScriptStruct FDialogueResponse *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueResponse;
class UScriptStruct* FDialogueResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueResponse, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueResponse"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueResponse.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Response_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomTextId_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResponseProvider_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Conditions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlwaysVisible_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Visibility_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinishDialogue_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ID;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Response;
	static const UECodeGen_Private::FNamePropertyParams NewProp_CustomTextId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResponseProvider;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Conditions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Conditions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NextNode;
	static void NewProp_AlwaysVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_AlwaysVisible;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Visibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Visibility;
	static void NewProp_FinishDialogue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_FinishDialogue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, ID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ID_MetaData), NewProp_ID_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Response = { "Response", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, Response), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Response_MetaData), NewProp_Response_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_CustomTextId = { "CustomTextId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, CustomTextId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomTextId_MetaData), NewProp_CustomTextId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_ResponseProvider = { "ResponseProvider", nullptr, (EPropertyFlags)0x011600000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, ResponseProvider), Z_Construct_UClass_UDialogueProvider_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResponseProvider_MetaData), NewProp_ResponseProvider_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0014000000000014, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sound_MetaData), NewProp_Sound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Conditions_Inner = { "Conditions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueCondition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_Inner_MetaData), NewProp_Conditions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Conditions = { "Conditions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, Conditions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Conditions_MetaData), NewProp_Conditions_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_Inner_MetaData), NewProp_Actions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_MetaData), NewProp_Actions_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_NextNode = { "NextNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, NextNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextNode_MetaData), NewProp_NextNode_MetaData) };
void Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_AlwaysVisible_SetBit(void* Obj)
{
	((FDialogueResponse*)Obj)->AlwaysVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_AlwaysVisible = { "AlwaysVisible", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueResponse), &Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_AlwaysVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlwaysVisible_MetaData), NewProp_AlwaysVisible_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Visibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Visibility = { "Visibility", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueResponse, Visibility), Z_Construct_UEnum_DialogueTool_EDialogueConditionVisibilityResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Visibility_MetaData), NewProp_Visibility_MetaData) }; // 826268928
void Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_FinishDialogue_SetBit(void* Obj)
{
	((FDialogueResponse*)Obj)->FinishDialogue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_FinishDialogue = { "FinishDialogue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueResponse), &Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_FinishDialogue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinishDialogue_MetaData), NewProp_FinishDialogue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Response,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_CustomTextId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_ResponseProvider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Sound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Conditions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Conditions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Actions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_NextNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_AlwaysVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Visibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_Visibility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewProp_FinishDialogue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueResponse",
	Z_Construct_UScriptStruct_FDialogueResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueResponse_Statics::PropPointers),
	sizeof(FDialogueResponse),
	alignof(FDialogueResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueResponse()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueResponse.InnerSingleton, Z_Construct_UScriptStruct_FDialogueResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueResponse.InnerSingleton;
}
// ********** End ScriptStruct FDialogueResponse ***************************************************

// ********** Begin ScriptStruct FDialogueNode *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueNode;
class UScriptStruct* FDialogueNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueNode, (UObject*)Z_Construct_UPackage__Script_DialogueTool(), TEXT("DialogueNode"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueNode.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDialogueNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsRoot_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootText_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootTextProviders_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootTextProviders_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootSounds_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Response_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueRoot.h" },
	};
#endif // WITH_METADATA
	static void NewProp_IsRoot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsRoot;
	static const UECodeGen_Private::FTextPropertyParams NewProp_RootText_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RootText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootTextProviders_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RootTextProviders;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_RootSounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RootSounds;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Response_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Response;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NextNode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueNode>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_IsRoot_SetBit(void* Obj)
{
	((FDialogueNode*)Obj)->IsRoot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_IsRoot = { "IsRoot", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueNode), &Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_IsRoot_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsRoot_MetaData), NewProp_IsRoot_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootText_Inner = { "RootText", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootText = { "RootText", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueNode, RootText), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootText_MetaData), NewProp_RootText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootTextProviders_Inner = { "RootTextProviders", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueProvider_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootTextProviders_Inner_MetaData), NewProp_RootTextProviders_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootTextProviders = { "RootTextProviders", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueNode, RootTextProviders), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootTextProviders_MetaData), NewProp_RootTextProviders_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootSounds_Inner = { "RootSounds", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootSounds = { "RootSounds", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueNode, RootSounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootSounds_MetaData), NewProp_RootSounds_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDialogueAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_Inner_MetaData), NewProp_Actions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0114008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueNode, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_MetaData), NewProp_Actions_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Response_Inner = { "Response", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueResponse, METADATA_PARAMS(0, nullptr) }; // 2606682219
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Response = { "Response", nullptr, (EPropertyFlags)0x0010008000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueNode, Response), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Response_MetaData), NewProp_Response_MetaData) }; // 2606682219
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_NextNode = { "NextNode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueNode, NextNode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextNode_MetaData), NewProp_NextNode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_IsRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootText_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootTextProviders_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootTextProviders,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootSounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_RootSounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Actions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Response_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_Response,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueNode_Statics::NewProp_NextNode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueNode_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
	nullptr,
	&NewStructOps,
	"DialogueNode",
	Z_Construct_UScriptStruct_FDialogueNode_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueNode_Statics::PropPointers),
	sizeof(FDialogueNode),
	alignof(FDialogueNode),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueNode_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueNode()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueNode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueNode.InnerSingleton, Z_Construct_UScriptStruct_FDialogueNode_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDialogueNode.InnerSingleton;
}
// ********** End ScriptStruct FDialogueNode *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h__Script_DialogueTool_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDialogueConditionVisibilityResult_StaticEnum, TEXT("EDialogueConditionVisibilityResult"), &Z_Registration_Info_UEnum_EDialogueConditionVisibilityResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 826268928U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDialogueCache::StaticStruct, Z_Construct_UScriptStruct_FDialogueCache_Statics::NewStructOps, TEXT("DialogueCache"), &Z_Registration_Info_UScriptStruct_FDialogueCache, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueCache), 2268999594U) },
		{ FDialogueSwitcherCondition::StaticStruct, Z_Construct_UScriptStruct_FDialogueSwitcherCondition_Statics::NewStructOps, TEXT("DialogueSwitcherCondition"), &Z_Registration_Info_UScriptStruct_FDialogueSwitcherCondition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueSwitcherCondition), 2143429039U) },
		{ FDialogueSwitcher::StaticStruct, Z_Construct_UScriptStruct_FDialogueSwitcher_Statics::NewStructOps, TEXT("DialogueSwitcher"), &Z_Registration_Info_UScriptStruct_FDialogueSwitcher, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueSwitcher), 26010884U) },
		{ FDialogueTransit::StaticStruct, Z_Construct_UScriptStruct_FDialogueTransit_Statics::NewStructOps, TEXT("DialogueTransit"), &Z_Registration_Info_UScriptStruct_FDialogueTransit, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueTransit), 2804408187U) },
		{ FDialogueInit::StaticStruct, Z_Construct_UScriptStruct_FDialogueInit_Statics::NewStructOps, TEXT("DialogueInit"), &Z_Registration_Info_UScriptStruct_FDialogueInit, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueInit), 321906102U) },
		{ FDialogueResponse::StaticStruct, Z_Construct_UScriptStruct_FDialogueResponse_Statics::NewStructOps, TEXT("DialogueResponse"), &Z_Registration_Info_UScriptStruct_FDialogueResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueResponse), 2606682219U) },
		{ FDialogueNode::StaticStruct, Z_Construct_UScriptStruct_FDialogueNode_Statics::NewStructOps, TEXT("DialogueNode"), &Z_Registration_Info_UScriptStruct_FDialogueNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueNode), 633395235U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h__Script_DialogueTool_1026569182(TEXT("/Script/DialogueTool"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h__Script_DialogueTool_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h__Script_DialogueTool_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h__Script_DialogueTool_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueRoot_h__Script_DialogueTool_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
