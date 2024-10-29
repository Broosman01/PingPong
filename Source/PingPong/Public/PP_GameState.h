// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PP_GameState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChanged, const FName&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnScoreChanged, int32, int32);

UCLASS()
class PINGPONG_API APP_GameState : public AGameState
{
    GENERATED_BODY()

public:
    virtual void OnRep_MatchState() override;

    FOnMatchStateChanged OnMatchStateChanged;
    FOnScoreChanged OnScoreChanged;

    void IncreaseScore(int32 TeamIndex);

    int32 GetFirstTeamScore() const { return FirstTeamScore; }
    int32 GetSecondTeamScore() const { return SecondTeamScore; }

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(ReplicatedUsing = OnRep_FirstTeamScore)
    int32 FirstTeamScore = 0;

    UPROPERTY(ReplicatedUsing = OnRep_SecondTeamScore)
    int32 SecondTeamScore = 0;

    UFUNCTION()
    void OnRep_FirstTeamScore();

    UFUNCTION()
    void OnRep_SecondTeamScore();
};
