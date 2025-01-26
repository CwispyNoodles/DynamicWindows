// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "DynamicWindowContainer.generated.h"

class UDynamicWindowWidget;
class UCanvasPanelSlot;
class UCanvasPanel;

USTRUCT(BlueprintType)
struct DYNAMICWINDOWS_API FDynamicWindowArguments
{
	GENERATED_BODY()

	FAnchorData DynamicWindowLayout;

	UPROPERTY(BlueprintReadWrite)
	FText Title = FText::FromString("Placeholder");

	UPROPERTY(BlueprintReadWrite)
	UWidget* Content = nullptr;
};
/**
 * 
 */
UCLASS(NotBlueprintable)
class DYNAMICWINDOWS_API UDynamicWindowContainer : public UUserWidget
{
	GENERATED_BODY()

public:
	UDynamicWindowContainer(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable)
	UCanvasPanelSlot* AddDynamicWindow(FDynamicWindowArguments InArgs, bool& bSuccess);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UDynamicWindowWidget> DynamicWindowWidgetClass;

private:
	UDynamicWindowWidget* InitializeNewDynamicWindow(bool& bSuccess);
	
protected:
	UPROPERTY()
	TObjectPtr<UCanvasPanel> DynamicWindowPanel;

public: // UUserWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;

	
};
