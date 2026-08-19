// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueAction.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueAction() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueAction();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueAction Function ExecuteAction ***********************************
struct DialogueAction_eventExecuteAction_Parms
{
	UObject* context;
};
static FName NAME_UDialogueAction_ExecuteAction = FName(TEXT("ExecuteAction"));
void UDialogueAction::ExecuteAction(UObject* context)
{
	UFunction* Func = FindFunctionChecked(NAME_UDialogueAction_ExecuteAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		DialogueAction_eventExecuteAction_Parms Parms;
		Parms.context=context;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		ExecuteAction_Implementation(context);
	}
}
struct Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool|Action" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Executes the action using the supplied context.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Executes the action using the supplied context." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueAction_eventExecuteAction_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::NewProp_context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueAction, nullptr, "ExecuteAction", Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::PropPointers), sizeof(DialogueAction_eventExecuteAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DialogueAction_eventExecuteAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueAction_ExecuteAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueAction_ExecuteAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueAction::execExecuteAction)
{
	P_GET_OBJECT(UObject,Z_Param_context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteAction_Implementation(Z_Param_context);
	P_NATIVE_END;
}
// ********** End Class UDialogueAction Function ExecuteAction *************************************

// ********** Begin Class UDialogueAction **********************************************************
void UDialogueAction::StaticRegisterNativesUDialogueAction()
{
	UClass* Class = UDialogueAction::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteAction", &UDialogueAction::execExecuteAction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueAction;
UClass* UDialogueAction::GetPrivateStaticClass()
{
	using TClass = UDialogueAction;
	if (!Z_Registration_Info_UClass_UDialogueAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueAction"),
			Z_Registration_Info_UClass_UDialogueAction.InnerSingleton,
			StaticRegisterNativesUDialogueAction,
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
	return Z_Registration_Info_UClass_UDialogueAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueAction_NoRegister()
{
	return UDialogueAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueAction.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueAction.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueAction_ExecuteAction, "ExecuteAction" }, // 2300589016
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueAction_Statics::ClassParams = {
	&UDialogueAction::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueAction_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueAction()
{
	if (!Z_Registration_Info_UClass_UDialogueAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueAction.OuterSingleton, Z_Construct_UClass_UDialogueAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueAction.OuterSingleton;
}
UDialogueAction::UDialogueAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueAction);
UDialogueAction::~UDialogueAction() {}
// ********** End Class UDialogueAction ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueAction, UDialogueAction::StaticClass, TEXT("UDialogueAction"), &Z_Registration_Info_UClass_UDialogueAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueAction), 2463685890U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h__Script_DialogueTool_107412494(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueAction_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
