// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_Level4.generated.h"

/**
 * 
 */
UCLASS()
class SKYFIREUPRISINGLVL4_API AGameMode_Level4 : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameMode_Level4();
	virtual ~AGameMode_Level4() = default;

	/* Return the number of the test count in the game */
	UFUNCTION(BlueprintPure, Category = "Test")
	virtual int32 GetTestCount() const;

	UFUNCTION(BlueprintCallable, Category = "Test")
	virtual void SetTestCount(int32 newTestCount);
};
