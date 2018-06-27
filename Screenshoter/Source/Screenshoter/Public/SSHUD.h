// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SSHUD.generated.h"

class UMainMenu;
class USettingsMenu;
class UMyFileManager;

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
	TSubclassOf<class UUserWidget> FileManagerClass;

	UMainMenu* MainUI = nullptr;
	USettingsMenu* SettingsMenu = nullptr;
	UMyFileManager* FileManager = nullptr;

	ASSHUD();

	virtual void BeginPlay() override;

private:

	FString RootLocation = "/Pictures/Screenshots/";
	FString CurrentPath = RootLocation;	//	MUST be finished with "/"
	FString FolderName = "";



	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void TakeScreenshot();

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void SettingsMenuShow();

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void SetFolderSettings();
	
	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void FileManagerShow();
};
