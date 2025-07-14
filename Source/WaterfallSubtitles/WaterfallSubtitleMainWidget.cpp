// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitleMainWidget.h"

#include "WaterfallSubtitleFunctionLibrary.h"
#include "WaterfallSubtitleItemWidget.h"
#include "WaterfallSubtitlesAsset.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void UWaterfallSubtitleMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TMap<int32, FWaterfallSubtitleItem> Subtitles = UWaterfallSubtitleFunctionLibrary::GetSubtitles();

	if (Pnl_Main == nullptr)
	{
		return;
	}

	FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(this);
	float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this);
	float ScreenSizeX = ViewportSize.X / ViewportScale;

	ShowingSubtitles.Empty();
	for (auto& Subtitle : Subtitles)
	{
		FWaterfallSubtitleItem ItemInfo = Subtitle.Value;

		auto CreateSubtitle = [this, ItemInfo, ScreenSizeX]()
		{
			if (UWaterfallSubtitleItemWidget* SubtitleItemUI = CreateWidget<UWaterfallSubtitleItemWidget>(this, SubtitleItemClass))
			{
				SubtitleItemUI->SetData(ItemInfo);
			
				if (UCanvasPanelSlot* ItemSlot = Pnl_Main->AddChildToCanvas(SubtitleItemUI))
				{
					ItemSlot->SetAutoSize(true);
					FVector2D ItemStartPos = FVector2D(ScreenSizeX, ItemInfo.StartHeight);
					ItemSlot->SetPosition(ItemStartPos);
				}

				ShowingSubtitles.Add(SubtitleItemUI);
			}
		};

		if (FMath::IsNearlyEqual(ItemInfo.StartTime, 0))
		{
			CreateSubtitle();
		}
		else
		{
			FTimerHandle StartPlayTimerHandle;
			GetWorld()->GetTimerManager().SetTimer(StartPlayTimerHandle, CreateSubtitle, ItemInfo.StartTime, false, ItemInfo.StartTime);
		}
	}
}

void UWaterfallSubtitleMainWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	for (auto SubtitleItr = ShowingSubtitles.CreateIterator(); SubtitleItr; ++SubtitleItr)
	{
		UWaterfallSubtitleItemWidget* SubtitleItemUI = *SubtitleItr;
		if (SubtitleItemUI == nullptr)
		{
			continue;
		}
	
		if (UCanvasPanelSlot* ItemSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(SubtitleItemUI))
		{
			FVector2D CurPos = ItemSlot->GetPosition();
			FVector2D ItemSize = SubtitleItemUI->GetDesiredSize();
	
			if (CurPos.X + ItemSize.X < 0)
			{
				FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(this);
				float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this);
				float ScreenSizeX = ViewportSize.X / ViewportScale;
				
				FVector2D ItemStartPos = FVector2D(ScreenSizeX, SubtitleItemUI->CacheStartHeight);
				ItemSlot->SetPosition(ItemStartPos);
			}
			else
			{
				FVector2D NewPos = FVector2D(CurPos.X - SubtitleItemUI->CacheSpeed * InDeltaTime, CurPos.Y);
				ItemSlot->SetPosition(NewPos);
			}
		}
	}
}
