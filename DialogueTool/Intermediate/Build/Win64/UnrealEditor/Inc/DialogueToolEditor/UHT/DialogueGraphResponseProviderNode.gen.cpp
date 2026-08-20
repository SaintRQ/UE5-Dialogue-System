// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphResponseProviderNode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphResponseProviderNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueProvider_NoRegister();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphResponseProviderNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphResponseProviderNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphResponseProviderNode ***************************************
void UDialogueGraphResponseProviderNode::StaticRegisterNativesUDialogueGraphResponseProviderNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode;
UClass* UDialogueGraphResponseProviderNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphResponseProviderNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphResponseProviderNode"),
			Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphResponseProviderNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphResponseProviderNode_NoRegister()
{
	return UDialogueGraphResponseProviderNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphResponseProviderNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphResponseProviderNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueProvider_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueGraphResponseProviderNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DialogueProvider;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphResponseProviderNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::NewProp_DialogueProvider = { "DialogueProvider", nullptr, (EPropertyFlags)0x0146000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueGraphResponseProviderNode, DialogueProvider), Z_Construct_UClass_UDialogueProvider_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueProvider_MetaData), NewProp_DialogueProvider_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::NewProp_DialogueProvider,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::ClassParams = {
	&UDialogueGraphResponseProviderNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphResponseProviderNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphResponseProviderNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode.OuterSingleton;
}
UDialogueGraphResponseProviderNode::UDialogueGraphResponseProviderNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphResponseProviderNode);
UDialogueGraphResponseProviderNode::~UDialogueGraphResponseProviderNode() {}
// ********** End Class UDialogueGraphResponseProviderNode *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphResponseProviderNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphResponseProviderNode, UDialogueGraphResponseProviderNode::StaticClass, TEXT("UDialogueGraphResponseProviderNode"), &Z_Registration_Info_UClass_UDialogueGraphResponseProviderNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphResponseProviderNode), 1257063638U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphResponseProviderNode_h__Script_DialogueToolEditor_374812933(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphResponseProviderNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphResponseProviderNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
