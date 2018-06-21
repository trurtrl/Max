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

	FString NameTextBlockFolder = "Set a folder's name :";
	FString NameTextBlockButtonOk = "OK";
	FString NameTextBlockButtonCancel = "Cancel";

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockFolder = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* TextBoxFolder = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonOk = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonOk = nullptr;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonCancel = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockButtonCancel = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void Show();

	UFUNCTION(BlueprintCallable, Category = "Screenshot")
	void Hide();

};
