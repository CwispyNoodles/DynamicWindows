﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DynamicWindowContainer.generated.h"

class UCanvasPanelSlot;
class UCanvasPanel;
/**
 * 
 */
UCLASS(NotBlueprintable)
class DYNAMICWINDOWS_API UDynamicWindowContainer : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(CallInEditor)
	void AddDynamicWindowTest();
	
	UFUNCTION(BlueprintCallable)
	UCanvasPanelSlot* AddDynamicWindow(UWidget* Content);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> Widget;

protected:
	UPROPERTY()
	TObjectPtr<UCanvasPanel> DynamicWindowPanel;

public: // UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;

	
};
