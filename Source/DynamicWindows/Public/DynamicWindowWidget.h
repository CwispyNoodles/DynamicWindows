// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DynamicWindowWidget.generated.h"

class UCanvasPanelSlot;

struct FDynamicWindowDragOperation
{
	FDynamicWindowDragOperation() = delete;
	FDynamicWindowDragOperation(FVector2D InLocalMousePos, UCanvasPanelSlot* InDynamicWindowSlot)
		: LocalMousePos(InLocalMousePos), DynamicWindowSlot(InDynamicWindowSlot)
	{}
	
	FVector2D LocalMousePos;
	UCanvasPanelSlot* DynamicWindowSlot = nullptr;
};

class UButton;
/**
 * 
 */
UCLASS(Abstract)
class DYNAMICWINDOWS_API UDynamicWindowWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BringToFront();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UButton> Taskbar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UButton> CloseButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UNamedSlot> Content;

private:
	UFUNCTION()
	void HandleTaskbarPressed();

	UFUNCTION()
	void HandleTaskbarReleased();

	bool bIsDraggingWindow = false;
	FDynamicWindowDragOperation DynamicWindowDragOperation = FDynamicWindowDragOperation(FVector2D(), nullptr);

public: // UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
