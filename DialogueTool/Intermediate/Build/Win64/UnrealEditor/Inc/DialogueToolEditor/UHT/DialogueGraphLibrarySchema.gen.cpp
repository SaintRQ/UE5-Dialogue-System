// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphLibrarySchema.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphLibrarySchema() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphLibrarySchema();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphLibrarySchema_NoRegister();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSchema();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphLibrarySchema **********************************************
void UDialogueGraphLibrarySchema::StaticRegisterNativesUDialogueGraphLibrarySchema()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphLibrarySchema;
UClass* UDialogueGraphLibrarySchema::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphLibrarySchema;
	if (!Z_Registration_Info_UClass_UDialogueGraphLibrarySchema.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphLibrarySchema"),
			Z_Registration_Info_UClass_UDialogueGraphLibrarySchema.InnerSingleton,
			StaticRegisterNativesUDialogueGraphLibrarySchema,
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
	return Z_Registration_Info_UClass_UDialogueGraphLibrarySchema.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphLibrarySchema_NoRegister()
{
	return UDialogueGraphLibrarySchema::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphLibrarySchema.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphLibrarySchema.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphLibrarySchema>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueGraphSchema,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics::ClassParams = {
	&UDialogueGraphLibrarySchema::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphLibrarySchema()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphLibrarySchema.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphLibrarySchema.OuterSingleton, Z_Construct_UClass_UDialogueGraphLibrarySchema_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphLibrarySchema.OuterSingleton;
}
UDialogueGraphLibrarySchema::UDialogueGraphLibrarySchema(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphLibrarySchema);
UDialogueGraphLibrarySchema::~UDialogueGraphLibrarySchema() {}
// ********** End Class UDialogueGraphLibrarySchema ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphLibrarySchema_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphLibrarySchema, UDialogueGraphLibrarySchema::StaticClass, TEXT("UDialogueGraphLibrarySchema"), &Z_Registration_Info_UClass_UDialogueGraphLibrarySchema, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphLibrarySchema), 2721093112U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphLibrarySchema_h__Script_DialogueToolEditor_2395353290(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphLibrarySchema_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphLibrarySchema_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
