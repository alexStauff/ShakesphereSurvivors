// Fill out your copyright notice in the Description page of Project Settings.

#include "SurvivorBase.h"
#include "PickUp.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    if (!RootComponent)
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    }

    if (!CollisionSphere)
    {
        // Use a sphere as a simple collision representation.
        CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
        // Set the sphere's collision profile name to "Projectile".
        CollisionSphere->BodyInstance.SetCollisionProfileName(TEXT("OverlapAll"));
        // Event called when component hits something.
        // Set the sphere's collision radius.

        RootComponent = CollisionSphere;
        CollisionSphere->SetSphereRadius(50.f);
        CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnOverlapBegin);
    }
    if (!MeshComponent)
    {
        MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
        static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
        if (Mesh.Succeeded())
        {
            MeshComponent->SetStaticMesh(Mesh.Object);
        }
        MeshComponent->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
        MeshComponent->SetupAttachment(RootComponent);
        MeshComponent->CastShadow = false;
    }
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ASurvivorBase* PlayerCharacter = Cast<ASurvivorBase>(OtherActor);
    if (PlayerCharacter)
    {
        // Implement pickup logic here, e.g., add to inventory
        UE_LOG(LogTemp, Warning, TEXT("Player picked up item!"));
        Destroy(); // Destroy the pickup after interaction
    }
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

