#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"


UCLASS()
class GAME_C_05_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings", meta = (AllowPrivateAccess = "true"))
    float MoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings", meta = (AllowPrivateAccess = "true"))
    float MaxRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings", meta = (AllowPrivateAccess = "true"))
    FVector MoveDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings", meta = (AllowPrivateAccess = "true"))
    float StartPhase;

    FVector StartLocation;
};