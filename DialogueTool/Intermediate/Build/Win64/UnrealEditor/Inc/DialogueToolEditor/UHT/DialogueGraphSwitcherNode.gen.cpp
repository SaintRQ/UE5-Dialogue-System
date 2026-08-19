// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphSwitcherNode.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphSwitcherNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueSwitcher();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSwitcherNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSwitcherNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphSwitcherNode ***********************************************
void UDialogueGraphSwitcherNode::StaticRegisterNativesUDialogueGraphSwitcherNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphSwitcherNode;
UClass* UDialogueGraphSwitcherNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphSwitcherNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphSwitcherNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphSwitcherNode"),
			Z_Registration_Info_UClass_UDialogueGraphSwitcherNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphSwitcherNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphSwitcherNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphSwitcherNode_NoRegister()
{
	return UDialogueGraphSwitcherNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphSwitcherNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphSwitcherNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwitcherNodeId_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphSwitcherNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClipboardSwitcherData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphSwitcherNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HasClipboardSwitcherData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphSwitcherNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SwitcherNodeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClipboardSwitcherData;
	static void NewProp_HasClipboardSwitcherData_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_HasClipboardSwitcherData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphSwitcherNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_SwitcherNodeId = { "SwitcherNodeId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphSwitcherNode, SwitcherNodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwitcherNodeId_MetaData), NewProp_SwitcherNodeId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_ClipboardSwitcherData = { "ClipboardSwitcherData", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphSwitcherNode, ClipboardSwitcherData), Z_Construct_UScriptStruct_FDialogueSwitcher, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClipboardSwitcherData_MetaData), NewProp_ClipboardSwitcherData_MetaData) }; // 26010884
void Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_HasClipboardSwitcherData_SetBit(void* Obj)
{
	((UDialogueGraphSwitcherNode*)Obj)->HasClipboardSwitcherData = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_HasClipboardSwitcherData = { "HasClipboardSwitcherData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueGraphSwitcherNode), &Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_HasClipboardSwitcherData_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HasClipboardSwitcherData_MetaData), NewProp_HasClipboardSwitcherData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_SwitcherNodeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_ClipboardSwitcherData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::NewProp_HasClipboardSwitcherData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::ClassParams = {
	&UDialogueGraphSwitcherNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphSwitcherNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphSwitcherNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphSwitcherNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphSwitcherNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphSwitcherNode.OuterSingleton;
}
UDialogueGraphSwitcherNode::UDialogueGraphSwitcherNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphSwitcherNode);
UDialogueGraphSwitcherNode::~UDialogueGraphSwitcherNode() {}
// ********** End Class UDialogueGraphSwitcherNode *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSwitcherNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphSwitcherNode, UDialogueGraphSwitcherNode::StaticClass, TEXT("UDialogueGraphSwitcherNode"), &Z_Registration_Info_UClass_UDialogueGraphSwitcherNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphSwitcherNode), 131436688U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSwitcherNode_h__Script_DialogueToolEditor_2247041962(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSwitcherNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSwitcherNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
