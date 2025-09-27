// Fill out your copyright notice in the Description page of Project Settings.


#include "ActProgressionPoints.h"

void AActProgressionPoints::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ASurvivorBase::StaticClass())) {
		UE_LOG(LogTemp, Warning, TEXT("Player has Earned %d XP!"), ActProgressionOnPickUp);
		Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}
