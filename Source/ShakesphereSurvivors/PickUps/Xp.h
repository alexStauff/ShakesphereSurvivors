// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "Xp.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API AXp : public APickUp
{
	GENERATED_BODY()

public:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere)
	int XPValueOnPickUp = 1;
};
