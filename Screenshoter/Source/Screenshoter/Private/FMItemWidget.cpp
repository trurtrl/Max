// Fill out your copyright notice in the Description page of Project Settings.

#include "FMItemWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/Border.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/HorizontalBox.h"
#include "Runtime/UMG/Public/Components/CheckBox.h"

#include "MyFileManager.h"

UFMItemWidget::UFMItemWidget(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
	if (!WidgetTree) WidgetTree = NewObject <UWidgetTree> (UWidgetTree::StaticClass());

}



void UFMItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind delegates are here
	//	Border->OnMouseDoubleClickEvent.BindUFunction(this, "GoToDirectory");
	Border->OnMouseButtonDownEvent.BindUFunction(this, FName("SetToFile"));
//	Border->SetBrushColor(FLinearColor::Gray);
}

TSharedRef<SWidget> UFMItemWidget::RebuildWidget()
{
	RootWidgetHorizBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("Root Widget"));
	WidgetTree->RootWidget = RootWidgetHorizBox;
	

	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	if (RootWidgetHorizBox)
	{
		CheckBox = NewObject<UCheckBox>(this, UCheckBox::StaticClass());

		TextBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());

		//TextBlock->SetColorAndOpacity(FLinearColor::Green);

		Border = NewObject<UBorder>(this, UBorder::StaticClass());
		Border->AddChild(TextBlock);

		RootWidgetHorizBox->AddChild(CheckBox);
		RootWidgetHorizBox->AddChild(Border);

	}

	return Widget;
}

void UFMItemWidget::PrintTest()
{

	UE_LOG(LogTemp, Warning, TEXT("FM Item is clicked"))
}

void UFMItemWidget::SetText(FString& ItemText)
{
	TextBlock->SetText(FText::FromString(ItemText));
}

void UFMItemWidget::SetToFile()
{
	FString ToFile = TextBlock->Text.ToString();
	Parent->SetToFile(ToFile);
}

void UFMItemWidget::SetParent(UMyFileManager* NewParent)
{
	Parent = NewParent;
}
