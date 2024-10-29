// Fill out your copyright notice in the Description page of Project Settings.

#include "PP_GameState.h"
#include "Net/UnrealNetwork.h"

void APP_GameState::OnRep_MatchState()
{
    Super::OnRep_MatchState();
    OnMatchStateChanged.Broadcast(MatchState);
}
