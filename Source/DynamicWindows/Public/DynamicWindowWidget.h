// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DynamicWindowWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS(Abstract)
class DYNAMICWINDOWS_API UDynamicWindowWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UButton> TaskBar;
};
