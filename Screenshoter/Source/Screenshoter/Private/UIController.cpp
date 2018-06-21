// Fill out your copyright notice in the Description page of Project Settings.

#include "UIController.h"
#include "MainMenu.h"

#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/UMG/Public/Components/Viewport.h"

void AUIController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI Mode;
	//Mode.SetLockMouseToViewport(true);
	Mode.SetHideCursorDuringCapture(false);
	SetInputMode(Mode);

	

	/*ScreenshotMenu = CreateWidget<UScreenshotMenu>(this, UScreenshotMenu::StaticClass());
	if (!ScreenshotMenu)
	{
		UE_LOG(LogTemp, Warning, TEXT("Background is absent"))
		return;
	};
	ScreenshotMenu->AddToViewport(100);*/

}

void AUIController::SetMenu(UMainMenu* MenuToSet)
{
	WidgetMenu = MenuToSet;
}
