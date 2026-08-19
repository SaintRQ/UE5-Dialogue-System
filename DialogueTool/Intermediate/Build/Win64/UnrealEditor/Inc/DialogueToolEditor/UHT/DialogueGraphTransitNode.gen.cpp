// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphTransitNode.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphTransitNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueTransit();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphTransitNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphTransitNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphTransitNode ************************************************
void UDialogueGraphTransitNode::StaticRegisterNativesUDialogueGraphTransitNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphTransitNode;
UClass* UDialogueGraphTransitNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphTransitNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphTransitNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphTransitNode"),
			Z_Registration_Info_UClass_UDialogueGraphTransitNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphTransitNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphTransitNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphTransitNode_NoRegister()
{
	return UDialogueGraphTransitNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphTransitNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphTransitNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphTransitNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitNodeId_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphTransitNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClipboardTransitData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphTransitNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HasClipboardTransitData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueGraphTransitNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TransitNodeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClipboardTransitData;
	static void NewProp_HasClipboardTransitData_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_HasClipboardTransitData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphTransitNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_TransitNodeId = { "TransitNodeId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphTransitNode, TransitNodeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitNodeId_MetaData), NewProp_TransitNodeId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_ClipboardTransitData = { "ClipboardTransitData", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphTransitNode, ClipboardTransitData), Z_Construct_UScriptStruct_FDialogueTransit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClipboardTransitData_MetaData), NewProp_ClipboardTransitData_MetaData) }; // 2804408187
void Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_HasClipboardTransitData_SetBit(void* Obj)
{
	((UDialogueGraphTransitNode*)Obj)->HasClipboardTransitData = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_HasClipboardTransitData = { "HasClipboardTransitData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueGraphTransitNode), &Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_HasClipboardTransitData_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HasClipboardTransitData_MetaData), NewProp_HasClipboardTransitData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueGraphTransitNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_TransitNodeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_ClipboardTransitData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphTransitNode_Statics::NewProp_HasClipboardTransitData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphTransitNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueGraphTransitNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphTransitNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphTransitNode_Statics::ClassParams = {
	&UDialogueGraphTransitNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueGraphTransitNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphTransitNode_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphTransitNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphTransitNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphTransitNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphTransitNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphTransitNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphTransitNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphTransitNode.OuterSingleton;
}
UDialogueGraphTransitNode::UDialogueGraphTransitNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphTransitNode);
UDialogueGraphTransitNode::~UDialogueGraphTransitNode() {}
// ********** End Class UDialogueGraphTransitNode **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphTransitNode, UDialogueGraphTransitNode::StaticClass, TEXT("UDialogueGraphTransitNode"), &Z_Registration_Info_UClass_UDialogueGraphTransitNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphTransitNode), 3640442239U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h__Script_DialogueToolEditor_1796371989(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphTransitNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
