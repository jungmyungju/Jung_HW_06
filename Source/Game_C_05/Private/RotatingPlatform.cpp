#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    RotationSpeed = 1.f;   
    MaxAngle = 0.f;       
    StartPhase = 0.f;     
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();
    StartTime = GetWorld()->GetTimeSeconds();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    float Time = GetWorld()->GetTimeSeconds() - StartTime;

    if (MaxAngle <= 0.f)
    {
        AddActorLocalRotation(FRotator(0, RotationSpeed * 45.f * DeltaTime, 0));
    }
    else
    {
        float Angle = FMath::Sin(Time * RotationSpeed + StartPhase) * MaxAngle;
        FRotator NewRotation(0, Angle, 0);
        SetActorRotation(NewRotation);
    }
}
