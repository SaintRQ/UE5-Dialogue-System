// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueCondition.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueCondition() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueCondition_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueCondition Function ExecuteCondition *****************************
struct DialogueCondition_eventExecuteCondition_Parms
{
	UObject* context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	DialogueCondition_eventExecuteCondition_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UDialogueCondition_ExecuteCondition = FName(TEXT("ExecuteCondition"));
bool UDialogueCondition::ExecuteCondition(UObject* context) const
{
	UFunction* Func = FindFunctionChecked(NAME_UDialogueCondition_ExecuteCondition);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		DialogueCondition_eventExecuteCondition_Parms Parms;
		Parms.context=context;
		const_cast<UDialogueCondition*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UDialogueCondition*>(this)->ExecuteCondition_Implementation(context);
	}
}
struct Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue Tool|Condition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Evaluates the condition using the supplied context.\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueCondition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Evaluates the condition using the supplied context." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::NewProp_context = { "context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueCondition_eventExecuteCondition_Parms, context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueCondition_eventExecuteCondition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueCondition_eventExecuteCondition_Parms), &Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::NewProp_context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueCondition, nullptr, "ExecuteCondition", Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::PropPointers), sizeof(DialogueCondition_eventExecuteCondition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DialogueCondition_eventExecuteCondition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueCondition_ExecuteCondition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueCondition_ExecuteCondition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueCondition::execExecuteCondition)
{
	P_GET_OBJECT(UObject,Z_Param_context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ExecuteCondition_Implementation(Z_Param_context);
	P_NATIVE_END;
}
// ********** End Class UDialogueCondition Function ExecuteCondition *******************************

// ********** Begin Class UDialogueCondition *******************************************************
void UDialogueCondition::StaticRegisterNativesUDialogueCondition()
{
	UClass* Class = UDialogueCondition::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteCondition", &UDialogueCondition::execExecuteCondition },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueCondition;
UClass* UDialogueCondition::GetPrivateStaticClass()
{
	using TClass = UDialogueCondition;
	if (!Z_Registration_Info_UClass_UDialogueCondition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueCondition"),
			Z_Registration_Info_UClass_UDialogueCondition.InnerSingleton,
			StaticRegisterNativesUDialogueCondition,
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
	return Z_Registration_Info_UClass_UDialogueCondition.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueCondition_NoRegister()
{
	return UDialogueCondition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueCondition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueCondition.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueCondition.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueCondition_ExecuteCondition, "ExecuteCondition" }, // 3716824239
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueCondition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueCondition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueCondition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueCondition_Statics::ClassParams = {
	&UDialogueCondition::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueCondition_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueCondition_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueCondition()
{
	if (!Z_Registration_Info_UClass_UDialogueCondition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueCondition.OuterSingleton, Z_Construct_UClass_UDialogueCondition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueCondition.OuterSingleton;
}
UDialogueCondition::UDialogueCondition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueCondition);
UDialogueCondition::~UDialogueCondition() {}
// ********** End Class UDialogueCondition *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueCondition, UDialogueCondition::StaticClass, TEXT("UDialogueCondition"), &Z_Registration_Info_UClass_UDialogueCondition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueCondition), 2972441807U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h__Script_DialogueTool_1902321153(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueCondition_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
