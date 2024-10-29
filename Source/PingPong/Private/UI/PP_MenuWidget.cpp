// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/PP_MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UPP_MenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (CreateLobbyButton)
    {
        CreateLobbyButton->OnClicked.AddDynamic(this, &UPP_MenuWidget::CreateLobby);
    }
    if (FindLobbyButton)
    {
        FindLobbyButton->OnClicked.AddDynamic(this, &UPP_MenuWidget::FindLobby);
    }
    if (ExitGameButton)
    {
        ExitGameButton->OnClicked.AddDynamic(this, &UPP_MenuWidget::ExitGame);
    }
}

void UPP_MenuWidget::CreateLobby()
{
    UWorld* World = GetWorld();
    if (!World) return;

    FString LevelPath = "/Game/Maps/BaseLevel?listen";
    World->ServerTravel(LevelPath);
}

void UPP_MenuWidget::FindLobby()
{
    FString IPAdress = FString("127.0.0.1");
    UGameplayStatics::OpenLevel(this, *IPAdress);
}

void UPP_MenuWidget::ExitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
