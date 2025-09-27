// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "InputActionValue.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "survivorItem.h"
#include "survivorWeaponArc.h"
#include "survivorWeaponProjectile.h"
#include "SurvivorBase.generated.h"

UCLASS()
class SHAKESPHERESURVIVORS_API ASurvivorBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASurvivorBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float movementSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float healthValue = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equpiment")
	TArray<UsurvivorItem*> playerEquipment;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveActionX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveActionY;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION()
	void MoveX(const FInputActionValue& Value);
	void MoveY(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category = "easeOfUse")
	void equipWeapon(UsurvivorItem* newWeapon);

};

