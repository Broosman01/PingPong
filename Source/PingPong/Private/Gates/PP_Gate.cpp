// Fill out your copyright notice in the Description page of Project Settings.

#include "Gates/PP_Gate.h"
#include "Components/BoxComponent.h"
#include "PP_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Ball/PP_Ball.h"
#include "PP_GameState.h"

APP_Gate::APP_Gate()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;

    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    CollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APP_Gate::OnOverlapBegin);
}

void APP_Gate::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    APP_Ball* Ball = Cast<APP_Ball>(OtherActor);
    if (!Ball) return;

    UWorld* World = GetWorld();
    if (!Ball) return;

    APP_GameState* GameState = World->GetGameState<APP_GameState>();
    GameState->IncreaseScore(TeamIndex);
}