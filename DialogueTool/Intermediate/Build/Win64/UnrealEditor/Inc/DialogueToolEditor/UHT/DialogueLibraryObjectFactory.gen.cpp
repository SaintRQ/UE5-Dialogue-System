// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueLibraryObjectFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueLibraryObjectFactory() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueLibraryObjectFactory();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueLibraryObjectFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueLibraryObjectFactory ********************************************
void UDialogueLibraryObjectFactory::StaticRegisterNativesUDialogueLibraryObjectFactory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueLibraryObjectFactory;
UClass* UDialogueLibraryObjectFactory::GetPrivateStaticClass()
{
	using TClass = UDialogueLibraryObjectFactory;
	if (!Z_Registration_Info_UClass_UDialogueLibraryObjectFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueLibraryObjectFactory"),
			Z_Registration_Info_UClass_UDialogueLibraryObjectFactory.InnerSingleton,
			StaticRegisterNativesUDialogueLibraryObjectFactory,
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
	return Z_Registration_Info_UClass_UDialogueLibraryObjectFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueLibraryObjectFactory_NoRegister()
{
	return UDialogueLibraryObjectFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueLibraryObjectFactory.h" },
		{ "ModuleRelativePath", "Public/DialogueLibraryObjectFactory.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueLibraryObjectFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics::ClassParams = {
	&UDialogueLibraryObjectFactory::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueLibraryObjectFactory()
{
	if (!Z_Registration_Info_UClass_UDialogueLibraryObjectFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueLibraryObjectFactory.OuterSingleton, Z_Construct_UClass_UDialogueLibraryObjectFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueLibraryObjectFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueLibraryObjectFactory);
UDialogueLibraryObjectFactory::~UDialogueLibraryObjectFactory() {}
// ********** End Class UDialogueLibraryObjectFactory **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueLibraryObjectFactory_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueLibraryObjectFactory, UDialogueLibraryObjectFactory::StaticClass, TEXT("UDialogueLibraryObjectFactory"), &Z_Registration_Info_UClass_UDialogueLibraryObjectFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueLibraryObjectFactory), 2084591976U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueLibraryObjectFactory_h__Script_DialogueToolEditor_230414661(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueLibraryObjectFactory_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueLibraryObjectFactory_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
