// Fill out your copyright notice in the Description page of Project Settings.


#include "survivorItem.h"

// Sets default values for this component's properties
UsurvivorItem::UsurvivorItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UsurvivorItem::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UsurvivorItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

void UsurvivorItem::DecrementTime(float DeltaTime)
{
	currentTimer = currentTimer - DeltaTime;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("My Float Value: %f"), currentTimer));
	if (currentTimer <= 0.0f && !currentlyAttacking) {
		currentlyAttacking = true;
		ActivateItem();
	}
}

void UsurvivorItem::ActivateItem()
{
	//Logic to use weapon, for x attacks
	//Reset Timer
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SHAW!"));
	currentTimer = baseCooldown * cooldownReduction;
	currentlyAttacking = false;
}

