// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_ScoreWidget.generated.h"

class UTextBlock;

UCLASS()
class PINGPONG_API UPP_ScoreWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void UpdateScore(int32 Team1Score, int32 Team2Score);

    UFUNCTION()
    void HandleMatchStateChanged(const FName& MatchState);

protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UTextBlock* Team1ScoreText;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UTextBlock* Team2ScoreText;
};
