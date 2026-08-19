// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphRerouteNode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphRerouteNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphRerouteNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphRerouteNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphRerouteNode ************************************************
void UDialogueGraphRerouteNode::StaticRegisterNativesUDialogueGraphRerouteNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphRerouteNode;
UClass* UDialogueGraphRerouteNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphRerouteNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphRerouteNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphRerouteNode"),
			Z_Registration_Info_UClass_UDialogueGraphRerouteNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphRerouteNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphRerouteNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphRerouteNode_NoRegister()
{
	return UDialogueGraphRerouteNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphRerouteNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphRerouteNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphRerouteNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphRerouteNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueGraphRerouteNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphRerouteNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphRerouteNode_Statics::ClassParams = {
	&UDialogueGraphRerouteNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphRerouteNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphRerouteNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphRerouteNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphRerouteNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphRerouteNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphRerouteNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphRerouteNode.OuterSingleton;
}
UDialogueGraphRerouteNode::UDialogueGraphRerouteNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphRerouteNode);
UDialogueGraphRerouteNode::~UDialogueGraphRerouteNode() {}
// ********** End Class UDialogueGraphRerouteNode **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphRerouteNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphRerouteNode, UDialogueGraphRerouteNode::StaticClass, TEXT("UDialogueGraphRerouteNode"), &Z_Registration_Info_UClass_UDialogueGraphRerouteNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphRerouteNode), 128995009U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphRerouteNode_h__Script_DialogueToolEditor_587385174(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphRerouteNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphRerouteNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
