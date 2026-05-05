// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FPSCharacter_Level4.generated.h"

// Forward-declare Enhanced Input UObject types so UHT can parse the UPROPERTYs
class UInputMappingContext;
class UInputAction;

UCLASS()
class SKYFIREUPRISINGLVL4_API AFPSCharacter_Level4 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter_Level4();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Defining Inputs:

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputAction* PrimaryInput;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputAction* CrouchAction;

	// Functions for inputs:

	void Move(const FInputActionValue& InputValue);

	void Look(const FInputActionValue& InputValue);

	void Jump();

	void PrimaryAction();

	void Sprint(const FInputActionValue& InputValue);

	void InputCrouch();

};
