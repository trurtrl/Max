// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFileManager.h"
#include "Runtime/Core/Public/HAL/FileManager.h"

void UMyFileManager::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMyFileManager::ScanDirectory(FString& CurrentDirectory)
{
	FoundDirectories.Empty();
	FoundFiles.Empty();
	IFileManager& FileMgr = IFileManager::Get();
	if (!FileMgr.DirectoryExists(*CurrentDirectory))
	{
		UE_LOG(LogTemp, Warning, TEXT("Attention! Path is not exist - %s"), *CurrentDirectory)
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("CurrentDirectory:%s"), *CurrentDirectory)
		UE_LOG(LogTemp, Warning, TEXT("FoundDirectories.Max = %i"), FoundDirectories.Max())

	FString Path = CurrentDirectory + "*";
	FileMgr.FindFiles(FoundDirectories, *Path, false, true);
	FileMgr.FindFiles(FoundFiles, *Path, true, false);
}

void UMyFileManager::PrintList()
{
	UE_LOG(LogTemp, Warning, TEXT("Directories: ( Max = %i, Num = %i )"), FoundDirectories.Max(), FoundDirectories.Num())

	for (FString File : FoundDirectories)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *File)
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Files:"))

	for (FString File : FoundFiles)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *File)
	}
	UE_LOG(LogTemp, Warning, TEXT("Directories: ( Max = %i, Num = %i )"), FoundDirectories.Max(), FoundDirectories.Num())
}

int32 UMyFileManager::GetFoundDMax()
{
	return FoundDirectories.Max();
}
