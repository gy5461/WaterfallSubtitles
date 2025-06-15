// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WaterfallSubtitlesAsset.generated.h"

USTRUCT(BlueprintType)
struct FWaterfallSubtitleItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕ID"))
	int32 ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕内容"))
	FString Content;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕头像"))
	UTexture2D* HeadIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕起始高度"))
	int32 StartHeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕播放速度"))
	float Speed = 5.f;
};

/**
 * 
 */
UCLASS()
class WATERFALLSUBTITLES_API UWaterfallSubtitlesAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕列表"))
	TMap<int32, FWaterfallSubtitleItem> Subtitles;
};
