// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitleItemWidget.h"

#include "WaterfallEmojiWidget.h"
#include "WaterfallSubtitlesAsset.h"
#include "Blueprint/WidgetTree.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

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
	CacheStartHeight = InItemInfo.StartHeight;

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

void UWaterfallSubtitleItemWidget::SetSubtitleTranslation(const UUserWidget* RootWidget, const FVector2D& InTrans)
{
	RootWidget->WidgetTree->ForEachWidget([&](UWidget* InWidget)
	{
		if(UUserWidget* InUserWidget = Cast<UUserWidget>(InWidget))
		{
			SetSubtitleTranslation(InUserWidget, InTrans);
			return;
		}
		
		TSharedRef<SWidget> SubtitleSWidget = InWidget->TakeWidget();
		TWeakPtr<FSlateCachedElementList> SubtitlePtr = SubtitleSWidget->GetPersistentState().CachedElementHandle.Ptr;
		if (SubtitlePtr.IsValid())
		{
			TSharedPtr<FSlateCachedElementList> SubtitlePtrPin = SubtitlePtr.Pin();
			if (SubtitlePtrPin.IsValid())
			{
				if (FSlateCachedFastPathRenderingData* CacheRenderDataPtr = SubtitlePtrPin->CachedRenderingData)
				{
					FSlateVertexArray& SubtitleItemVertices = CacheRenderDataPtr->Vertices;
					for(FSlateVertex& Vertex : SubtitleItemVertices)
					{
						Vertex.Position = FVector2f(Vertex.Position.X + InTrans.X, Vertex.Position.Y + InTrans.Y );
					}
				}
			}
		}
	});
}
