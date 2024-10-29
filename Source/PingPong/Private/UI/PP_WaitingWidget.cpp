// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/PP_WaitingWidget.h"

void UPP_WaitingWidget::HandleMatchStateChanged(const FName& MatchState)
{
    if (MatchState == FName(TEXT("InProgress")))
    {
        SetVisibility(ESlateVisibility::Collapsed);
    }
    else
    {
        SetVisibility(ESlateVisibility::Visible);
    }
}
