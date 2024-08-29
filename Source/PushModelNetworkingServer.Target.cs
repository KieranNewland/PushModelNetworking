// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PushModelNetworkingServerTarget : TargetRules
{
	public PushModelNetworkingServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		bWithPushModel = true;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("PushModelNetworking");
	}
}
