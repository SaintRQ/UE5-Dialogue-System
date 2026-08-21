// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueProvider.h"
#include "DialogueRoot.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueProvider() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueProvider();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueProvider_NoRegister();
DIALOGUETOOL_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueCache();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueProvider Function ExecuteProvider *******************************
struct DialogueProvider_eventExecuteProvider_Parms
{
	UObject* context;
	FDialogueCache cache;
	FText ReturnValue;
};
static FName NAME_UDialogueProvider_ExecuteProvider = FName(TEXT("ExecuteProvider"));
FText UDialogueProvider::ExecuteProvider(UObject* context, FDialogueCache const& cache) const
{
	UFunction* Func = FindFunctionChecked(NAME_UDialogueProvider_ExecuteProvider);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		DialogueProvider_eventExecuteProvider_Parms Parms;
		Parms.context=context;
		Parms.cache=cache;
		const_cast<UDialogueProvider*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UDialogueProvider*>(this)->ExecuteProvider_Implementation(context, cache);
	}
}
struct Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool|Provider" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Generates dialogue text from the execution context and current cache.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generates dialogue text from the execution context and current cache." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cache_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_cache;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueProvider_eventExecuteProvider_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::NewProp_cache = { "cache", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueProvider_eventExecuteProvider_Parms, cache), Z_Construct_UScriptStruct_FDialogueCache, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cache_MetaData), NewProp_cache_MetaData) }; // 2268999594
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueProvider_eventExecuteProvider_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::NewProp_context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::NewProp_cache,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueProvider, nullptr, "ExecuteProvider", Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::PropPointers), sizeof(DialogueProvider_eventExecuteProvider_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DialogueProvider_eventExecuteProvider_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueProvider_ExecuteProvider()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueProvider_ExecuteProvider_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueProvider::execExecuteProvider)
{
	P_GET_OBJECT(UObject,Z_Param_context);
	P_GET_STRUCT_REF(FDialogueCache,Z_Param_Out_cache);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->ExecuteProvider_Implementation(Z_Param_context,Z_Param_Out_cache);
	P_NATIVE_END;
}
// ********** End Class UDialogueProvider Function ExecuteProvider *********************************

// ********** Begin Class UDialogueProvider ********************************************************
void UDialogueProvider::StaticRegisterNativesUDialogueProvider()
{
	UClass* Class = UDialogueProvider::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteProvider", &UDialogueProvider::execExecuteProvider },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueProvider;
UClass* UDialogueProvider::GetPrivateStaticClass()
{
	using TClass = UDialogueProvider;
	if (!Z_Registration_Info_UClass_UDialogueProvider.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueProvider"),
			Z_Registration_Info_UClass_UDialogueProvider.InnerSingleton,
			StaticRegisterNativesUDialogueProvider,
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
	return Z_Registration_Info_UClass_UDialogueProvider.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueProvider_NoRegister()
{
	return UDialogueProvider::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueProvider_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueProvider.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueProvider.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueProvider_ExecuteProvider, "ExecuteProvider" }, // 1840785719
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueProvider>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueProvider_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueProvider_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueProvider_Statics::ClassParams = {
	&UDialogueProvider::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x003010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueProvider_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueProvider_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueProvider()
{
	if (!Z_Registration_Info_UClass_UDialogueProvider.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueProvider.OuterSingleton, Z_Construct_UClass_UDialogueProvider_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueProvider.OuterSingleton;
}
UDialogueProvider::UDialogueProvider(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueProvider);
UDialogueProvider::~UDialogueProvider() {}
// ********** End Class UDialogueProvider **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueProvider, UDialogueProvider::StaticClass, TEXT("UDialogueProvider"), &Z_Registration_Info_UClass_UDialogueProvider, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueProvider), 1024912264U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h__Script_DialogueTool_3701334181(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueProvider_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
