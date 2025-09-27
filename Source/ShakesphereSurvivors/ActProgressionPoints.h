// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "ActProgressionPoints.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESPHERESURVIVORS_API AActProgressionPoints : public APickUp
{
	GENERATED_BODY()

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere)
	int ActProgressionOnPickUp = 1;
};
