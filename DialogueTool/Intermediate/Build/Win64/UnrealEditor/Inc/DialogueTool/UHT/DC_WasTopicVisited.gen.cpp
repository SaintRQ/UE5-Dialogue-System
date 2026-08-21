// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Conditions/DC_WasTopicVisited.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDC_WasTopicVisited() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDC_WasTopicVisited();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDC_WasTopicVisited_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDC_WasTopicVisited ******************************************************
void UDC_WasTopicVisited::StaticRegisterNativesUDC_WasTopicVisited()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDC_WasTopicVisited;
UClass* UDC_WasTopicVisited::GetPrivateStaticClass()
{
	using TClass = UDC_WasTopicVisited;
	if (!Z_Registration_Info_UClass_UDC_WasTopicVisited.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DC_WasTopicVisited"),
			Z_Registration_Info_UClass_UDC_WasTopicVisited.InnerSingleton,
			StaticRegisterNativesUDC_WasTopicVisited,
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
	return Z_Registration_Info_UClass_UDC_WasTopicVisited.InnerSingleton;
}
UClass* Z_Construct_UClass_UDC_WasTopicVisited_NoRegister()
{
	return UDC_WasTopicVisited::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDC_WasTopicVisited_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Conditions/DC_WasTopicVisited.h" },
		{ "ModuleRelativePath", "Public/Conditions/DC_WasTopicVisited.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks whether the topic containing this response was visited before its current entry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConditionResult_MetaData[] = {
		{ "Category", "Topic" },
		{ "ModuleRelativePath", "Public/Conditions/DC_WasTopicVisited.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ConditionResult_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ConditionResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDC_WasTopicVisited>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UDC_WasTopicVisited_Statics::NewProp_ConditionResult_SetBit(void* Obj)
{
	((UDC_WasTopicVisited*)Obj)->ConditionResult = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDC_WasTopicVisited_Statics::NewProp_ConditionResult = { "ConditionResult", nullptr, (EPropertyFlags)0x0040000000000801, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDC_WasTopicVisited), &Z_Construct_UClass_UDC_WasTopicVisited_Statics::NewProp_ConditionResult_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConditionResult_MetaData), NewProp_ConditionResult_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDC_WasTopicVisited_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDC_WasTopicVisited_Statics::NewProp_ConditionResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasTopicVisited_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDC_WasTopicVisited_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueCondition,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasTopicVisited_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDC_WasTopicVisited_Statics::ClassParams = {
	&UDC_WasTopicVisited::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDC_WasTopicVisited_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasTopicVisited_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasTopicVisited_Statics::Class_MetaDataParams), Z_Construct_UClass_UDC_WasTopicVisited_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDC_WasTopicVisited()
{
	if (!Z_Registration_Info_UClass_UDC_WasTopicVisited.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDC_WasTopicVisited.OuterSingleton, Z_Construct_UClass_UDC_WasTopicVisited_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDC_WasTopicVisited.OuterSingleton;
}
UDC_WasTopicVisited::UDC_WasTopicVisited(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDC_WasTopicVisited);
UDC_WasTopicVisited::~UDC_WasTopicVisited() {}
// ********** End Class UDC_WasTopicVisited ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasTopicVisited_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDC_WasTopicVisited, UDC_WasTopicVisited::StaticClass, TEXT("UDC_WasTopicVisited"), &Z_Registration_Info_UClass_UDC_WasTopicVisited, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDC_WasTopicVisited), 3684172786U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasTopicVisited_h__Script_DialogueTool_2688186602(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasTopicVisited_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasTopicVisited_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
