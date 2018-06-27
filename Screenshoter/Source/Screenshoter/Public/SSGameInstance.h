// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SSGameInstance.generated.h"

class UMainMenu;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API USSGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	FString GetRootLocation();
	void SetPathToScreenshot(FString& Dir);
	FString GetPathToScreenshot();


private:

	FString RootLocation = "/Pictures/Screenshots/";
	FString PathToScreenshot = RootLocation;
};
