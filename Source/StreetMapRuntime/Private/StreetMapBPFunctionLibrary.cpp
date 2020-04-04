// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetMapBPFunctionLibrary.h"


bool UStreetMapBPFunctionLibrary::GetRoadFromWorldLocation(const UStreetMap* StreetMap, FVector2D loc, float threshold, FStreetMapRoad& result)
{
	if (StreetMap == nullptr)
		return false;

	FBox2D mapBox(StreetMap->GetBoundsMin(), StreetMap->GetBoundsMax());

	if (!mapBox.IsInside(loc))
		return false;

	TArray<FStreetMapRoad> roads = StreetMap->GetRoads();
	for (FStreetMapRoad road : roads)
	{
		for (int i = 0, len = road.RoadPoints.Num() - 1; i < len; i++)
		{
			if (FMath::PointDistToSegment(FVector(loc, 0), FVector(road.RoadPoints[i], 0), FVector(road.RoadPoints[i + 1], 0)) <= threshold)
			{
				result = road;
				//UE_LOG(LogTemp, Log, TEXT("Found road: %s"), *road.RoadName);
				return true;
			}
		}
	}
	return false;
}

void UStreetMapBPFunctionLibrary::HelloStreetMap()
{
	UE_LOG(LogTemp, Log, TEXT("Hello from BP StreetMap Lib"));
}
