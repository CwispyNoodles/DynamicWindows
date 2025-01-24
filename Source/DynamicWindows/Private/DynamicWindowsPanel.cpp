// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicWindowsPanel.h"

#include "DynamicWindowsPanelSlot.h"

UDynamicWindowsPanelSlot* UDynamicWindowsPanel::AddChildToDynamicWindows(UWidget* Content)
{
	return Cast<UDynamicWindowsPanelSlot>( Super::AddChild(Content) );
}

UClass* UDynamicWindowsPanel::GetSlotClass() const
{
	return UDynamicWindowsPanelSlot::StaticClass();
}

void UDynamicWindowsPanel::OnSlotAdded(UPanelSlot* InSlot)
{
	// Add the child to the live canvas if it already exists
	// if ( MyCanvas.IsValid() )
	// {
	// 	CastChecked<UDynamicWindowsPanelSlot>(InSlot)->BuildDynamicWindowSlot(MyCanvas.ToSharedRef());
	// }
}

void UDynamicWindowsPanel::OnSlotRemoved(UPanelSlot* InSlot)
{
	Super::OnSlotRemoved(InSlot);
}
