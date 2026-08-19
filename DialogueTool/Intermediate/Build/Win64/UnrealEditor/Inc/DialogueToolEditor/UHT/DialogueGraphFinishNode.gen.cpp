// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphFinishNode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphFinishNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphFinishNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphFinishNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphFinishNode *************************************************
void UDialogueGraphFinishNode::StaticRegisterNativesUDialogueGraphFinishNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphFinishNode;
UClass* UDialogueGraphFinishNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphFinishNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphFinishNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphFinishNode"),
			Z_Registration_Info_UClass_UDialogueGraphFinishNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphFinishNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphFinishNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphFinishNode_NoRegister()
{
	return UDialogueGraphFinishNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphFinishNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphFinishNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphFinishNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphFinishNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueGraphFinishNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphFinishNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphFinishNode_Statics::ClassParams = {
	&UDialogueGraphFinishNode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphFinishNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphFinishNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphFinishNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphFinishNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphFinishNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphFinishNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphFinishNode.OuterSingleton;
}
UDialogueGraphFinishNode::UDialogueGraphFinishNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphFinishNode);
UDialogueGraphFinishNode::~UDialogueGraphFinishNode() {}
// ********** End Class UDialogueGraphFinishNode ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphFinishNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphFinishNode, UDialogueGraphFinishNode::StaticClass, TEXT("UDialogueGraphFinishNode"), &Z_Registration_Info_UClass_UDialogueGraphFinishNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphFinishNode), 2159460040U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphFinishNode_h__Script_DialogueToolEditor_1587518016(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphFinishNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphFinishNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
