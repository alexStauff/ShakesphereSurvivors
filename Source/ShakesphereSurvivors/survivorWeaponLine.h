// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "survivorItem.h"
#include "survivorWeaponLine.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API UsurvivorWeaponLine : public UsurvivorItem
{
	GENERATED_BODY()
public:
	UsurvivorWeaponLine();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float baseLineWidth = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float LineWidthMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float numberOfAttacks = 1.0f;
	
	//solid maybe
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float absoluteTimeBetweenAttacks = 0.1f;
};
