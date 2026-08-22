// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueToolSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDialogueToolSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueToolSettings();
DIALOGUETOOL_API UClass* Z_Construct_UClass_UDialogueToolSettings_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialogueTool();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueToolSettings ****************************************************
void UDialogueToolSettings::StaticRegisterNativesUDialogueToolSettings()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueToolSettings;
UClass* UDialogueToolSettings::GetPrivateStaticClass()
{
	using TClass = UDialogueToolSettings;
	if (!Z_Registration_Info_UClass_UDialogueToolSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DialogueToolSettings"),
			Z_Registration_Info_UClass_UDialogueToolSettings.InnerSingleton,
			StaticRegisterNativesUDialogueToolSettings,
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
	return Z_Registration_Info_UClass_UDialogueToolSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueToolSettings_NoRegister()
{
	return UDialogueToolSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueToolSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Dialogue Tool" },
		{ "IncludePath", "DialogueToolSettings.h" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoContinue_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Automatically continues after a fully revealed text when no response selection is waiting.\n" },
#endif
		{ "DisplayName", "Auto Continue" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically continues after a fully revealed text when no response selection is waiting." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoContinueDelay_MetaData[] = {
		{ "Category", "Text" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Defines the delay before automatic continuation in seconds.\n" },
#endif
		{ "DisplayName", "Auto Continue Delay" },
		{ "EditCondition", "AutoContinue" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Defines the delay before automatic continuation in seconds." },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowContinueClick_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Allows manual Continue input while automatic continuation is enabled.\n" },
#endif
		{ "DisplayName", "Allow Continue Click" },
		{ "EditCondition", "AutoContinue" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows manual Continue input while automatic continuation is enabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharactersPerSecond_MetaData[] = {
		{ "Category", "Text" },
		{ "DisplayName", "Characters Per Second" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResponseEndDialogueText_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResponseReturnDialogueText_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopicCustomTextList_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ID | Text\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ID | Text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResponseCustomTextList_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ID | Text\n" },
#endif
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ID | Text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RichTextStyleSet_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/DialogueToolSettings.h" },
		{ "RequiredAssetDataTags", "RowStructure=/Script/UMG.RichTextStyleRow" },
	};
#endif // WITH_METADATA
	static void NewProp_AutoContinue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoContinue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AutoContinueDelay;
	static void NewProp_AllowContinueClick_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_AllowContinueClick;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CharactersPerSecond;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ResponseEndDialogueText;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ResponseReturnDialogueText;
	static const UECodeGen_Private::FTextPropertyParams NewProp_TopicCustomTextList_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TopicCustomTextList_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TopicCustomTextList;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ResponseCustomTextList_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ResponseCustomTextList_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ResponseCustomTextList;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_RichTextStyleSet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueToolSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AutoContinue_SetBit(void* Obj)
{
	((UDialogueToolSettings*)Obj)->AutoContinue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AutoContinue = { "AutoContinue", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueToolSettings), &Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AutoContinue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoContinue_MetaData), NewProp_AutoContinue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AutoContinueDelay = { "AutoContinueDelay", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, AutoContinueDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoContinueDelay_MetaData), NewProp_AutoContinueDelay_MetaData) };
void Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AllowContinueClick_SetBit(void* Obj)
{
	((UDialogueToolSettings*)Obj)->AllowContinueClick = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AllowContinueClick = { "AllowContinueClick", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueToolSettings), &Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AllowContinueClick_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowContinueClick_MetaData), NewProp_AllowContinueClick_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_CharactersPerSecond = { "CharactersPerSecond", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, CharactersPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharactersPerSecond_MetaData), NewProp_CharactersPerSecond_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseEndDialogueText = { "ResponseEndDialogueText", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, ResponseEndDialogueText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResponseEndDialogueText_MetaData), NewProp_ResponseEndDialogueText_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseReturnDialogueText = { "ResponseReturnDialogueText", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, ResponseReturnDialogueText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResponseReturnDialogueText_MetaData), NewProp_ResponseReturnDialogueText_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_TopicCustomTextList_ValueProp = { "TopicCustomTextList", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_TopicCustomTextList_Key_KeyProp = { "TopicCustomTextList_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_TopicCustomTextList = { "TopicCustomTextList", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, TopicCustomTextList), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopicCustomTextList_MetaData), NewProp_TopicCustomTextList_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseCustomTextList_ValueProp = { "ResponseCustomTextList", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseCustomTextList_Key_KeyProp = { "ResponseCustomTextList_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseCustomTextList = { "ResponseCustomTextList", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, ResponseCustomTextList), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResponseCustomTextList_MetaData), NewProp_ResponseCustomTextList_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_RichTextStyleSet = { "RichTextStyleSet", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueToolSettings, RichTextStyleSet), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RichTextStyleSet_MetaData), NewProp_RichTextStyleSet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueToolSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AutoContinue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AutoContinueDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_AllowContinueClick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_CharactersPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseEndDialogueText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseReturnDialogueText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_TopicCustomTextList_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_TopicCustomTextList_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_TopicCustomTextList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseCustomTextList_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseCustomTextList_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_ResponseCustomTextList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueToolSettings_Statics::NewProp_RichTextStyleSet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueToolSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueToolSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_DialogueTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueToolSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueToolSettings_Statics::ClassParams = {
	&UDialogueToolSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueToolSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueToolSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueToolSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueToolSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueToolSettings()
{
	if (!Z_Registration_Info_UClass_UDialogueToolSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueToolSettings.OuterSingleton, Z_Construct_UClass_UDialogueToolSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueToolSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueToolSettings);
UDialogueToolSettings::~UDialogueToolSettings() {}
// ********** End Class UDialogueToolSettings ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h__Script_DialogueTool_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueToolSettings, UDialogueToolSettings::StaticClass, TEXT("UDialogueToolSettings"), &Z_Registration_Info_UClass_UDialogueToolSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueToolSettings), 740805734U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h__Script_DialogueTool_1337365485(TEXT("/Script/DialogueTool"),
	Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h__Script_DialogueTool_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_project_alay_Plugins_DialogueTool_Source_DialogueTool_Public_DialogueToolSettings_h__Script_DialogueTool_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
