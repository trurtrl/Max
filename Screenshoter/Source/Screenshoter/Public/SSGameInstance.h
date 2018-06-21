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
	
	USSGameInstance();

	void Temp();

//	UPROPERTY(EditAnywhere, Category = "UI")
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainUIClass;

//	UPROPERTY(VisibleAnywhere)
	UMainMenu* MainUI = nullptr;

private:

	//	Class to initialize BP UserWidget
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")

	

};
