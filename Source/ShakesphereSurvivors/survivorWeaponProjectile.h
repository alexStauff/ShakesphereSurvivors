// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "survivorItem.h"
#include "survivorWeaponProjectile.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API UsurvivorWeaponProjectile : public UsurvivorItem
{
	GENERATED_BODY()
public:
	UsurvivorWeaponProjectile();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float baseProjWidth = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float numberOfProjectiles = 1.0f;

	//IsItBetterToHaveItShotgun or chaotic clumps
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float shotgunAngle = 1.0f;
	
};
