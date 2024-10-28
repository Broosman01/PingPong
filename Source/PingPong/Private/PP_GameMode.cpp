// Fill out your copyright notice in the Description page of Project Settings.

#include "PP_GameMode.h"
#include "Player/PP_Pawn.h"
#include "Player/PP_PlayerController.h"
#include "Player/PP_PlayerState.h"
#include "PP_GameState.h"
#include "HUD/PP_HUD.h"

APP_GameMode::APP_GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    DefaultPawnClass = APP_Pawn::StaticClass();
    PlayerControllerClass = APP_PlayerController::StaticClass();
    PlayerStateClass = APP_PlayerState::StaticClass();
    GameStateClass = APP_GameState::StaticClass();
    HUDClass = APP_HUD::StaticClass();
}