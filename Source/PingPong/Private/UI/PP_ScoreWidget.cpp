// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PP_ScoreWidget.h"
#include "Components/TextBlock.h"

void UPP_ScoreWidget::UpdateScore(int32 Team1Score, int32 Team2Score)
{
    if (Team1ScoreText)
    {
        Team1ScoreText->SetText(FText::AsNumber(Team1Score));
    }

    if (Team2ScoreText)
    {
        Team2ScoreText->SetText(FText::AsNumber(Team2Score));
    }
}

void UPP_ScoreWidget::HandleMatchStateChanged(const FName& MatchState)
{
    if (MatchState != FName(TEXT("InProgress")))
    {
        SetVisibility(ESlateVisibility::Collapsed);
    }
    else
    {
        SetVisibility(ESlateVisibility::Visible);
    }
}