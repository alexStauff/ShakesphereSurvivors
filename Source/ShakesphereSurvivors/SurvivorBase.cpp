// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivorBase.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ASurvivorBase::ASurvivorBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASurvivorBase::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	// Get the player controller for this character
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		PlayerController->bShowMouseCursor = true;
		// Get the enhanced input local player subsystem and add a new input mapping context to it
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerContext, 0);
		}
	}
	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using SurvivorBaseCharacter."));
	
}

// Called every frame
void ASurvivorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector pLoc = GetActorLocation();
	FRotator pRot = GetActorRotation();
	FVector WorldLocation;
	FVector WorldDirection;
	Cast<APlayerController>(GetController())->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
	pRot.Yaw = UKismetMathLibrary::FindLookAtRotation(pLoc, WorldLocation).Yaw;
	SetActorRotation(pRot);
}

// Called to bind functionality to input
void ASurvivorBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Bind Movement Actions
		EnhancedInputComponent->BindAction(MoveActionX, ETriggerEvent::Triggered, this, &ASurvivorBase::MoveX);
		EnhancedInputComponent->BindAction(MoveActionY, ETriggerEvent::Triggered, this, &ASurvivorBase::MoveY);
	}

}

void ASurvivorBase::MoveX(const FInputActionValue& Value)
{
	const FVector2D MovementValue = Value.Get<FVector2D>();
	if (Controller) {
		AddMovementInput(FVector(MovementValue.X, 0.0f, 0.0f), movementSpeed);
	}
}

void ASurvivorBase::MoveY(const FInputActionValue& Value)
{
	const FVector2D MovementValue = Value.Get<FVector2D>();
	if (Controller) {
		AddMovementInput(FVector(0.0f, MovementValue.X, 0.0f), movementSpeed);
	}
}

