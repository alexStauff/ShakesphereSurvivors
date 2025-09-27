// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    if (!RootComponent)
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
    }

    if (!CollisionComponent)
    {
        // Use a sphere as a simple collision representation.
        CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
        // Set the sphere's collision profile name to "Projectile".
        CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
        // Event called when component hits something.

        CollisionComponent->SetBoxExtent(FVector(1.0f, 1.0f, 1.0f));
        CollisionComponent->AddLocalOffset(FVector(0.0f, 0.0f, 0.0f));

        CollisionComponent->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
        // Set the sphere's collision radius.
        //CollisionComponent->InitSphereRadius(15.0f);
        // Set the root component to be the collision component.
        RootComponent = CollisionComponent;
    }

    if (!ProjectileMovementComponent)
    {
        // Use this component to drive this projectile's movement.
        ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
        ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
        ProjectileMovementComponent->InitialSpeed = 256.0f*4.0f;
        ProjectileMovementComponent->MaxSpeed = 256.0f * 4.0f;
        ProjectileMovementComponent->bRotationFollowsVelocity = true;
        ProjectileMovementComponent->bShouldBounce = true;
        ProjectileMovementComponent->Bounciness = 0.3f;
        ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
    }

    if (!ProjectileMeshComponent)
    {
        ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
        static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/SM_MERGED_SimpleDagger.SM_MERGED_SimpleDagger'"));
        if (Mesh.Succeeded())
        {
            ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
        }
        ProjectileMeshComponent->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
        ProjectileMeshComponent->SetupAttachment(RootComponent);
        ProjectileMeshComponent->CastShadow = false;
    }
    // Delete the projectile after 3 seconds.
    InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::FireInDirection(const FVector& ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// Function that is called when the projectile hits something.
void ABaseProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    
    if (OtherActor)
    {
        UGameplayStatics::ApplyDamage(
            OtherActor,             // The actor to damage
            10.0f,                  // Base damage amount
            GetInstigatorController(), // Controller responsible for the damage (e.g., player controller)
            this,                   // Actor that directly caused the damage (e.g., the projectile)
            UDamageType::StaticClass() // Type of damage (you can create custom UDamageType classes)
        );
    }
    Destroy();
}
