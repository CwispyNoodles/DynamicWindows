// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicWindowWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/PanelWidget.h"

void UDynamicWindowWidget::BringToFront()
{
	if (UCanvasPanel* Parent = Cast<UCanvasPanel>(GetParent()))
	{
		UCanvasPanelSlot* CanvasPanelSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(this);
		FAnchorData Layout = CanvasPanelSlot->GetLayout();
		RemoveFromParent();
		CanvasPanelSlot = Parent->AddChildToCanvas(this);
		CanvasPanelSlot->SetLayout(Layout);
		CanvasPanelSlot->SetAutoSize(true);
	}
}

void UDynamicWindowWidget::HandleTaskbarPressed()
{
	BringToFront();
	if (UCanvasPanelSlot* CanvasPanelSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(this))
	{
		FDynamicWindowDragOperation NewDynamicWindowDragOp
		(
		UWidgetLayoutLibrary::GetMousePositionOnViewport(this) - CanvasPanelSlot->GetPosition(),
		CanvasPanelSlot
		);

		DynamicWindowDragOperation = NewDynamicWindowDragOp;
		bIsDraggingWindow = true;
	}
}

void UDynamicWindowWidget::HandleTaskbarReleased()
{
	bIsDraggingWindow = false;
}

void UDynamicWindowWidget::HandleClosedButtonPressed()
{
	RemoveFromParent();
}

void UDynamicWindowWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Taskbar->OnPressed.AddDynamic(this, &ThisClass::HandleTaskbarPressed);
	Taskbar->OnReleased.AddDynamic(this, &ThisClass::HandleTaskbarReleased);

	CloseButton->OnPressed.AddDynamic(this, &ThisClass::HandleClosedButtonPressed);
}

void UDynamicWindowWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (bIsDraggingWindow)
	{
		DynamicWindowDragOperation.DynamicWindowSlot->SetPosition(UWidgetLayoutLibrary::GetMousePositionOnViewport(this) - DynamicWindowDragOperation.LocalMousePos);
		
	}
}

FReply UDynamicWindowWidget::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton().IsMouseButton())
	{
		BringToFront();
	}
	return Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
}


