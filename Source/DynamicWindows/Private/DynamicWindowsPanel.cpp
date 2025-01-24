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
	Super::OnSlotAdded(InSlot);
}

void UDynamicWindowsPanel::OnSlotRemoved(UPanelSlot* InSlot)
{
	Super::OnSlotRemoved(InSlot);
}
