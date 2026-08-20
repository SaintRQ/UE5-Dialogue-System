// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphNode.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphNode *******************************************************
void UDialogueGraphNode::StaticRegisterNativesUDialogueGraphNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphNode;
UClass* UDialogueGraphNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphNode"),
			Z_Registration_Info_UClass_UDialogueGraphNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphNode_NoRegister()
{
	return UDialogueGraphNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueNodeId_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClipboardDialogueData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HasClipboardDialogueData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DialogueNodeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClipboardDialogueData;
	static void NewProp_HasClipboardDialogueData_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_HasClipboardDialogueData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_DialogueNodeId = { "DialogueNodeId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphNode, DialogueNodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueNodeId_MetaData), NewProp_DialogueNodeId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_ClipboardDialogueData = { "ClipboardDialogueData", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphNode, ClipboardDialogueData), Z_Construct_UScriptStruct_FDialogueNode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClipboardDialogueData_MetaData), NewProp_ClipboardDialogueData_MetaData) }; // 3295821771
void Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_HasClipboardDialogueData_SetBit(void* Obj)
{
	((UDialogueGraphNode*)Obj)->HasClipboardDialogueData = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_HasClipboardDialogueData = { "HasClipboardDialogueData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueGraphNode), &Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_HasClipboardDialogueData_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HasClipboardDialogueData_MetaData), NewProp_HasClipboardDialogueData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueGraphNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_DialogueNodeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_ClipboardDialogueData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphNode_Statics::NewProp_HasClipboardDialogueData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueGraphNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphNode_Statics::ClassParams = {
	&UDialogueGraphNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueGraphNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphNode_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphNode.OuterSingleton;
}
UDialogueGraphNode::UDialogueGraphNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphNode);
UDialogueGraphNode::~UDialogueGraphNode() {}
// ********** End Class UDialogueGraphNode *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphNode, UDialogueGraphNode::StaticClass, TEXT("UDialogueGraphNode"), &Z_Registration_Info_UClass_UDialogueGraphNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphNode), 575491711U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h__Script_DialogueToolEditor_1571510663(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
