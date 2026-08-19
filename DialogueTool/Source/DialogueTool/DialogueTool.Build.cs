// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DialogueTool : ModuleRules
{
	public DialogueTool(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"DeveloperSettings",
			"Engine"
		});
	}
}
