// Fill out your copyright notice in the Description page of Project Settings.

#include "PP_GameState.h"
#include "Net/UnrealNetwork.h"

void APP_GameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APP_GameState, FirstTeamScore);
    DOREPLIFETIME(APP_GameState, SecondTeamScore);
}

void APP_GameState::OnRep_FirstTeamScore()
{
    OnScoreChanged.Broadcast(FirstTeamScore, SecondTeamScore);
}

void APP_GameState::OnRep_SecondTeamScore()
{
    OnScoreChanged.Broadcast(FirstTeamScore, SecondTeamScore);
}

void APP_GameState::OnRep_MatchState()
{
    Super::OnRep_MatchState();
    OnMatchStateChanged.Broadcast(MatchState);
}

void APP_GameState::IncreaseScore(int32 TeamIndex)
{
    if (TeamIndex == 1)
    {
        FirstTeamScore++;
        OnRep_FirstTeamScore();
    }
    else if (TeamIndex == 2)
    {
        SecondTeamScore++;
        OnRep_SecondTeamScore();
    }
}
