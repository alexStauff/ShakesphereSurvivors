// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ShakesphereSurvivors.h"
void AGM_ShakesphereSurvivors::BeginPlay() {
    UWorld* World = GetWorld();
    if (World) {
        ACharacter* PlayerPawn = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
        ASurvivorBase* MyPlayerCharacter = Cast<ASurvivorBase>(PlayerPawn);
        if (MyPlayerCharacter) {
            playerCharacter = MyPlayerCharacter;
        }
    }
    
}
void AGM_ShakesphereSurvivors::Tick(float DeltaTime) {
    currentSpawnTimer -= DeltaTime;
    if (currentSpawnTimer <= 0.0f) {
        //spawn badGuy
        playerLocation =  playerCharacter->GetActorLocation();
        UWorld* World = GetWorld();
        if (World)
        {
            if (actorsToSpawn[0])
            {
                FActorSpawnParameters SpawnParams;
                SpawnParams.Owner = this; // Optional: Set the owner of the spawned actor
                float randRad = FMath::FRandRange(0.0, PI * 2);
                FVector MagicCircle = FVector(playerLocation.X + circleOfProtection * FMath::Cos(randRad), playerLocation.Y + circleOfProtection * FMath::Sin(randRad), 0.0f);
                AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(actorsToSpawn[0], MagicCircle, FRotator(0.0f, 0.0f, 0.0f), SpawnParams);

                if (SpawnedActor)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Successfully spawned actor: %s"), *SpawnedActor->GetName());
                }
                else
                {
                    UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor."));
                }
            }
            //FActorSpawnParameters SpawnParams;
            //// Spawn the projectile at the muzzle.
            //ABaseProjectile* Projectile = World->SpawnActor<ABaseProjectile>(ABaseProjectile::StaticClass(), WorldLocation + (DirectionVector * (16.0f)), FRotator(0.0f, 0.0f, 0.0f), SpawnParams);//World->SpawnActor<ABaseProjectile>(ProjectileClass, WorldLocation, DirectionVector, SpawnParams);
            //if (Projectile)
            //{
            //    Projectile->FireInDirection(DirectionVector);
            //}
        }
        currentSpawnTimer = enemySpawnTimer * spawnRateMultiplier;
    }
}
void AGM_ShakesphereSurvivors::progress(int progressionPoints)
{
	currentActProgress += progressionPoints;
	UE_LOG(LogTemp, Warning, TEXT("GM_Progress -> You have %d Points out of %d"), currentActProgress, pointsNeededToProgressToNextAct);
	if (currentActProgress >= pointsNeededToProgressToNextAct) {
		currentActProgress = 0;
		currentAct = currentAct + 1;
		pointsNeededToProgressToNextAct = FMath::Floor(pointsNeededToProgressToNextAct * 3.14);
		UE_LOG(LogTemp, Warning, TEXT("GM_Progress -> Congrats You have made it to act %d"), currentAct);
	}
}

void AGM_ShakesphereSurvivors::pauseGame(bool pause)
{
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0); // Get the first local player controller
    if (PlayerController)
    {
        bool bIsGamePaused = UGameplayStatics::IsGamePaused(GetWorld());
        UGameplayStatics::SetGamePaused(GetWorld(), !bIsGamePaused);
        if (!bIsGamePaused) {
            UE_LOG(LogTemp, Warning, TEXT("Pause"));
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("Resumed"));
        }
    }
}
