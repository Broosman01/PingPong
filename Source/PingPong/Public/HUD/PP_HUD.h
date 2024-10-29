// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PP_HUD.generated.h"

class UPP_WaitingWidget;
class UPP_ScoreWidget;

UCLASS()
class PINGPONG_API APP_HUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UPP_WaitingWidget> WaitingWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UPP_ScoreWidget> ScoreWidgetClass;
};
