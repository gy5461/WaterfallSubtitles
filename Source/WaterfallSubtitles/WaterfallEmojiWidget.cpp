// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallEmojiWidget.h"

#include "Components/Image.h"

void UWaterfallEmojiWidget::SetIcon(const TScriptInterface<ISlateTextureAtlasInterface>& InIcon)
{
	if (Image_Emoji)
	{
		Image_Emoji->SetBrushFromAtlasInterface(InIcon);
	}
}
