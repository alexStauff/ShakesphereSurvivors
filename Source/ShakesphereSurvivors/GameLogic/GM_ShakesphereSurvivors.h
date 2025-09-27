// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../PlayerCharacters/SurvivorBase.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GM_ShakesphereSurvivors.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API AGM_ShakesphereSurvivors : public AGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int currentLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int currentXP = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int XPToNextLevel = 8;

protected:
	virtual void BeginPlay();

	UFUNCTION()
	void grantXP(float xpValue);

	UFUNCTION()
	void levelUp();

	UPROPERTY(BlueprintReadOnly)
	int currentAct = 1;
	UPROPERTY(BlueprintReadOnly)
	int currentActProgress = 0;

	UPROPERTY(BlueprintReadOnly)
	float enemySpawnTimer = 5.0f;

	UPROPERTY()
	float currentSpawnTimer = 5.0f;

	UPROPERTY(BlueprintReadOnly)
	int pointsNeededToProgressToNextAct = 20;

public:
	
	virtual void Tick(float DeltaTime);
	UFUNCTION()
	void progress(int progressionPoints);

	UFUNCTION()
	void pauseGame(bool pause);

	UPROPERTY(EditAnywhere)
	float spawnRateMultiplier = 1.0f;

	UPROPERTY(EditAnywhere)
	float spawnBuffMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	float circleOfProtection = 1000.0f;

	UPROPERTY(BlueprintReadOnly)
	FVector playerLocation;
	
	UPROPERTY(BlueprintReadOnly)
	ACharacter* playerCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawning")
	TArray<TSubclassOf<AActor>> actorsToSpawn;
	
};
