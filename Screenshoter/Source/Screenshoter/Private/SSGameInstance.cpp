// Fill out your copyright notice in the Description page of Project Settings.

#include "SSGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "MainMenu.h"


FString USSGameInstance::GetRootLocation()
{
	return RootLocation;
}

void USSGameInstance::SetPathToScreenshot(FString& Dir)
{
	PathToScreenshot = Dir;
}

FString USSGameInstance::GetPathToScreenshot()
{
	return PathToScreenshot;
}