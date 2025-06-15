// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WaterfallSubtitlesAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WaterfallSubtitleFunctionLibrary.generated.h"

class UWaterfallSubtitlesAsset;
/**
 * 
 */
UCLASS()
class WATERFALLSUBTITLES_API UWaterfallSubtitleFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static TMap<int32, FWaterfallSubtitleItem>& GetSubtitles();

	UFUNCTION()
	static bool GetSubtitle(int32 InSubtitleID, FWaterfallSubtitleItem& OutSubtitle);

	UFUNCTION()
	static void Init();
	
	static TMap<int32, FWaterfallSubtitleItem> CacheSubtitlesData;
};
