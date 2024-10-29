// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/PP_HUD.h"
#include "PP_GameState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PP_WaitingWidget.h"
#include "UI/PP_ScoreWidget.h"

void APP_HUD::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    APP_GameState* GameState = World->GetGameState<APP_GameState>();
    if (!GameState) return;

    if (WaitingWidgetClass)
    {
        UPP_WaitingWidget* WaitingWidget = CreateWidget<UPP_WaitingWidget>(World, WaitingWidgetClass);
        if (WaitingWidget)
        {
            GameState->OnMatchStateChanged.AddUObject(WaitingWidget, &UPP_WaitingWidget::HandleMatchStateChanged);
            WaitingWidget->AddToViewport();
            GameState->OnRep_MatchState();
        }
    }

    if (ScoreWidgetClass)
    {
        UPP_ScoreWidget* ScoreWidget = CreateWidget<UPP_ScoreWidget>(World, ScoreWidgetClass);
        if (ScoreWidget)
        {
            GameState->OnScoreChanged.AddUObject(ScoreWidget, &UPP_ScoreWidget::UpdateScore);
            GameState->OnMatchStateChanged.AddUObject(ScoreWidget, &UPP_ScoreWidget::HandleMatchStateChanged);
            ScoreWidget->AddToViewport();
            GameState->OnRep_MatchState();
        }
    }
    GameState->OnRep_MatchState();
}