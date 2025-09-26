// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "survivorItem.h"
#include "survivorWeaponArc.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API UsurvivorWeaponArc : public UsurvivorItem
{
	GENERATED_BODY()
public:
	UsurvivorWeaponArc();
	void DecrementTime(float delta);
	void ActivateItem();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float arcAngle = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float angleMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float arcExtention = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float extensionMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float numberOfAttacks = 1.0f;

	//solid maybe
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float absoluteTimeBetweenAttacks = 0.1f;
};
