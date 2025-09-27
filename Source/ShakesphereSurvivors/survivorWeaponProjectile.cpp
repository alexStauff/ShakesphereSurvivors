// Fill out your copyright notice in the Description page of Project Settings.


#include "survivorWeaponProjectile.h"

UsurvivorWeaponProjectile::UsurvivorWeaponProjectile()
{
}

void UsurvivorWeaponProjectile::DecrementTime(float delta) {
	Super::DecrementTime(delta);
}

void UsurvivorWeaponProjectile::ActivateItem() {
	AActor* OwningActor = GetOwner();
	if (OwningActor) {
		FVector WorldLocation = OwningActor->GetActorLocation();
		FVector DirectionVector = OwningActor->GetActorForwardVector();
        UWorld* World = GetWorld();
        if (World)
        {
            FActorSpawnParameters SpawnParams;
            // Spawn the projectile at the muzzle.
            ABaseProjectile* Projectile = World->SpawnActor<ABaseProjectile>(ABaseProjectile::StaticClass(), WorldLocation + DirectionVector * (4.0f), FRotator(0.0f, 0.0f, 0.0f), SpawnParams);//World->SpawnActor<ABaseProjectile>(ProjectileClass, WorldLocation, DirectionVector, SpawnParams);
            if (Projectile)
            {
                Projectile->FireInDirection(DirectionVector);
            }
        }
	}
    Super::ActivateItem();
}
void UsurvivorWeaponProjectile::PrintFVector(const FVector& MyFVector)
{
    UE_LOG(LogTemp, Warning, TEXT("FVector value: %s"), *MyFVector.ToString());
}
