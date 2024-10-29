// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PP_Ball.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class PINGPONG_API APP_Ball : public AActor
{
    GENERATED_BODY()

public:
    APP_Ball();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnHitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
        const FHitResult& Hit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    USphereComponent* SphereComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MoveSpeed = 250;

    FVector CurrentVelocity;

public:
    virtual void Tick(float DeltaTime) override;
};
