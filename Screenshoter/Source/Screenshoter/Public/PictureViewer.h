// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "PictureViewer.generated.h"

class UButton;
class UTextBlock;
class UImage;
class UScrollBox;

/**
 * 
 */
UCLASS()
class SCREENSHOTER_API UPictureViewer : public UUserWidget
{
	GENERATED_BODY()
	
public:

	TSharedRef<SWidget> RebuildWidget();
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton * ButtonClose = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock * TextBlockButtonClose = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage * Image = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage * ImageBackground = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Picture Viewer")
	void SetImage(FString& Path);


private:

	FString NameTextBlockButtonClose = "X";
	const FVector2D BackgroundSize = FVector2D(1920, 1080);
	const FVector2D ButtonCloseSize = FVector2D(50, 50);
	UTexture2D* Texture = nullptr;

	UTexture2D* Victory_LoadTexture2D_FromFile(const FString& FullFilePath, EImageFormat ImageFormat, bool& IsValid, int32& Width, int32& Height);

	UFUNCTION(BlueprintCallable, Category = "Picture Viewer")
	void Hide();
		
};
