// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PP_Gate.generated.h"

class UBoxComponent;

UCLASS()
class PINGPONG_API APP_Gate : public AActor
{
    GENERATED_BODY()

public:
    APP_Gate();

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UBoxComponent* CollisionBox;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 TeamIndex;
};
