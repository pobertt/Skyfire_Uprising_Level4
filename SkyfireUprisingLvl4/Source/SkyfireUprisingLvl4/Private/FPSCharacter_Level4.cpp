// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter_Level4.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "AC_Level4.h"

// Sets default values
AFPSCharacter_Level4::AFPSCharacter_Level4()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter_Level4::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello from C++! test number 5"));
	
}

// Called every frame
void AFPSCharacter_Level4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter_Level4::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Add Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	// Bind Actions (Only one 'if' needed here)
	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSCharacter_Level4::Move);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AFPSCharacter_Level4::Jump);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSCharacter_Level4::Look);
		EnhancedInput->BindAction(PrimaryInput, ETriggerEvent::Triggered, this, &AFPSCharacter_Level4::PrimaryAction);
		EnhancedInput->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AFPSCharacter_Level4::Sprint);
		EnhancedInput->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &AFPSCharacter_Level4::InputCrouch);
	}
}

void AFPSCharacter_Level4::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		//Get forward direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		//If pressing W want to move in this direction:
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		//If pressing D want to move in this direction:
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Add movement input
		/*
			Gets forward facing direction and then right facing direction
			Then moving depending on input
			(W or S = forward or backwards)
			(A or D = Left or Right)
		*/

		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void AFPSCharacter_Level4::Look(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		AddControllerYawInput(-InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void AFPSCharacter_Level4::Jump()
{
	ACharacter::Jump();
}

void AFPSCharacter_Level4::PrimaryAction()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("PrimaryAction"));
}

void AFPSCharacter_Level4::Sprint(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Sprint"));

	//bool bIsSprinting = InputValue.Get<bool>();
	//GetCharacterMovement()->MaxWalkSpeed = bIsSprinting ? 1200.f : 500.f;
}


void AFPSCharacter_Level4::InputCrouch()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Crouch"));
	ACharacter::Crouch();

}

