// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_Level4.h"
#include "GameState_Level4.h"

AGameMode_Level4::AGameMode_Level4()
{
	GameStateClass = AGameState_Level4::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Content_Level4/PlayerCharacter_Level4/BP_FPSCharacter_Level4"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

int32 AGameMode_Level4::GetTestCount() const
{
	return int32();
}

void AGameMode_Level4::SetTestCount(int32 newTestCount)
{
}

