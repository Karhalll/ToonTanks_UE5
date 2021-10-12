// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	BaseMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mash"));
	RootComponent = BaseMash;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}