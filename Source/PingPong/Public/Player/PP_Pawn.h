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

    virtual void Tick(float DeltaTime) override;

    void Move(const FInputActionValue& Value);

protected:
    virtual void BeginPlay() override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UStaticMeshComponent* WallMesh;

    UPROPERTY(EditAnywhere, Category = "Materials")
    UMaterialInterface* AllyMaterial;

    UPROPERTY(EditAnywhere, Category = "Materials")
    UMaterialInterface* EnemyMaterial;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MoveSpeed = 600.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MoveBound = 450.f;

    FVector InitialLocation;

    UFUNCTION(Server, Reliable)
    void ServerMove(FVector NewLocation);

    void SetPawnColor(bool IsLocal);

private:
    void DeterminePawnColor();
};
