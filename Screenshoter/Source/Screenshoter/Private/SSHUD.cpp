// Fill out your copyright notice in the Description page of Project Settings.

#include "SSHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "MainMenu.h"
#include "SettingsMenu.h"
#include "MyFileManager.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"

ASSHUD::ASSHUD()
{
	//	Load class from asset in Content Browser of the UserWidget we created (UMainMenu)
	//	ConstructorHelpers::FClassFinder<UUserWidget> MainUIClassFinder(TEXT("/Game/UI/MainMenu_BP.MainMenu_BP_C"));
	ConstructorHelpers::FClassFinder<UUserWidget> MainUIClassFinder(TEXT("/Game/UI/MainMenu_BP"));
	if (MainUIClassFinder.Succeeded())
	{
		//	Assign the class of the loaded asset to the WigetClass variable, which is a "subclass" of UUserWidget : Which our asset class is
		MainUIClass = MainUIClassFinder.Class;
	}

	ConstructorHelpers::FClassFinder<UUserWidget> SettingsMenuClassFinder(TEXT("/Game/UI/SettingsMenu_BP"));
	if (SettingsMenuClassFinder.Succeeded())
	{
		SettingsMenuClass = SettingsMenuClassFinder.Class;
	}

	ConstructorHelpers::FClassFinder<UUserWidget> FileManagerClassFinder(TEXT("/Game/UI/MyFileManager_BP"));
	if (FileManagerClassFinder.Succeeded())
	{
		FileManagerClass = FileManagerClassFinder.Class;
	}

}

void ASSHUD::BeginPlay()
{
	Super::BeginPlay();

	if (SettingsMenuClass)
	{
		SettingsMenu = CreateWidget<USettingsMenu>(GetWorld(), SettingsMenuClass);
		if (SettingsMenu)
		{
			SettingsMenu->ButtonOk->OnPressed.AddDynamic(this, &ASSHUD::SetFolderSettings);
			SettingsMenu->SetHeader(SettingsMenuHeader);
		};
	};

	// Make sure asset was loaded and class was set 
	if (MainUIClass)
	{
		//	Create the widget of our UUserWidget type (UMainMenu) from the class we loaded from the Content Browser
		MainUI = CreateWidget<UMainMenu>(GetWorld(), MainUIClass);
		if (MainUI)
		{
			MainUI->AddToViewport();

			MainUI->ButtonScreenshot->OnPressed.AddDynamic(this, &ASSHUD::TakeScreenshot);
			MainUI->ButtonMenuSettings->OnPressed.AddDynamic(this, &ASSHUD::SettingsMenuShow);
		};
	};

	if (FileManagerClass)
	{
		FileManager = CreateWidget<UMyFileManager>(GetWorld(), FileManagerClass);
		if (FileManager)
		{
			MainUI->ButtonMenuFileManager->OnReleased.AddDynamic(this, &ASSHUD::FileManagerShow);
		}
	}

}

void ASSHUD::TakeScreenshot()
{
	FString CurrentFilePathName = CurrentPath + FolderName;
	FScreenshotRequest::RequestScreenshot(CurrentFilePathName, false, true);
}



void ASSHUD::SettingsMenuShow()
{
	MainUI->MenuHide();
	SettingsMenu->Show();
}

void ASSHUD::SetFolderSettings()
{
	if (SettingsMenu->TextBox)
	{
		FolderName = SettingsMenu->TextBox->GetText().ToString();
	}

	CurrentPath = CurrentPath + FolderName + "/";
	UE_LOG(LogTemp, Warning, TEXT("FileName:%s"), *CurrentPath);
	SettingsMenu->Hide();
}

void ASSHUD::FileManagerShow()
{
//	UE_LOG(LogTemp, Warning, TEXT("Max = %i"), FileManager->GetFoundDMax())

	//	FileManager->ScanDirectory(CurrentPath);
	//	FileManager->PrintList();

	MainUI->MenuHide();
	FileManager->Show();
}
