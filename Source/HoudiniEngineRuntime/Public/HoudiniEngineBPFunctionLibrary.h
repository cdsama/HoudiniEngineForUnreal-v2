// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HoudiniEngineBPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class HOUDINIENGINERUNTIME_API UHoudiniEngineBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Houdini|Config")
	static void SetHoudiniEnvironmentFiles(const FString& Files);

	UFUNCTION(BlueprintCallable, Category = "Houdini|Config")
	static void SetHoudiniWorkingDirectory(const FString& Path);

    UFUNCTION(BlueprintCallable, Category = "Houdini|Config")
    static void SetOtlSearchPath(const FString& Path);

	UFUNCTION(BlueprintCallable, Category = "File|String")
	static void SaveStringtoFile(const FString& String,const FString& Filename);
	
};
