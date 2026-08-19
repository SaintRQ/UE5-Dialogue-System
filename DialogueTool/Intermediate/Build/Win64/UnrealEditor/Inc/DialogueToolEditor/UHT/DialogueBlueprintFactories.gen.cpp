// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueBlueprintFactories.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueBlueprintFactories() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueActionBlueprintFactory();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueActionBlueprintFactory_NoRegister();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueConditionBlueprintFactory();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueConditionBlueprintFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UBlueprintFactory();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueConditionBlueprintFactory ***************************************
void UDialogueConditionBlueprintFactory::StaticRegisterNativesUDialogueConditionBlueprintFactory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory;
UClass* UDialogueConditionBlueprintFactory::GetPrivateStaticClass()
{
	using TClass = UDialogueConditionBlueprintFactory;
	if (!Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueConditionBlueprintFactory"),
			Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory.InnerSingleton,
			StaticRegisterNativesUDialogueConditionBlueprintFactory,
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
	return Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueConditionBlueprintFactory_NoRegister()
{
	return UDialogueConditionBlueprintFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "DialogueBlueprintFactories.h" },
		{ "ModuleRelativePath", "Public/DialogueBlueprintFactories.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueConditionBlueprintFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics::ClassParams = {
	&UDialogueConditionBlueprintFactory::StaticClass,
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
	0x001020A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueConditionBlueprintFactory()
{
	if (!Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory.OuterSingleton, Z_Construct_UClass_UDialogueConditionBlueprintFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueConditionBlueprintFactory);
UDialogueConditionBlueprintFactory::~UDialogueConditionBlueprintFactory() {}
// ********** End Class UDialogueConditionBlueprintFactory *****************************************

// ********** Begin Class UDialogueActionBlueprintFactory ******************************************
void UDialogueActionBlueprintFactory::StaticRegisterNativesUDialogueActionBlueprintFactory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueActionBlueprintFactory;
UClass* UDialogueActionBlueprintFactory::GetPrivateStaticClass()
{
	using TClass = UDialogueActionBlueprintFactory;
	if (!Z_Registration_Info_UClass_UDialogueActionBlueprintFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueActionBlueprintFactory"),
			Z_Registration_Info_UClass_UDialogueActionBlueprintFactory.InnerSingleton,
			StaticRegisterNativesUDialogueActionBlueprintFactory,
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
	return Z_Registration_Info_UClass_UDialogueActionBlueprintFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueActionBlueprintFactory_NoRegister()
{
	return UDialogueActionBlueprintFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "DialogueBlueprintFactories.h" },
		{ "ModuleRelativePath", "Public/DialogueBlueprintFactories.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueActionBlueprintFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics::ClassParams = {
	&UDialogueActionBlueprintFactory::StaticClass,
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
	0x001020A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueActionBlueprintFactory()
{
	if (!Z_Registration_Info_UClass_UDialogueActionBlueprintFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueActionBlueprintFactory.OuterSingleton, Z_Construct_UClass_UDialogueActionBlueprintFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueActionBlueprintFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueActionBlueprintFactory);
UDialogueActionBlueprintFactory::~UDialogueActionBlueprintFactory() {}
// ********** End Class UDialogueActionBlueprintFactory ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueBlueprintFactories_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueConditionBlueprintFactory, UDialogueConditionBlueprintFactory::StaticClass, TEXT("UDialogueConditionBlueprintFactory"), &Z_Registration_Info_UClass_UDialogueConditionBlueprintFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueConditionBlueprintFactory), 2592419006U) },
		{ Z_Construct_UClass_UDialogueActionBlueprintFactory, UDialogueActionBlueprintFactory::StaticClass, TEXT("UDialogueActionBlueprintFactory"), &Z_Registration_Info_UClass_UDialogueActionBlueprintFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueActionBlueprintFactory), 3910332257U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueBlueprintFactories_h__Script_DialogueToolEditor_1433643681(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueBlueprintFactories_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueBlueprintFactories_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
