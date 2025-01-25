// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "DynamicWindowsPanelSlot.generated.h"

class UDynamicWindowWidget;
/**
 * 
 */
UCLASS()
class DYNAMICWINDOWS_API UDynamicWindowsPanelSlot : public UCanvasPanelSlot
{
	GENERATED_BODY()

public:
	TObjectPtr<UDynamicWindowWidget> DynamicWindowWidget;
};
