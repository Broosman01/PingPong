// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PP_GameMode.generated.h"

class APP_Ball;

UCLASS()
class PINGPONG_API APP_GameMode : public AGameMode
{
    GENERATED_BODY()

public:
    APP_GameMode(const FObjectInitializer& ObjectInitializer);

    virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;
    virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

    bool IsValidPlayerStart(AActor* Start);

protected:
    virtual bool ReadyToStartMatch_Implementation() override;
    virtual void HandleMatchHasStarted() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<APP_Ball> BallClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FVector BallSpawnLocation;
};
