// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball/PP_Ball.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

APP_Ball::APP_Ball()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;
    SetReplicateMovement(true);

    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    RootComponent = SphereComponent;

    SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    SphereComponent->SetCollisionResponseToAllChannels(ECR_Block);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->InitialSpeed = 1000.f;
    ProjectileMovement->MaxSpeed = 1000.f;
    ProjectileMovement->Bounciness = 1.f;
    ProjectileMovement->SetIsReplicated(true);
}
void APP_Ball::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APP_Ball::BeginPlay()
{
    Super::BeginPlay();

    SphereComponent->OnComponentHit.AddDynamic(this, &APP_Ball::OnHitEvent);
}

void APP_Ball::OnHitEvent(
    UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    FVector HitNormal = Hit.Normal;
    FVector IncomingVelocity = ProjectileMovement->Velocity;

    FVector ReflectionVector = FMath::GetReflectionVector(IncomingVelocity, HitNormal);
    float RandomAngle = FMath::FRandRange(-10.f, 10.f);

    FQuat RandomRotation = FQuat(HitNormal, FMath::DegreesToRadians(RandomAngle));
    FVector NewDirection = RandomRotation.RotateVector(ReflectionVector);

    ProjectileMovement->Velocity = NewDirection.GetSafeNormal2D() * IncomingVelocity.Size();
    UE_LOG(LogTemp, Warning, TEXT("New Velocity: %s"), *ProjectileMovement->Velocity.ToString());
}