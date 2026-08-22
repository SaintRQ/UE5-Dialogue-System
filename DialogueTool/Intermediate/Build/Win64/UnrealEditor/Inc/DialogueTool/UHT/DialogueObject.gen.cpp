// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueObject.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueObject();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueObject_NoRegister();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueInit();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueNode();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSkipText();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSwitcher();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueTransit();
ENGINE_API UClass* Z_Construct_UClass_UEdGraph_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueObject **********************************************************
void UDialogueObject::StaticRegisterNativesUDialogueObject()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueObject;
UClass* UDialogueObject::GetPrivateStaticClass()
{
	using TClass = UDialogueObject;
	if (!Z_Registration_Info_UClass_UDialogueObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueObject"),
			Z_Registration_Info_UClass_UDialogueObject.InnerSingleton,
			StaticRegisterNativesUDialogueObject,
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
	return Z_Registration_Info_UClass_UDialogueObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueObject_NoRegister()
{
	return UDialogueObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stores dialogue data. */" },
#endif
		{ "IncludePath", "DialogueObject.h" },
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stores dialogue data." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootID_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueInit_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueSwitchers_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueTransits_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueSkipTexts_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EditorGraph_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueObject.h" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_RootID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueInit_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DialogueInit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueNodes_ValueProp;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DialogueNodes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DialogueNodes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueSwitchers_ValueProp;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DialogueSwitchers_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DialogueSwitchers;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueTransits_ValueProp;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DialogueTransits_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DialogueTransits;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueSkipTexts_ValueProp;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DialogueSkipTexts_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DialogueSkipTexts;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EditorGraph;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_RootID = { "RootID", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, RootID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootID_MetaData), NewProp_RootID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueInit_Inner = { "DialogueInit", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueInit, METADATA_PARAMS(0, nullptr) }; // 321906102
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueInit = { "DialogueInit", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, DialogueInit), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueInit_MetaData), NewProp_DialogueInit_MetaData) }; // 321906102
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueNodes_ValueProp = { "DialogueNodes", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDialogueNode, METADATA_PARAMS(0, nullptr) }; // 633395235
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueNodes_Key_KeyProp = { "DialogueNodes_Key", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueNodes = { "DialogueNodes", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, DialogueNodes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueNodes_MetaData), NewProp_DialogueNodes_MetaData) }; // 633395235
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSwitchers_ValueProp = { "DialogueSwitchers", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDialogueSwitcher, METADATA_PARAMS(0, nullptr) }; // 26010884
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSwitchers_Key_KeyProp = { "DialogueSwitchers_Key", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSwitchers = { "DialogueSwitchers", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, DialogueSwitchers), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueSwitchers_MetaData), NewProp_DialogueSwitchers_MetaData) }; // 26010884
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueTransits_ValueProp = { "DialogueTransits", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDialogueTransit, METADATA_PARAMS(0, nullptr) }; // 2804408187
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueTransits_Key_KeyProp = { "DialogueTransits_Key", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueTransits = { "DialogueTransits", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, DialogueTransits), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueTransits_MetaData), NewProp_DialogueTransits_MetaData) }; // 2804408187
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSkipTexts_ValueProp = { "DialogueSkipTexts", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDialogueSkipText, METADATA_PARAMS(0, nullptr) }; // 348299129
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSkipTexts_Key_KeyProp = { "DialogueSkipTexts_Key", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSkipTexts = { "DialogueSkipTexts", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, DialogueSkipTexts), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueSkipTexts_MetaData), NewProp_DialogueSkipTexts_MetaData) }; // 348299129
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueObject_Statics::NewProp_EditorGraph = { "EditorGraph", nullptr, (EPropertyFlags)0x0144000800000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueObject, EditorGraph), Z_Construct_UClass_UEdGraph_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EditorGraph_MetaData), NewProp_EditorGraph_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_RootID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueInit_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueInit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueNodes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueNodes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueNodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSwitchers_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSwitchers_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSwitchers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueTransits_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueTransits_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueTransits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSkipTexts_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSkipTexts_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_DialogueSkipTexts,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueObject_Statics::NewProp_EditorGraph,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueObject_Statics::ClassParams = {
	&UDialogueObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueObject_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueObject_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueObject()
{
	if (!Z_Registration_Info_UClass_UDialogueObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueObject.OuterSingleton, Z_Construct_UClass_UDialogueObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueObject.OuterSingleton;
}
UDialogueObject::UDialogueObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueObject);
UDialogueObject::~UDialogueObject() {}
// ********** End Class UDialogueObject ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueObject, UDialogueObject::StaticClass, TEXT("UDialogueObject"), &Z_Registration_Info_UClass_UDialogueObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueObject), 2894898021U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h__Script_DialogueTool_2608862794(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueObject_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
