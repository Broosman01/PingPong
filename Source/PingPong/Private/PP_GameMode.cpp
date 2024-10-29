// Fill out your copyright notice in the Description page of Project Settings.

#include "PP_GameMode.h"
#include "Player/PP_Pawn.h"
#include "Player/PP_PlayerController.h"
#include "Player/PP_PlayerState.h"
#include "PP_GameState.h"
#include "HUD/PP_HUD.h"
#include "GameFramework/PlayerStart.h"
#include "EngineUtils.h"

APP_GameMode::APP_GameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    DefaultPawnClass = APP_Pawn::StaticClass();
    PlayerControllerClass = APP_PlayerController::StaticClass();
    PlayerStateClass = APP_PlayerState::StaticClass();
    GameStateClass = APP_GameState::StaticClass();
    HUDClass = APP_HUD::StaticClass();
}

AActor* APP_GameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
    UWorld* World = GetWorld();
    if (World)
    {
        for (TActorIterator<APlayerStart> It(World); It; ++It)
        {
            const FName IncomingPlayerStartTag = FName(*IncomingName);
            APlayerStart* Start = *It;
            if (IsValidPlayerStart(Start))
            {
                return Start;
            }
        }
    }

    return Super::FindPlayerStart_Implementation(Player, IncomingName);
}

bool APP_GameMode::IsValidPlayerStart(AActor* Start)
{
    for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
    {
        APlayerController* PlayerActor = Iterator->Get();
        if (PlayerActor && PlayerActor->GetPawn() && PlayerActor->GetPawn()->GetActorLocation() == Start->GetActorLocation())
        {
            return false;
        }
    }
    return true;
}
