// Fill out your copyright notice in the Description page of Project Settings.


#include "HoudiniEngineBPFunctionLibrary.h"
#include "HoudiniRuntimeSettings.h"
#include "Misc/FileHelper.h"

void UHoudiniEngineBPFunctionLibrary::SetHoudiniEnvironmentFiles(const FString& Files)
{
    UHoudiniRuntimeSettings* Settings = GetMutableDefault<UHoudiniRuntimeSettings>();
    Settings->HoudiniEnvironmentFiles = Files;
    Settings->SaveConfig();
}

void UHoudiniEngineBPFunctionLibrary::SetHoudiniWorkingDirectory(const FString& Path)
{
    UHoudiniRuntimeSettings* Settings = GetMutableDefault<UHoudiniRuntimeSettings>();
    Settings->HoudiniWorkingDirectory = Path;
    Settings->SaveConfig();
}

void UHoudiniEngineBPFunctionLibrary::SetOtlSearchPath(const FString& Path)
{
    UHoudiniRuntimeSettings* Settings = GetMutableDefault<UHoudiniRuntimeSettings>();
    Settings->OtlSearchPath = Path;
    Settings->SaveConfig();
}

void UHoudiniEngineBPFunctionLibrary::SaveStringtoFile(const FString& String, const FString& Filename)
{
    FFileHelper::SaveStringToFile(String, *Filename);
}