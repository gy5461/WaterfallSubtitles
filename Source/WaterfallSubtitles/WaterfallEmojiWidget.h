// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaterfallEmojiWidget.generated.h"

class ISlateTextureAtlasInterface;
class UImage;
/**
 * 
 */
UCLASS()
class WATERFALLSUBTITLES_API UWaterfallEmojiWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetIcon(const TScriptInterface<ISlateTextureAtlasInterface>& InIcon);
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UImage* Image_Emoji;
};
