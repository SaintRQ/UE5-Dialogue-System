// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetDefinition_DialogueLibraryObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAssetDefinition_DialogueLibraryObject() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UAssetDefinitionDefault();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAssetDefinition_DialogueLibraryObject ***********************************
void UAssetDefinition_DialogueLibraryObject::StaticRegisterNativesUAssetDefinition_DialogueLibraryObject()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject;
UClass* UAssetDefinition_DialogueLibraryObject::GetPrivateStaticClass()
{
	using TClass = UAssetDefinition_DialogueLibraryObject;
	if (!Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AssetDefinition_DialogueLibraryObject"),
			Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject.InnerSingleton,
			StaticRegisterNativesUAssetDefinition_DialogueLibraryObject,
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
	return Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_NoRegister()
{
	return UAssetDefinition_DialogueLibraryObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AssetDefinition_DialogueLibraryObject.h" },
		{ "ModuleRelativePath", "Public/AssetDefinition_DialogueLibraryObject.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetDefinition_DialogueLibraryObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetDefinitionDefault,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics::ClassParams = {
	&UAssetDefinition_DialogueLibraryObject::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject()
{
	if (!Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject.OuterSingleton, Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject.OuterSingleton;
}
UAssetDefinition_DialogueLibraryObject::UAssetDefinition_DialogueLibraryObject() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetDefinition_DialogueLibraryObject);
UAssetDefinition_DialogueLibraryObject::~UAssetDefinition_DialogueLibraryObject() {}
// ********** End Class UAssetDefinition_DialogueLibraryObject *************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueLibraryObject_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAssetDefinition_DialogueLibraryObject, UAssetDefinition_DialogueLibraryObject::StaticClass, TEXT("UAssetDefinition_DialogueLibraryObject"), &Z_Registration_Info_UClass_UAssetDefinition_DialogueLibraryObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssetDefinition_DialogueLibraryObject), 1613121656U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueLibraryObject_h__Script_DialogueToolEditor_814713660(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueLibraryObject_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueLibraryObject_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
