// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsMenu.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"

/*USettingsMenu::USettingsMenu(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
	if (ButtonCancel)
	{
		ButtonCancel->OnReleased.AddDynamic(this, &USettingsMenu::Hide);
	};
	UE_LOG(LogTemp, Warning, TEXT("Settings constructor"))
}*/


void USettingsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonCancel && !(ButtonCancel->OnReleased.IsBound()))
	{
		ButtonCancel->OnReleased.AddDynamic(this, &USettingsMenu::Hide);
	};

	if (TextBlockButtonOk) TextBlockButtonOk->SetText(FText::FromString(NameTextBlockButtonOk));
	if (TextBlockButtonCancel) TextBlockButtonCancel->SetText(FText::FromString(NameTextBlockButtonCancel));
}

void USettingsMenu::SetHeader(FString& Header)
{
	if (TextBlockHeader) TextBlockHeader->SetText(FText::FromString(Header));
}

void USettingsMenu::Show()
{
	AddToViewport();
}

void USettingsMenu::Hide()
{
	RemoveFromViewport();
}
