#pragma once //������� �ѹ��� �ҷ�����

#include "CoreMinimal.h" //�α�, �Լ��� �𸮾� �⺻ Ÿ�Ե�
#include "GameFramework/Actor.h" //����Ŭ������ ������ ���� �������
#include "Item.generated.h" //���÷��� �ý���?



UCLASS() // ���÷��� �ý��� ���� (���� �ȴٷ�)
class BASIS_API AItem : public AActor //������Ŭ������ ���͸� ��� �ٵ� �� A�� �پ��ֳ�. �𸮾� Ŭ������ Ŭ���� �տ� ���ξ ���̴°� ������
	//���ʹ� A / ������Ʈ U / ����ü F / Enum E 
{
	GENERATED_BODY() // UCLASS�� ������ �ٴ�
	
public:	
	// Sets default values for this actor's properties
	AItem(); //������

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
