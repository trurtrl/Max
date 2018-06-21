// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SSHUD.generated.h"

class UMainMenu;
class USettingsMenu;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API ASSHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	TSubclassOf<class UUserWidget> MainUIClass;
	TSubclassOf<class UUserWidget> SettingsMenuClass;

	UMainMenu* MainUI = nullptr;
	USettingsMenu* SettingsMenu = nullptr;

	ASSHUD();

	virtual void BeginPlay() override;

private:
	FString CurrentFileName = "";
	FString RootLocation = "/Pictures/Screenshots/";
	FString FolderName = "";

	FString SetFilesLocation();

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void TakeScreenshot();

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void SettingsMenuShow();

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void SetFolderSettings();
	
	
};
