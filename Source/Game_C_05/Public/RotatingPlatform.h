
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class GAME_C_05_API ARotatingPlatform : public AActor
{
    GENERATED_BODY()

public:
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation Settings", meta = (AllowPrivateAccess = "true"))
    float RotationSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation Settings", meta = (AllowPrivateAccess = "true"))
    float MaxAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation Settings", meta = (AllowPrivateAccess = "true"))
    float StartPhase;

    float StartTime;
};