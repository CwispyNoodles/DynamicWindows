// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicWindowContainer.h"

#include "DynamicWindowWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/NamedSlot.h"

UDynamicWindowContainer::UDynamicWindowContainer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UDynamicWindowWidget> DefaultDynamicWindowWidget(TEXT("/DynamicWindows/W_DefaultDynamicWindow"));
	DynamicWindowWidgetClass = DefaultDynamicWindowWidget.Class;
	
}

UCanvasPanelSlot* UDynamicWindowContainer::AddDynamicWindow(bool& bSuccess, UWidget* Content)
{
	UDynamicWindowWidget* NewDynamicWindow = InitializeNewDynamicWindow(bSuccess);
	if (!bSuccess)
		return nullptr;
	
	NewDynamicWindow->Content->SetContent(Content);
	UCanvasPanelSlot* CanvasPanelSlot = DynamicWindowPanel->AddChildToCanvas(NewDynamicWindow);
	CanvasPanelSlot->SetAutoSize(true);
	bSuccess = true;
	return CanvasPanelSlot;
}

UDynamicWindowWidget* UDynamicWindowContainer::InitializeNewDynamicWindow(bool& bSuccess)
{
	if (!DynamicWindowWidgetClass)
	{
		bSuccess = false;
		return nullptr;
	}
	
	UDynamicWindowWidget* NewDynamicWindow = CreateWidget<UDynamicWindowWidget>(this, DynamicWindowWidgetClass);
	
	bSuccess = true;
	return NewDynamicWindow;
}

TSharedRef<SWidget> UDynamicWindowContainer::RebuildWidget()
{
	if (WidgetTree)
	{
		DynamicWindowPanel = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("DynamicWindowPanel"));
		WidgetTree->RootWidget = DynamicWindowPanel;
	}
	return Super::RebuildWidget();
}

void UDynamicWindowContainer::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	
}
