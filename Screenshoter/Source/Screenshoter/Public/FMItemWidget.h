// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FMItemWidget.generated.h"

class UButton;
class UBorder;
class UTextBlock;
class UCheckBox;
class UHorizontalBox;

class UMyFileManager;


/**
 *	File Manager Item Widget represents view of File or Catalog
 */
UCLASS()
class SCREENSHOTER_API UFMItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFMItemWidget(const FObjectInitializer & ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual TSharedRef<SWidget> RebuildWidget();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox *RootWidgetHorizBox = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCheckBox* CheckBox = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock * TextBlock = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton * Button = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UBorder* Border = nullptr;


	UFUNCTION(BlueprintCallable, Category = "FM Item")
	void PrintTest();

	UFUNCTION(BlueprintCallable, Category = "FM Item")
	void SetText(FString& ItemText);


	UFUNCTION(BlueprintCallable, Category = "FM Item")
	void SetParent(UMyFileManager* NewParent);




private:
	
	UMyFileManager* Parent;

	UFUNCTION(BlueprintCallable, Category = "FM Item")
	void SetToFile();

};
