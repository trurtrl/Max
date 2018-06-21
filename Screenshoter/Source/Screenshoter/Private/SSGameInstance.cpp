// Fill out your copyright notice in the Description page of Project Settings.

#include "SSGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "MainMenu.h"

USSGameInstance::USSGameInstance()
{}

void USSGameInstance::Temp()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainUIClassFinder(TEXT("/Game/UI/MainMenu_BP.MainMenu_BP_C"));
	if (MainUIClassFinder.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("MainUIClassFinder is successeded"))
	//	TSubclassOf<class UUserWidget> MainUIClass = MainUIClassFinder.Class;
		MainUIClass = MainUIClassFinder.Class;
		if (MainUIClass)
		{
			UE_LOG(LogTemp, Warning, TEXT("MainUIClass"))
			MainUI = CreateWidget<UMainMenu>(GetWorld(), MainUIClass);
		}
		UE_LOG(LogTemp, Warning, TEXT("PASS"))
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MainUIClass is NULL"))
	}
	UE_LOG(LogTemp, Warning, TEXT("End of Constructor"))
	//	MainUI->AddToViewport();
}



