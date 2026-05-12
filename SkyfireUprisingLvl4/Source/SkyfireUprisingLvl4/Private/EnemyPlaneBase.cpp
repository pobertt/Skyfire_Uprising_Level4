// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPlaneBase.h"

// Sets default values
AEnemyPlaneBase::AEnemyPlaneBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyPlaneBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPlaneBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyPlaneBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//Get rotate data
void AEnemyPlaneBase::CalculateChaseInput(FVector TargetLocation, float& Pitch, float& Yaw, float& Roll)
{
    //FVector ToTarget =(TargetLocation - GetActorLocation()).GetSafeNormal();
    FVector RelativePositionToPlayer = TargetLocation - GetActorLocation();//get relative location

    FVector ToTarget = RelativePositionToPlayer.GetSafeNormal();

    FVector LocalDir = GetActorTransform().InverseTransformVectorNoScale(ToTarget);

    Yaw = FMath::Clamp(LocalDir.Y, -1.f, 1.f);
    Pitch = FMath::Clamp(LocalDir.Z, -1.f, 1.f);
    Roll = FMath::Clamp(LocalDir.Y * 1.2f, -1.f, 1.f);
}
//get locate to player
void AEnemyPlaneBase::GetLocateToPlayer(const AActor* Player, FVector& WorldVectorToPlayer, FVector& LocalVectorToPlayer) {

    if (!Player) { 
        UE_LOG(LogTemp, Warning, TEXT("Player does not exist!!"));
        return; 
    }

    WorldVectorToPlayer = Player->GetActorLocation() - GetActorLocation();

    LocalVectorToPlayer = Player->GetActorTransform().InverseTransformVectorNoScale(WorldVectorToPlayer);
}
//Auto level


