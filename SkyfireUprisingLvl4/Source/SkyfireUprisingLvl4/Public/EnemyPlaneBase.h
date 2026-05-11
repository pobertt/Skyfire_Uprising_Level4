// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPlaneBase.generated.h"

UCLASS()
class SKYFIREUPRISINGLVL4_API AEnemyPlaneBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPlaneBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Flight|AI")
	void CalculateChaseInput(FVector TargetLocation, float& Pitch, float& Yaw, float& Roll);//caculate pitch yaw and roll ; position to player(World Axis and Local Axis)

	UFUNCTION(BlueprintCallable, Category = "Flight|AI")
	void GetLocateToPlayer(const AActor* Player, FVector& WorldVectorToPlayer, FVector& LocalVectorToPlayer);//get distance to player
};
