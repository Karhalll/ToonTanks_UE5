// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"

#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
    RootComponent = CapsuleComp;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    BaseMesh->SetupAttachment(CapsuleComp);

    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
    TurretMesh->SetupAttachment(BaseMesh);

    ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
    ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	const FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	const FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretMesh->SetWorldRotation(LookAtRotation);
}

void ABasePawn::Fire()
{
	DrawDebugSphere(
		GetWorld(),
		ProjectileSpawnPoint->GetComponentLocation(),
		40.f,
		8,
		FColor::Red,
		false,
		2.f
		);
}
