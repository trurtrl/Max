// Fill out your copyright notice in the Description page of Project Settings.

#include "PictureViewer.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/UMG/Public/Components/ScrollBox.h"

#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "SSGameInstance.h"


TSharedRef<SWidget> UPictureViewer::RebuildWidget()
{
	//	Define Root Widget if there is no one
	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	if (!RootWidget)
	{
		if (!WidgetTree) WidgetTree = NewObject <UWidgetTree>(UWidgetTree::StaticClass());
		RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("Root Widget"));

		UCanvasPanelSlot* RootWidgetSlot = Cast<UCanvasPanelSlot>(RootWidget->Slot);

		if (RootWidgetSlot)
		{
			RootWidgetSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
			RootWidgetSlot->SetOffsets(FMargin(0.f, 0.f));
		}
		WidgetTree->RootWidget = RootWidget;
	}

	// Super::RebuildWidget MUST be after defined Root Widget
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	//	My Widgets
	if (!ButtonClose)	ButtonClose = NewObject<UButton>(this, UButton::StaticClass());
	if (!TextBlockButtonClose)	TextBlockButtonClose = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
	ButtonClose->AddChild(TextBlockButtonClose);

	if (!Image) Image = NewObject<UImage>(this, UImage::StaticClass());
	if (!ImageBackground) ImageBackground = NewObject<UImage>(this, UImage::StaticClass());


	RootWidget->AddChild(ImageBackground);
	RootWidget->AddChild(Image);
	RootWidget->AddChild(ButtonClose);

	return Widget;
}

void UPictureViewer::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind delegates are here

	if (ButtonClose && !(ButtonClose->OnReleased.IsBound()))
	{
		ButtonClose->OnReleased.AddDynamic(this, &UPictureViewer::Hide);
		ButtonClose->SetBackgroundColor(FLinearColor::Red);
	};
	if (TextBlockButtonClose)
	{
		TextBlockButtonClose->SetText(FText::FromString(NameTextBlockButtonClose));

		//TextBlockButtonClose->SetFont(FSlateFontInfo(this, 24));
	}

	Cast<UCanvasPanelSlot>(ButtonClose->Slot)->SetSize(ButtonCloseSize);

	ImageBackground->SetColorAndOpacity(FLinearColor::Gray);
	Cast<UCanvasPanelSlot>(ImageBackground->Slot)->SetSize(BackgroundSize);

}

void UPictureViewer::SetImage(FString& Path)
{
	bool bResultValid = false;
	int32 PicWidth = 0;
	int32 PicHeight = 0;
	Texture = Victory_LoadTexture2D_FromFile(Path, EImageFormat::PNG, bResultValid, PicWidth, PicHeight);
	if (bResultValid && Image)
	{
		UE_LOG(LogTemp, Warning, TEXT("Image is ready to set"))
		Image->SetBrushFromTexture(Texture);
		//	to get Viewport Resolution anywhere include "Engine.h" instead of "EngineMinimal.h" in ProjectName.h
		//const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

		/*//	Another way to get Viewport Size
		FIntPoint SizeXY;
		USSGameInstance* SSGI = Cast<USSGameInstance>(GetWorld()->GetGameInstance());
		if (SSGI)
		{
			SizeXY = SSGI->GetEngine()->GameViewport->Viewport->GetSizeXY();

		}
		else
		{
			SizeXY = FIntPoint();
		}
		FVector2D VPSize = FVector2D(SizeXY.X, SizeXY.Y);*/

		Cast<UCanvasPanelSlot>(Image->Slot)->SetSize(FVector2D(PicWidth, PicHeight));	// TODO check pictures sizes on Android. 

	}
}

void UPictureViewer::Hide()
{
	RemoveFromViewport();
}

UTexture2D* UPictureViewer::Victory_LoadTexture2D_FromFile(const FString& FullFilePath, EImageFormat ImageFormat, bool& IsValid, int32& Width, int32& Height)
{
	IsValid = false;
	UTexture2D* LoadedT2D = NULL;

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);

	//Load From File
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData, *FullFilePath))
	{
		return NULL;
	}


	//Create T2D!
	if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	{
		const TArray<uint8>* UncompressedBGRA = NULL;
		if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
		{
			LoadedT2D = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);

			//Valid?
			if (!LoadedT2D)
			{
				return NULL;
			}

			//Out!
			Width = ImageWrapper->GetWidth();
			Height = ImageWrapper->GetHeight();

			//Copy!
			void* TextureData = LoadedT2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(TextureData, UncompressedBGRA->GetData(), UncompressedBGRA->Num());
			LoadedT2D->PlatformData->Mips[0].BulkData.Unlock();

			//Update!
			LoadedT2D->UpdateResource();
		}
	}

	// Success!
	IsValid = true;
	return LoadedT2D;
}
