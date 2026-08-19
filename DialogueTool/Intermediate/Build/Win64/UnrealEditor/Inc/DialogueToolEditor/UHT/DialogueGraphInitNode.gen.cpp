// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphInitNode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphInitNode() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphInitNode();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphInitNode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphInitNode ***************************************************
void UDialogueGraphInitNode::StaticRegisterNativesUDialogueGraphInitNode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphInitNode;
UClass* UDialogueGraphInitNode::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphInitNode;
	if (!Z_Registration_Info_UClass_UDialogueGraphInitNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphInitNode"),
			Z_Registration_Info_UClass_UDialogueGraphInitNode.InnerSingleton,
			StaticRegisterNativesUDialogueGraphInitNode,
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
	return Z_Registration_Info_UClass_UDialogueGraphInitNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphInitNode_NoRegister()
{
	return UDialogueGraphInitNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphInitNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphInitNode.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphInitNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphInitNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueGraphInitNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphInitNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphInitNode_Statics::ClassParams = {
	&UDialogueGraphInitNode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphInitNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphInitNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphInitNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphInitNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphInitNode.OuterSingleton, Z_Construct_UClass_UDialogueGraphInitNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphInitNode.OuterSingleton;
}
UDialogueGraphInitNode::UDialogueGraphInitNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphInitNode);
UDialogueGraphInitNode::~UDialogueGraphInitNode() {}
// ********** End Class UDialogueGraphInitNode *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphInitNode, UDialogueGraphInitNode::StaticClass, TEXT("UDialogueGraphInitNode"), &Z_Registration_Info_UClass_UDialogueGraphInitNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphInitNode), 3557259610U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h__Script_DialogueToolEditor_2818367298(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphInitNode_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
