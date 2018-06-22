// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

//#include "Runtime/UMG/Public/Components/ComboBoxString.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/VerticalBox.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (TextBlockButtonScreenshot)	TextBlockButtonScreenshot->SetText(FText::FromString(NameButtonSS));
	if (TextBlockButtonMenu)	TextBlockButtonMenu->SetText(FText::FromString(NameMenu));
	if (TextBlockButtonSettings)	TextBlockButtonSettings->SetText(FText::FromString(NameMenuOptions));
	if (TextBlockButtonFileManager)	TextBlockButtonFileManager->SetText(FText::FromString(NameMenuFilemanager));
	if (TextBlockButtonMenuSendEmail)	TextBlockButtonMenuSendEmail->SetText(FText::FromString(NameMenuSendEmail));

	MainUIShow();
	MenuHide();

	if (ButtonMenu && !(ButtonMenu->OnPressed.IsBound()) ) 	ButtonMenu->OnPressed.AddDynamic(this, &UMainMenu::MenuShow);
//	if (ButtonMenuFileManager && !(ButtonMenuFileManager->OnReleased.IsBound()) )	ButtonMenuFileManager->OnReleased.AddDynamic(this, &UMainMenu::PrintTest);

	/*Menu->AddOption(MenuOptions);
	Menu->AddOption(MenuFilemanager);
	Menu->OnSelectionChanged*/
}

void UMainMenu::MainUIShow()
{
	ButtonMenu->SetVisibility(ESlateVisibility::Visible);
	ButtonScreenshot->SetVisibility(ESlateVisibility::Visible);
}
void UMainMenu::MainUIHide()
{
	ButtonMenu->SetVisibility(ESlateVisibility::Hidden);
	ButtonScreenshot->SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenu::MenuShow()
{
	VerticalBoxMenu->SetVisibility(ESlateVisibility::Visible);
}
void UMainMenu::MenuHide()
{
	VerticalBoxMenu->SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenu::PrintTest()
{
	MenuHide();
	UE_LOG(LogTemp, Warning, TEXT("Menu is hidden"))
}
