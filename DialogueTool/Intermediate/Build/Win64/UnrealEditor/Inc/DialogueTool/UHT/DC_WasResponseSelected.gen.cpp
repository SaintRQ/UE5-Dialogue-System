// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Conditions/DC_WasResponseSelected.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDC_WasResponseSelected() {}

// ********** Begin Cross Module References ********************************************************
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDC_WasResponseSelected();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDC_WasResponseSelected_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDC_WasResponseSelected **************************************************
void UDC_WasResponseSelected::StaticRegisterNativesUDC_WasResponseSelected()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDC_WasResponseSelected;
UClass* UDC_WasResponseSelected::GetPrivateStaticClass()
{
	using TClass = UDC_WasResponseSelected;
	if (!Z_Registration_Info_UClass_UDC_WasResponseSelected.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DC_WasResponseSelected"),
			Z_Registration_Info_UClass_UDC_WasResponseSelected.InnerSingleton,
			StaticRegisterNativesUDC_WasResponseSelected,
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
	return Z_Registration_Info_UClass_UDC_WasResponseSelected.InnerSingleton;
}
UClass* Z_Construct_UClass_UDC_WasResponseSelected_NoRegister()
{
	return UDC_WasResponseSelected::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDC_WasResponseSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Conditions/DC_WasResponseSelected.h" },
		{ "ModuleRelativePath", "Public/Conditions/DC_WasResponseSelected.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks whether the response containing this condition has ever been selected." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConditionResult_MetaData[] = {
		{ "Category", "Response" },
		{ "ModuleRelativePath", "Public/Conditions/DC_WasResponseSelected.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ConditionResult_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ConditionResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDC_WasResponseSelected>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UDC_WasResponseSelected_Statics::NewProp_ConditionResult_SetBit(void* Obj)
{
	((UDC_WasResponseSelected*)Obj)->ConditionResult = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDC_WasResponseSelected_Statics::NewProp_ConditionResult = { "ConditionResult", nullptr, (EPropertyFlags)0x0040000000000801, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDC_WasResponseSelected), &Z_Construct_UClass_UDC_WasResponseSelected_Statics::NewProp_ConditionResult_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConditionResult_MetaData), NewProp_ConditionResult_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDC_WasResponseSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDC_WasResponseSelected_Statics::NewProp_ConditionResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasResponseSelected_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDC_WasResponseSelected_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueCondition,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasResponseSelected_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDC_WasResponseSelected_Statics::ClassParams = {
	&UDC_WasResponseSelected::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDC_WasResponseSelected_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasResponseSelected_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDC_WasResponseSelected_Statics::Class_MetaDataParams), Z_Construct_UClass_UDC_WasResponseSelected_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDC_WasResponseSelected()
{
	if (!Z_Registration_Info_UClass_UDC_WasResponseSelected.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDC_WasResponseSelected.OuterSingleton, Z_Construct_UClass_UDC_WasResponseSelected_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDC_WasResponseSelected.OuterSingleton;
}
UDC_WasResponseSelected::UDC_WasResponseSelected(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDC_WasResponseSelected);
UDC_WasResponseSelected::~UDC_WasResponseSelected() {}
// ********** End Class UDC_WasResponseSelected ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasResponseSelected_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDC_WasResponseSelected, UDC_WasResponseSelected::StaticClass, TEXT("UDC_WasResponseSelected"), &Z_Registration_Info_UClass_UDC_WasResponseSelected, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDC_WasResponseSelected), 3989371535U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasResponseSelected_h__Script_DialogueTool_2925594277(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasResponseSelected_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_Conditions_DC_WasResponseSelected_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
