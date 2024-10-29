// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PP_GameState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChanged, const FName&);

UCLASS()
class PINGPONG_API APP_GameState : public AGameState
{
    GENERATED_BODY()

public:
    virtual void OnRep_MatchState() override;

    FOnMatchStateChanged OnMatchStateChanged;
};
