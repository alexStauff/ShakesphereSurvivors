// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShakesphereSurvivors : ModuleRules
{
	public ShakesphereSurvivors(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ShakesphereSurvivors",
			"ShakesphereSurvivors/Variant_Strategy",
			"ShakesphereSurvivors/Variant_Strategy/UI",
			"ShakesphereSurvivors/Variant_TwinStick",
			"ShakesphereSurvivors/Variant_TwinStick/AI",
			"ShakesphereSurvivors/Variant_TwinStick/Gameplay",
			"ShakesphereSurvivors/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
