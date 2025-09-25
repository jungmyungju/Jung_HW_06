// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Game_C_05 : ModuleRules
{
	public Game_C_05(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	}
}
