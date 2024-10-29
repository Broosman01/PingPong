// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PP_GameMode.generated.h"

/**
 *
 */
UCLASS()
class PINGPONG_API APP_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	APP_GameMode(const FObjectInitializer& ObjectInitializer);

	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;

	bool IsValidPlayerStart(AActor* Start);
};
