// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyChar.h"

// Sets default values
ABaseEnemyChar::ABaseEnemyChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseEnemyChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemyChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ABaseEnemyChar::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    // Call the base class implementation first
    float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

    // Apply damage to health
    CurrentHealth -= ActualDamage;

    // Clamp health to ensure it doesn't go below zero
    CurrentHealth = FMath::Max(0.0f, CurrentHealth);

    UE_LOG(LogTemp, Warning, TEXT("%s took %f damage. Current Health: %f"), *GetName(), ActualDamage, CurrentHealth);

    // Handle death if health reaches zero
    if (CurrentHealth <= 0.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s has died!"), *GetName());
        FVector WorldLocation = GetActorLocation();
        UWorld* World = GetWorld();
        if (World)
        {
            FActorSpawnParameters SpawnParams;
            // Spawn the projectile at the muzzle.
            AXp* pickUp = World->SpawnActor<AXp>(AXp::StaticClass(), WorldLocation, FRotator(0.0f, 0.0f, 0.0f), SpawnParams);
            if (pickUp) {
                pickUp->XPValueOnPickUp = 5;
            }
            AGM_ShakesphereSurvivors* gm_ref = Cast<AGM_ShakesphereSurvivors>(GetWorld()->GetAuthGameMode());
            if (gm_ref) {
                gm_ref->progress(1);
            }
        }
        Destroy();
        // Implement death logic here (e.g., play death animation, destroy actor)
    }

    return ActualDamage; // Return the actual damage dealt
}
// Called to bind functionality to input
void ABaseEnemyChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

