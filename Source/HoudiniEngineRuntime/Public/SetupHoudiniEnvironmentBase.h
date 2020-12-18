// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SetupHoudiniEnvironmentBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class HOUDINIENGINERUNTIME_API USetupHoudiniEnvironmentBase : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetupHoudiniEnvironment();

};
