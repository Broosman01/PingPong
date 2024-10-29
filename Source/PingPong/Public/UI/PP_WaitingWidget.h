// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_WaitingWidget.generated.h"

UCLASS()
class PINGPONG_API UPP_WaitingWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void HandleMatchStateChanged(const FName& MatchState);
};
