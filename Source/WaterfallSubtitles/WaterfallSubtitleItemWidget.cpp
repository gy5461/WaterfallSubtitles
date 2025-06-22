// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitleItemWidget.h"

#include "WaterfallEmojiWidget.h"
#include "WaterfallSubtitlesAsset.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/AssetManager.h"

void UWaterfallSubtitleItemWidget::SetData(const FWaterfallSubtitleItem& InItemInfo)
{
	if (Text_Content)
	{
		Text_Content->SetText(FText::FromString(InItemInfo.Content));
		Text_Content->SetColorAndOpacity(InItemInfo.TextColor);
	}

	if (Image_Bg)
	{
		Image_Bg->SetColorAndOpacity(InItemInfo.TextBgColor);
	}

	if (Image_Head)
	{
		Image_Head->SetBrushFromAtlasInterface(InItemInfo.HeadIcon);
	}

	CacheSpeed = InItemInfo.Speed;

	if (HB_Content)
	{
		for (auto& Emoji : InItemInfo.EmojiList)
		{
			if (UWaterfallEmojiWidget* SubtitleItemUI = CreateWidget<UWaterfallEmojiWidget>(this, EmojiItemClass))
			{
				SubtitleItemUI->SetIcon(Emoji);
				HB_Content->AddChildToHorizontalBox(SubtitleItemUI);
			}
		}
	}
}
