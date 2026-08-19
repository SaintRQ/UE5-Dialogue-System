// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetDefinition_DialogueObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAssetDefinition_DialogueObject() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_DialogueObject();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UAssetDefinition_DialogueObject_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UAssetDefinitionDefault();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAssetDefinition_DialogueObject ******************************************
void UAssetDefinition_DialogueObject::StaticRegisterNativesUAssetDefinition_DialogueObject()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAssetDefinition_DialogueObject;
UClass* UAssetDefinition_DialogueObject::GetPrivateStaticClass()
{
	using TClass = UAssetDefinition_DialogueObject;
	if (!Z_Registration_Info_UClass_UAssetDefinition_DialogueObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AssetDefinition_DialogueObject"),
			Z_Registration_Info_UClass_UAssetDefinition_DialogueObject.InnerSingleton,
			StaticRegisterNativesUAssetDefinition_DialogueObject,
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
	return Z_Registration_Info_UClass_UAssetDefinition_DialogueObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UAssetDefinition_DialogueObject_NoRegister()
{
	return UAssetDefinition_DialogueObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AssetDefinition_DialogueObject.h" },
		{ "ModuleRelativePath", "Public/AssetDefinition_DialogueObject.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetDefinition_DialogueObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetDefinitionDefault,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics::ClassParams = {
	&UAssetDefinition_DialogueObject::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAssetDefinition_DialogueObject()
{
	if (!Z_Registration_Info_UClass_UAssetDefinition_DialogueObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssetDefinition_DialogueObject.OuterSingleton, Z_Construct_UClass_UAssetDefinition_DialogueObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAssetDefinition_DialogueObject.OuterSingleton;
}
UAssetDefinition_DialogueObject::UAssetDefinition_DialogueObject() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetDefinition_DialogueObject);
UAssetDefinition_DialogueObject::~UAssetDefinition_DialogueObject() {}
// ********** End Class UAssetDefinition_DialogueObject ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueObject_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAssetDefinition_DialogueObject, UAssetDefinition_DialogueObject::StaticClass, TEXT("UAssetDefinition_DialogueObject"), &Z_Registration_Info_UClass_UAssetDefinition_DialogueObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssetDefinition_DialogueObject), 3195933367U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueObject_h__Script_DialogueToolEditor_696546379(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueObject_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_AssetDefinition_DialogueObject_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
