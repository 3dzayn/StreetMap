// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StreetMap.h"
#include <Math/Vector2D.h>
#include "StreetMapBPFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class STREETMAPRUNTIME_API UStreetMapBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "StreetMap")
		static bool GetRoadFromWorldLocation(const UStreetMap* StreetMap, FVector2D loc, float threshold, FStreetMapRoad& result);

	UFUNCTION(BlueprintCallable, Category = "StreetMap")
		static void HelloStreetMap();
};
