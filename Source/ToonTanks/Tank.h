// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"

#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
    ATank();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
protected:
    virtual void BeginPlay() override;

public:	
    virtual void Tick(float DeltaTime) override;

    void HandleDestruction();

    APlayerController* GetTankPlayerController() const { return TankPlayerController; }
    
private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class USpringArmComponent* SpringArm;
    UPROPERTY(VisibleAnywhere,Category = "Components")
    class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Speed = 500.f;
    UPROPERTY(EditAnywhere, Category = "Movement")
    float TurnRate = 45.f;

    void Move(float Value);
    void Turn(float Value);

    APlayerController* TankPlayerController;
};