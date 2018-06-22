// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyFileManager.generated.h"

class IFileManager;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API UMyFileManager : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	void ScanDirectory(FString& CurrentDirectory);
	void PrintList();
	int32 GetFoundDMax();



private:


	TArray<FString> FoundFiles;
	TArray<FString> FoundDirectories;



};
