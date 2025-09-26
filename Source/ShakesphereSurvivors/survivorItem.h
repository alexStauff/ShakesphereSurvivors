// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "survivorItem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHAKESPHERESURVIVORS_API UsurvivorItem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UsurvivorItem();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float baseCooldown = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float currentTimer = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float cooldownReduction = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float baseDamage = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float DamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float critChance = 5.0f;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	bool currentlyAttacking = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void DecrementTime(float DeltaTime);
	virtual void ActivateItem();
		
};
