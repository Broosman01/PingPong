// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PP_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PINGPONG_API APP_PlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

protected:
    virtual void SetupInputComponent() override;

    UPROPERTY(EditDefaultsOnly)
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditDefaultsOnly)
    UInputAction* MoveAction;

private:
    void Move(const FInputActionValue& Value);
};
