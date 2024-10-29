// Fill out your copyright notice in the Description page of Project Settings.

#include "PP_GameMode.h"
#include "Player/PP_Pawn.h"
#include "Player/PP_PlayerController.h"
#include "Player/PP_PlayerState.h"
#include "PP_GameState.h"
#include "HUD/PP_HUD.h"
#include "GameFramework/PlayerStart.h"
#include "EngineUtils.h"
#include "Ball/PP_Ball.h"

APP_GameMode::APP_GameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    DefaultPawnClass = APP_Pawn::StaticClass();
    PlayerControllerClass = APP_PlayerController::StaticClass();
    PlayerStateClass = APP_PlayerState::StaticClass();
    GameStateClass = APP_GameState::StaticClass();
    HUDClass = APP_HUD::StaticClass();

    bStartPlayersAsSpectators = 0;

    bDelayedStart = true;
}

AActor* APP_GameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
    UWorld* World = GetWorld();
    if (World)
    {
        for (TActorIterator<APlayerStart> It(World); It; ++It)
        {
            APlayerStart* Start = *It;
            if (IsValidPlayerStart(Start))
            {
                return Start;
            }
        }
    }

    return Super::FindPlayerStart_Implementation(Player, IncomingName);
}

void APP_GameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
    if (!bStartPlayersAsSpectators && !MustSpectate(NewPlayer))
    {
        RestartPlayer(NewPlayer);
    }

    if (!ReadyToStartMatch())
    {
        NewPlayer->DisableInput(NewPlayer);
    }
    else
    {
        for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
        {
            APlayerController* PlayerController = Iterator->Get();
            if (PlayerController)
            {
                PlayerController->EnableInput(PlayerController);
            }
        }
    }
}

bool APP_GameMode::ReadyToStartMatch_Implementation()
{
    return GetNumPlayers() == 2 || Super::ReadyToStartMatch_Implementation();
}

void APP_GameMode::HandleMatchHasStarted()
{
    Super::HandleMatchHasStarted();

    FRotator BallSpawnRotation = FRotator::ZeroRotator;
    if (BallClass)
    {
        APP_Ball* SpawnedBall = GetWorld()->SpawnActor<APP_Ball>(BallClass, BallSpawnLocation, BallSpawnRotation);
    }
}

bool APP_GameMode::IsValidPlayerStart(AActor* Start)
{
    const float Tolerance = 1.0f;

    for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
    {
        APlayerController* PlayerController = Iterator->Get();
        if (PlayerController && PlayerController->GetPawn())
        {
            APawn* PlayerPawn = PlayerController->GetPawn();
            if (FVector::Dist(PlayerPawn->GetActorLocation(), Start->GetActorLocation()) <= Tolerance)
            {
                return false;
            }
        }
    }
    return true;
}
