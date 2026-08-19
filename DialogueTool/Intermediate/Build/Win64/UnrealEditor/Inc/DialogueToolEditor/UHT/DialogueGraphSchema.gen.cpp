// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueGraphSchema.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueGraphSchema() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSchema();
DIALOGUETOOLEDITOR_API UClass* Z_Construct_UClass_UDialogueGraphSchema_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraphSchema();
UPackage* Z_Construct_UPackage__Script_DialogueToolEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueGraphSchema *****************************************************
void UDialogueGraphSchema::StaticRegisterNativesUDialogueGraphSchema()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueGraphSchema;
UClass* UDialogueGraphSchema::GetPrivateStaticClass()
{
	using TClass = UDialogueGraphSchema;
	if (!Z_Registration_Info_UClass_UDialogueGraphSchema.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueGraphSchema"),
			Z_Registration_Info_UClass_UDialogueGraphSchema.InnerSingleton,
			StaticRegisterNativesUDialogueGraphSchema,
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
	return Z_Registration_Info_UClass_UDialogueGraphSchema.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueGraphSchema_NoRegister()
{
	return UDialogueGraphSchema::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueGraphSchema_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueGraphSchema.h" },
		{ "ModuleRelativePath", "Public/DialogueGraphSchema.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGraphSchema>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueGraphSchema_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEdGraphSchema,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueToolEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSchema_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGraphSchema_Statics::ClassParams = {
	&UDialogueGraphSchema::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGraphSchema_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGraphSchema_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGraphSchema()
{
	if (!Z_Registration_Info_UClass_UDialogueGraphSchema.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGraphSchema.OuterSingleton, Z_Construct_UClass_UDialogueGraphSchema_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGraphSchema.OuterSingleton;
}
UDialogueGraphSchema::UDialogueGraphSchema(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGraphSchema);
UDialogueGraphSchema::~UDialogueGraphSchema() {}
// ********** End Class UDialogueGraphSchema *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSchema_h__Script_DialogueToolEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueGraphSchema, UDialogueGraphSchema::StaticClass, TEXT("UDialogueGraphSchema"), &Z_Registration_Info_UClass_UDialogueGraphSchema, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGraphSchema), 4020347836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSchema_h__Script_DialogueToolEditor_390180754(TEXT("/Script/DialogueToolEditor"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSchema_h__Script_DialogueToolEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueToolEditor_Public_DialogueGraphSchema_h__Script_DialogueToolEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
