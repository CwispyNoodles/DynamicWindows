// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicWindowContainer.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"

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
	return DynamicWindowPanel->AddChildToCanvas(Content);
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
