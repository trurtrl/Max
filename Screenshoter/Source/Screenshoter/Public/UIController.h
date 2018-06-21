// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UIController.generated.h"

class UMainMenu;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API AUIController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UMainMenu* WidgetMenu;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetMenu(UMainMenu* MenuToSet);

private:

	virtual void BeginPlay() override;

//	UScreenshotMenu* ScreenshotMenu;


	

};
