﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "DynamicWindowsPanel.generated.h"

class UDynamicWindowsPanelSlot;
class UDynamicWindowWidget;
/**
 * 
 */
UCLASS()
class DYNAMICWINDOWS_API UDynamicWindowsPanel : public UCanvasPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Dynamic Windows Panel")
	UDynamicWindowsPanelSlot* AddChildToDynamicWindows(UWidget* Content);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UDynamicWindowWidget> DynamicWindowWidgetClass;

protected: // UPanelWidget Interface
	virtual UClass* GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot* InSlot) override;
	virtual void OnSlotRemoved(UPanelSlot* InSlot) override;
};
