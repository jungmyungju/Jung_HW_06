#pragma once //헤더파일 한번만 불러오기

#include "CoreMinimal.h" //로그, 함수등 언리얼 기본 타입들
#include "GameFramework/Actor.h" //액터클래스의 정보를 가진 헤더파일
#include "Item.generated.h" //리플렉션 시스템?



UCLASS() // 리플레션 시스템 관련 (지금 안다룸)
class BASIS_API AItem : public AActor //아이템클래스가 액터를 상속 근데 왜 A가 붙어있냐. 언리얼 클래스는 클래스 앞에 접두어를 붙이는걸 권장함
	//액터는 A / 오브젝트 U / 구조체 F / Enum E 
{
	GENERATED_BODY() // UCLASS랑 쌍으로 다님
	
public:	
	// Sets default values for this actor's properties
	AItem(); //생성자

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;



	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



	UFUNCTION(BluePrintCallable, Category="Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category="Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item|Event")
	void OnItemPickedUP();
};
