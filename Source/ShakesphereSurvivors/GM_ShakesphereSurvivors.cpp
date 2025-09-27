// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ShakesphereSurvivors.h"

void AGM_ShakesphereSurvivors::progress(int progressionPoints)
{
	currentActProgress += progressionPoints;
	UE_LOG(LogTemp, Warning, TEXT("GM_Progress -> You have %d Points out of %d"), currentActProgress, pointsNeededToProgressToNextAct);
	if (currentActProgress >= pointsNeededToProgressToNextAct) {
		currentActProgress = 0;
		currentAct = currentAct + 1;
		pointsNeededToProgressToNextAct = FMath::Floor(pointsNeededToProgressToNextAct * 3.14);
		UE_LOG(LogTemp, Warning, TEXT("GM_Progress -> Congrats You have made it to act %d"), currentAct);
	}
}
