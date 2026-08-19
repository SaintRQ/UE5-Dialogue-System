// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DialogueToolEditor : ModuleRules
{
	public DialogueToolEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"AssetDefinition",
			"Core",
			"CoreUObject",
			"DialogueTool",
			"Engine",
			"GraphEditor",
			"Slate",
			"SlateCore",
			"UnrealEd"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"ApplicationCore",
			"AssetRegistry",
			"AssetTools",
			"PropertyEditor"
		});
	}
}
