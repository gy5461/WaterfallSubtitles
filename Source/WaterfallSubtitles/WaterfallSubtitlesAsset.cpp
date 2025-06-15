// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterfallSubtitlesAsset.h"

#include "WaterfallSubtitleFunctionLibrary.h"

void UWaterfallSubtitlesAsset::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	UWaterfallSubtitleFunctionLibrary::Init();
}
