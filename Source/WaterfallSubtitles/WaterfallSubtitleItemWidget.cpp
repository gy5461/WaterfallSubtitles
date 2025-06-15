// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitleItemWidget.h"

#include "WaterfallSubtitlesAsset.h"
#include "Components/TextBlock.h"

void UWaterfallSubtitleItemWidget::SetData(const FWaterfallSubtitleItem& InItemInfo)
{
	if (Text_Content)
	{
		Text_Content->SetText(FText::FromString(InItemInfo.Content));
	}

	CacheSpeed = InItemInfo.Speed;
}
