// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PP_PlayerController.h"
#include "Player/PP_Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void APP_PlayerController::BeginPlay()
{
    Super::BeginPlay();
    ULocalPlayer* LocalPlayer = GetLocalPlayer();

    if (!LocalPlayer) return;
    UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

    if (!Subsystem) return;
    Subsystem->AddMappingContext(InputMappingContext, 0);
}

void APP_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    if (EnhancedInputComponent)
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APP_PlayerController::Move);
    }
}

void APP_PlayerController::Move(const FInputActionValue& Value)
{
    APP_Pawn* PP_Pawn = GetPawn<APP_Pawn>();
    if (PP_Pawn)
    {
        PP_Pawn->Move(Value);
    }
}
