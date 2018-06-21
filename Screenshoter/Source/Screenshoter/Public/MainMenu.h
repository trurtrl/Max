// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

//class UComboBoxString;
class UButton;
class UTextBlock;
class UVerticalBox;

/**
 * 
 */
UCLASS()
class UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	FString NameButtonSS = "SS";
	FString NameMenu = "Menu";
	FString NameMenuOptions = "Options";
	FString NameMenuFilemanager = "File Manager";
	FString NameMenuSendEmail = "Send E-Mail";

	virtual void NativeConstruct() override;


	/*UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UComboBoxString* Menu = nullptr;*/

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonMenu = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonMenu = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* VerticalBoxMenu = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonMenuSettings = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonSettings = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonMenuFileManager = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonFileManager = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonMenuSendEmail = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonMenuSendEmail = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonScreenshot = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonScreenshot = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void MainUIShow();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void MainUIHide();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void MenuShow();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void MenuHide();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void PrintTest();

};
