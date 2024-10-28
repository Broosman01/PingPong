// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PP_Pawn.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PINGPONG_API APP_Pawn : public APawn
{
    GENERATED_BODY()

public:
    APP_Pawn();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MoveSpeed = 600.f;

    UPROPERTY(EditDefaultsOnly)
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditDefaultsOnly)
    UInputAction* MoveAction;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void Move(const FInputActionValue& Value);
};
