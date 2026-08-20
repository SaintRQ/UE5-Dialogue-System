// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueLibraryObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueLibraryObject() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueLibraryObject();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueLibraryObject_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueObject();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueLibraryObject ***************************************************
void UDialogueLibraryObject::StaticRegisterNativesUDialogueLibraryObject()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueLibraryObject;
UClass* UDialogueLibraryObject::GetPrivateStaticClass()
{
	using TClass = UDialogueLibraryObject;
	if (!Z_Registration_Info_UClass_UDialogueLibraryObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueLibraryObject"),
			Z_Registration_Info_UClass_UDialogueLibraryObject.InnerSingleton,
			StaticRegisterNativesUDialogueLibraryObject,
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
	return Z_Registration_Info_UClass_UDialogueLibraryObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueLibraryObject_NoRegister()
{
	return UDialogueLibraryObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueLibraryObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stores reusable dialogue flow that returns to its caller on completion. */" },
#endif
		{ "IncludePath", "DialogueLibraryObject.h" },
		{ "ModuleRelativePath", "Public/DialogueLibraryObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stores reusable dialogue flow that returns to its caller on completion." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueLibraryObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueLibraryObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueLibraryObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueLibraryObject_Statics::ClassParams = {
	&UDialogueLibraryObject::StaticClass,
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
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueLibraryObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueLibraryObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueLibraryObject()
{
	if (!Z_Registration_Info_UClass_UDialogueLibraryObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueLibraryObject.OuterSingleton, Z_Construct_UClass_UDialogueLibraryObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueLibraryObject.OuterSingleton;
}
UDialogueLibraryObject::UDialogueLibraryObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueLibraryObject);
UDialogueLibraryObject::~UDialogueLibraryObject() {}
// ********** End Class UDialogueLibraryObject *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueLibraryObject, UDialogueLibraryObject::StaticClass, TEXT("UDialogueLibraryObject"), &Z_Registration_Info_UClass_UDialogueLibraryObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueLibraryObject), 3383376383U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h__Script_DialogueTool_2236925129(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueLibraryObject_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
