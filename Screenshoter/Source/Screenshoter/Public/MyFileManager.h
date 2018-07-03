// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyFileManager.generated.h"

//class IFileManager;
class UButton;
class UTextBlock;
class UScrollBox;
class UFMItemWidget;
class USettingsMenu;
class UPictureViewer;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API UMyFileManager : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UMyFileManager(const FObjectInitializer & ObjectInitializer);
	virtual TSharedRef<SWidget> RebuildWidget();
	virtual void NativeConstruct() override;


	TSubclassOf<class USettingsMenu> SettingsMenuClass;
	USettingsMenu* AddDirectoryMenu = nullptr;

	UPictureViewer* PictureViewer = nullptr;

	FString NameTextBlockPath = "";
	FString NameTextBlockButtonExit = "X";
	FString NameTextBlockButtonMode = "Mode";
	FString NameTextBlockButtonAddDirectory = "New Directory";
	FString NameTextBlockButtonSend = "Send";
	FString NameItemUp = ". .";

	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockPath = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonExit = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonExit = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonMode = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonMode = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonAddDirectory = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonAddDirectory = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonSend = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonSend = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UScrollBox* ScrollBoxFilesField;


	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void SetToFile(FString& ToNewFile);


	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void AddItem();

	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void Show();

	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void Hide();


private:

	FString RootLocation = "";
	FString CurrentLocation = "";	//	MUST be finished with "/"
	FString ToFile = "";
//	FString NameFunctionSetToDir = "SetToDir";	//	Works through FMItemWidget
	FString NameFunctionChangeLocation = "ChangeLocation";
	FString NameFunctionOpenPicture = "OpenPicture";
	TArray<FString> Path;

	TArray<FString> FoundFiles;
	TArray<FString> FoundDirectories;
	TArray<UFMItemWidget*> Items;

	void ScanDirectory(FString& CurrentDirectory);
	void SetCurrentLocation();
	void ClearItems();
	void RebuildItems();
	FString GetRootLocationFromGameInstance();
	void SetCurrentLocationOnGameInstance();
	void CreateItem(UMyFileManager* Parent, FString& Header, FString& NameFunctionDoubleClick, FSlateColor Color = FLinearColor::Blue);


	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void OpenPicture();

	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void ChangeLocation();

	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void AddDirectory();

	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	void OpenMenuAddDirectory();

	UFUNCTION(BlueprintCallable, Category = "My File Manager")
	FString SetNewDirectoryName();

};
