// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaterfallSubtitleMainWidget.generated.h"

class UWaterfallSubtitleItemWidget;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class WATERFALLSUBTITLES_API UWaterfallSubtitleMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UCanvasPanel* Pnl_Main;


	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UUserWidget> SubtitleItemClass;

	UPROPERTY()
	TArray<UWaterfallSubtitleItemWidget*> ShowingSubtitles;
};
