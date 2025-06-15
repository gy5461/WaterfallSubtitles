// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitleItemWidget.h"

#include "WaterfallSubtitlesAsset.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/AssetManager.h"

void UWaterfallSubtitleItemWidget::SetData(const FWaterfallSubtitleItem& InItemInfo)
{
	if (Text_Content)
	{
		Text_Content->SetText(FText::FromString(InItemInfo.Content));
	}

	if (Image_Head)
	{
		Image_Head->SetBrushFromAtlasInterface(InItemInfo.HeadIcon);
	}

	CacheSpeed = InItemInfo.Speed;
}
