#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    MoveSpeed = 1.f;        
    MaxRange = 500.f;        
    MoveDirection = FVector(1, 0, 0);
    StartPhase = 0.f;      
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetActorLocation();

    if (MoveDirection.IsNearlyZero())
    {
        MoveDirection = FVector(1, 0, 0);
    }
    MoveDirection = MoveDirection.GetSafeNormal();
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    float Time = GetWorld()->GetTimeSeconds();

    float Offset = FMath::Sin(Time * MoveSpeed + StartPhase) * MaxRange;
    FVector NewLocation = StartLocation + MoveDirection * Offset;

    SetActorLocation(NewLocation);
}
