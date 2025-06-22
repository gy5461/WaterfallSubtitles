// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WaterfallSubtitlesAsset.h"
#include "Blueprint/UserWidget.h"
#include "WaterfallSubtitleItemWidget.generated.h"

class UHorizontalBox;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class WATERFALLSUBTITLES_API UWaterfallSubtitleItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetData(const FWaterfallSubtitleItem& InItemInfo);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* Text_Content;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UImage* Image_Head;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UImage* Image_Bg;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UHorizontalBox* HB_Content;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UUserWidget> EmojiItemClass;

	int32 CacheSpeed;
};
