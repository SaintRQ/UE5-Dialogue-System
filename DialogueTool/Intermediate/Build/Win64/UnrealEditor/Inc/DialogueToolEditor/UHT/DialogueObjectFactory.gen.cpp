// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueObjectFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueObjectFactory() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueObjectFactory();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueObjectFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueObjectFactory ***************************************************
void UDialogueObjectFactory::StaticRegisterNativesUDialogueObjectFactory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueObjectFactory;
UClass* UDialogueObjectFactory::GetPrivateStaticClass()
{
	using TClass = UDialogueObjectFactory;
	if (!Z_Registration_Info_UClass_UDialogueObjectFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueObjectFactory"),
			Z_Registration_Info_UClass_UDialogueObjectFactory.InnerSingleton,
			StaticRegisterNativesUDialogueObjectFactory,
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
	return Z_Registration_Info_UClass_UDialogueObjectFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueObjectFactory_NoRegister()
{
	return UDialogueObjectFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueObjectFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueObjectFactory.h" },
		{ "ModuleRelativePath", "Public/DialogueObjectFactory.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueObjectFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueObjectFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueObjectFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueObjectFactory_Statics::ClassParams = {
	&UDialogueObjectFactory::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueObjectFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueObjectFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueObjectFactory()
{
	if (!Z_Registration_Info_UClass_UDialogueObjectFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueObjectFactory.OuterSingleton, Z_Construct_UClass_UDialogueObjectFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueObjectFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueObjectFactory);
UDialogueObjectFactory::~UDialogueObjectFactory() {}
// ********** End Class UDialogueObjectFactory *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueObjectFactory, UDialogueObjectFactory::StaticClass, TEXT("UDialogueObjectFactory"), &Z_Registration_Info_UClass_UDialogueObjectFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueObjectFactory), 1590485692U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h__Script_DialogueToolEditor_1703343103(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueObjectFactory_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
