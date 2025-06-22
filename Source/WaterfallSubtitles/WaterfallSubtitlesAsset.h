// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WaterfallSubtitlesAsset.generated.h"

class ISlateTextureAtlasInterface;

USTRUCT(BlueprintType)
struct FWaterfallSubtitleItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕内容"))
	FString Content;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕头像"))
	TScriptInterface<ISlateTextureAtlasInterface> HeadIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕起始高度"))
	int32 StartHeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕播放速度"))
	float Speed = 200.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕开始播放时间"))
	float StartTime = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕颜色"))
	FLinearColor TextColor = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "字幕背景颜色"))
	FLinearColor TextBgColor = FLinearColor(0, 0, 0, 0.5);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "表情列表"))
	TArray<TScriptInterface<ISlateTextureAtlasInterface>> EmojiList;
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
