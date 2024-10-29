// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PP_Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerState.h"

APP_Pawn::APP_Pawn()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    WallMesh->SetupAttachment(RootComponent);
    WallMesh->SetIsReplicated(true);
}

void APP_Pawn::BeginPlay()
{
    Super::BeginPlay();

    InitialLocation = GetActorLocation();
    DeterminePawnColor();
}

void APP_Pawn::DeterminePawnColor()
{
    SetPawnColor(IsLocallyControlled());
}

void APP_Pawn::SetPawnColor(bool IsLocal)
{
    if (IsLocal && AllyMaterial)
    {
        WallMesh->SetMaterial(0, AllyMaterial);
    }
    else if (EnemyMaterial)
    {
        WallMesh->SetMaterial(0, EnemyMaterial);
    }
}

void APP_Pawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void APP_Pawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APP_Pawn::Move(const FInputActionValue& Value)
{
    FVector2D MoveVector = Value.Get<FVector2D>();
    FVector Right = GetActorRightVector();

    FVector NewLoc = WallMesh->GetComponentLocation() + (Right * MoveVector.X) * MoveSpeed * GetWorld()->GetDeltaSeconds();
    float ClampedY = FMath::Clamp(NewLoc.Y, InitialLocation.Y - MoveBound, InitialLocation.Y + MoveBound);

    NewLoc.Y = ClampedY;
    WallMesh->SetWorldLocation(NewLoc);

    if (HasAuthority()) return;
    ServerMove(NewLoc);
}

void APP_Pawn::ServerMove_Implementation(FVector NewLocation)
{
    WallMesh->SetWorldLocation(NewLocation);
}
