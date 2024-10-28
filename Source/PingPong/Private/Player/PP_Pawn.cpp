// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PP_Pawn.h"

// Sets default values
APP_Pawn::APP_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APP_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APP_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APP_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

