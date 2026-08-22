// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphSkipTextNode.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphSkipTextNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSkipText();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSkipTextNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSkipTextNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphSkipTextNode ***********************************************
void UDialogueGraphSkipTextNode::StaticRegisterNativesUDialogueGraphSkipTextNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphSkipTextNode;
UClass* UDialogueGraphSkipTextNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphSkipTextNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphSkipTextNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphSkipTextNode"),
			Z_Registration_Info_UClass_UDialogueGraphSkipTextNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphSkipTextNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphSkipTextNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphSkipTextNode_NoRegister()
{
	return UDialogueGraphSkipTextNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphSkipTextNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphSkipTextNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkipTextNodeId_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphSkipTextNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClipboardSkipTextData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphSkipTextNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HasClipboardSkipTextData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphSkipTextNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SkipTextNodeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClipboardSkipTextData;
	static void NewProp_HasClipboardSkipTextData_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_HasClipboardSkipTextData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphSkipTextNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_SkipTextNodeId = { "SkipTextNodeId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphSkipTextNode, SkipTextNodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkipTextNodeId_MetaData), NewProp_SkipTextNodeId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_ClipboardSkipTextData = { "ClipboardSkipTextData", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphSkipTextNode, ClipboardSkipTextData), Z_Construct_UScriptStruct_FDialogueSkipText, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClipboardSkipTextData_MetaData), NewProp_ClipboardSkipTextData_MetaData) }; // 348299129
void Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_HasClipboardSkipTextData_SetBit(void* Obj)
{
	((UDialogueGraphSkipTextNode*)Obj)->HasClipboardSkipTextData = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_HasClipboardSkipTextData = { "HasClipboardSkipTextData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueGraphSkipTextNode), &Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_HasClipboardSkipTextData_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HasClipboardSkipTextData_MetaData), NewProp_HasClipboardSkipTextData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_SkipTextNodeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_ClipboardSkipTextData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::NewProp_HasClipboardSkipTextData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::ClassParams = {
	&UDialogueGraphSkipTextNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphSkipTextNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphSkipTextNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphSkipTextNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphSkipTextNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphSkipTextNode.OuterSingleton;
}
UDialogueGraphSkipTextNode::UDialogueGraphSkipTextNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphSkipTextNode);
UDialogueGraphSkipTextNode::~UDialogueGraphSkipTextNode() {}
// ********** End Class UDialogueGraphSkipTextNode *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSkipTextNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphSkipTextNode, UDialogueGraphSkipTextNode::StaticClass, TEXT("UDialogueGraphSkipTextNode"), &Z_Registration_Info_UClass_UDialogueGraphSkipTextNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphSkipTextNode), 3199156960U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSkipTextNode_h__Script_DialogueToolEditor_2971051519(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSkipTextNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSkipTextNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
