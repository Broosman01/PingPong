// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PP_Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APP_Pawn::APP_Pawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APP_Pawn::BeginPlay()
{
    Super::BeginPlay();
    APlayerController* PC = Cast<APlayerController>(GetController());
    
    if (!PC) return;
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

    if (!Subsystem) return;
    Subsystem->AddMappingContext(InputMappingContext, 0);
}

void APP_Pawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APP_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (EnhancedInputComponent)
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APP_Pawn::Move);
    }
}

void APP_Pawn::Move(const FInputActionValue& Value)
{
    FVector2D MoveVector = Value.Get<FVector2D>();
    FVector Right = GetActorRightVector();

    FVector NewLoc = GetActorLocation() + (Right * MoveVector.X) * MoveSpeed * GetWorld()->GetDeltaSeconds();
    SetActorLocation(NewLoc);
}
