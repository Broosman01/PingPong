// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/PP_HUD.h"
#include "PP_GameState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PP_WaitingWidget.h"

void APP_HUD::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    APP_GameState* GameState = World->GetGameState<APP_GameState>();
    if (!GameState) return;

    if (!WaitingWidgetClass) return;
    UPP_WaitingWidget* WaitingWidget = CreateWidget<UPP_WaitingWidget>(World, WaitingWidgetClass);

    if (!WaitingWidget) return;
    GameState->OnMatchStateChanged.AddUObject(WaitingWidget, &UPP_WaitingWidget::HandleMatchStateChanged);
    GameState->OnRep_MatchState();
}