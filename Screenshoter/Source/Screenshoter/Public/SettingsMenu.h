// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsMenu.generated.h"

class UButton;
class UTextBlock;
class UEditableTextBox;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API USettingsMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockHeader = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* TextBox = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonOk = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonOk = nullptr;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonCancel = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonCancel = nullptr;


	UFUNCTION(BlueprintCallable, Category = "Settings Menu")
	void SetHeader(FString& Header);

	UFUNCTION(BlueprintCallable, Category = "Settings Menu")
	void Show();

	UFUNCTION(BlueprintCallable, Category = "Settings Menu")
	void Hide();

private:

	FString NameTextBlockButtonOk = "OK";
	FString NameTextBlockButtonCancel = "Cancel";

};
