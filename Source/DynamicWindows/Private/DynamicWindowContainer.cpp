// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicWindowContainer.h"

#include "DynamicWindowWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

UDynamicWindowContainer::UDynamicWindowContainer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UDynamicWindowWidget> DefaultDynamicWindowWidget(TEXT("/DynamicWindows/W_DefaultDynamicWindow"));
	DynamicWindowWidgetClass = DefaultDynamicWindowWidget.Class;
	
}

UCanvasPanelSlot* UDynamicWindowContainer::AddDynamicWindow(UWidget* Content)
{
	UCanvasPanelSlot* CanvasPanelSlot = DynamicWindowPanel->AddChildToCanvas(Content);
	CanvasPanelSlot->SetAutoSize(true);
	return CanvasPanelSlot;
}

void UDynamicWindowContainer::NativeConstruct()
{
	Super::NativeConstruct();

	
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
