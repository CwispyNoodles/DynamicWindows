// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "DynamicWindowsPanelSlot.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMICWINDOWS_API UDynamicWindowsPanelSlot : public UPanelSlot
{
	GENERATED_BODY()

public:
	void BuildDynamicWindowSlot(TSharedRef<SConstraintCanvas> Canvas);
};
