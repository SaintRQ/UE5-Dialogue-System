// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueTool_init() {}
	DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature();
	DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature();
	DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature();
	DIALOGUETOOL_API UFunction* Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DialogueTool;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DialogueTool()
	{
		if (!Z_Registration_Info_UPackage__Script_DialogueTool.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueTool_DialogueFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueTool_DialogueResponsesUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueTool_DialogueSoundRequested__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DialogueTool_DialogueTextUpdated__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/DialogueTool",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x1665590E,
				0x154638BC,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DialogueTool.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_DialogueTool.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DialogueTool(Z_Construct_UPackage__Script_DialogueTool, TEXT("/Script/DialogueTool"), Z_Registration_Info_UPackage__Script_DialogueTool, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1665590E, 0x154638BC));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
