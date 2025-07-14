// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitleFunctionLibrary.h"

TMap<int32, FWaterfallSubtitleItem> UWaterfallSubtitleFunctionLibrary::CacheSubtitlesData;

TMap<int32, FWaterfallSubtitleItem>& UWaterfallSubtitleFunctionLibrary::GetSubtitles()
{
	if (CacheSubtitlesData.IsEmpty())
	{
		Init();
	}
	
	return CacheSubtitlesData;
}

bool UWaterfallSubtitleFunctionLibrary::GetSubtitle(int32 InSubtitleID, FWaterfallSubtitleItem& OutSubtitle)
{
	if (FWaterfallSubtitleItem* Item = CacheSubtitlesData.Find(InSubtitleID))
	{
		OutSubtitle = *Item;

		return true;
	}

	return false;
}

void UWaterfallSubtitleFunctionLibrary::Init()
{
	if (UWaterfallSubtitlesAsset* WaterfallDA = LoadObject<UWaterfallSubtitlesAsset>(nullptr, TEXT("/Game/Data/DA_WaterfallSubtitles.DA_WaterfallSubtitles")))
	{
		CacheSubtitlesData = WaterfallDA->Subtitles;
		int32 Num = CacheSubtitlesData.Num();
		for(int32 Idx = 0; Idx < 100; ++Idx)
		{
			for(auto& Subtitle : WaterfallDA->Subtitles)
			{
				Num++;

				Subtitle.Value.Speed = FMath::RandRange(100, 600);
				Subtitle.Value.StartHeight = FMath::RandRange(50, 950);
				Subtitle.Value.StartTime = FMath::RandRange(0, 100);
				CacheSubtitlesData.Add(Num, Subtitle.Value);
			}
		}
	}
}
