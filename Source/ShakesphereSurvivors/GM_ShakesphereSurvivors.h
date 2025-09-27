// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GM_ShakesphereSurvivors.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API AGM_ShakesphereSurvivors : public AGameMode
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadOnly)
	int currentAct = 1;
	UPROPERTY(BlueprintReadOnly)
	int currentActProgress = 0;

	UPROPERTY(BlueprintReadOnly)
	int pointsNeededToProgressToNextAct = 20;

public:
	
	UFUNCTION()
	void progress(int progressionPoints);
	
	
};
