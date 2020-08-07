/*
* Copyright (c) <2018> Side Effects Software Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. The name of Side Effects Software may not be used to endorse or
*    promote products derived from this software without specific prior
*    written permission.
*
* THIS SOFTWARE IS PROVIDED BY SIDE EFFECTS SOFTWARE "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
* NO EVENT SHALL SIDE EFFECTS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "HAPI/HAPI_Common.h"

#include "CoreMinimal.h"

class UHoudiniInput;
class UHoudiniOutput;
class UHoudiniAssetComponent;
class UHoudiniSplineComponent;
class USceneComponent;
class USplineComponent;

struct FHoudiniGeoPartObject;
struct FHoudiniOutputObjectIdentifier;
struct FHoudiniOutputObject;

enum class EHoudiniCurveType : int8;
enum class EHoudiniCurveMethod : int8;

struct HOUDINIENGINE_API FHoudiniSplineTranslator
{
	// Get the cooked Houdini curve.
	static bool UpdateHoudiniCurve(UHoudiniSplineComponent * HoudiniSplineComponent);

	// Get all cooked Houdini curves of an input.
	static void UpdateHoudiniInputCurves(UHoudiniInput* Input);

	// Get all cooked Houdini curves of inputs in an HAC.
	static void UpdateHoudiniInputCurves(UHoudiniAssetComponent* HAC);

	// Upload Houdini spline component data to the curve node, and then sync the Houdini Spline Component with the curve node.
	static bool HapiUpdateNodeForHoudiniSplineComponent(UHoudiniSplineComponent* HoudiniSplineComponent);

	// Create a new curve node.
	static bool HapiCreateInputNodeForHoudiniSplineComponent(
		const FString& InObjNodeName, UHoudiniSplineComponent* SplineComponent);

	// Update the curve node data, or create a new curve node if the CurveNodeId is valid.
	static bool HapiCreateCurveInputNodeForData(
		HAPI_NodeId& CurveNodeId,
		const FString& InputNodeName,
		TArray<FVector>* Positions,
		TArray<FQuat>* Rotations,
		TArray<FVector>* Scales3d,
		EHoudiniCurveType InCurveType,
		EHoudiniCurveMethod InCurveMethod,
		const bool& InClosed,
		const bool& InReversed,
		const bool& InForceClose = false,
		const FTransform& ParentTransform = FTransform::Identity);

	// Create a default curve node.
	static bool HapiCreateCurveInputNode(
		HAPI_NodeId& OutCurveNodeId, const FString& InputNodeName);

	// Create a Houdini spline component from a given editable node. (Only called once when first build the editable node.)
	static UHoudiniSplineComponent* CreateHoudiniSplineComponentFromHoudiniEditableNode(const int32 & GeoId, const FString & PartName, UHoudiniAssetComponent* OuterHAC);

	// Helper functions.
	static void ExtractStringPositions(const FString& Positions, TArray<FVector>& OutPositions);

	static void ConvertToVectorData(const TArray<float> & InRawData, TArray<FVector>& OutVectorData);

	static void ConvertToVectorData(const TArray<float> & InRawData, TArray<TArray<FVector>>& OutVectorData, const TArray<int32>& CurveCounts);

	static void CreatePositionsString(const TArray<FVector>& InPositions, FString& OutPositionString);

	static bool CreateOutputSplinesFromHoudiniGeoPartObject(const FHoudiniGeoPartObject& InHGPO, UHoudiniAssetComponent* InOuter,
		TMap<FHoudiniOutputObjectIdentifier, FHoudiniOutputObject>& InSplines,
		TMap<FHoudiniOutputObjectIdentifier, FHoudiniOutputObject>& OutSplines,
		const bool& InForceRebuild);

	static bool CreateAllSplinesFromHoudiniOutput(UHoudiniOutput* InOutput, UObject* InOuterComponent);

	static USplineComponent* CreateOutputUnrealSplineComponent(const TArray<FVector>& CurvePoints, 
				const TArray<FVector>& CurveRotations, const TArray<FVector>& CurveScales, UHoudiniAssetComponent* OuterHAC);

	static UHoudiniSplineComponent* CreateOutputHoudiniSplineComponent(TArray<FVector>& CurvePoints, const TArray<FVector>& CurveRotations, const TArray<FVector>& CurveScales, UHoudiniAssetComponent* OuterHAC);

	static bool UpdateOutputUnrealSplineComponent(const TArray<FVector>& CurvePoints, USplineComponent* EditedSplineComponent, const EHoudiniCurveType& CurveType);

	static bool UpdateOutputHoudiniSplineComponent(const TArray<FVector>& CurvePoints, UHoudiniSplineComponent* EditedHoudiniSplineComponent);

	static void ReselectSelectedActors();
};