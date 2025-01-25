// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicWindowContainer.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void UDynamicWindowContainer::AddDynamicWindowTest()
{
	if (Widget)
	{
		UUserWidget* NewWidget = CreateWidget(GetOwningPlayer(), Widget);
		AddDynamicWindow(NewWidget);
	}
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
	DynamicWindowPanel = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("DynamicWindowPanel"));
	WidgetTree->RootWidget = DynamicWindowPanel;

	return Super::RebuildWidget();
}
