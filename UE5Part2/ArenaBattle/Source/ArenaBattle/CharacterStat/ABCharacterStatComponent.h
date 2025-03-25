// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ABCharacterStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;

	FORCEINLINE float GetMaxHp() { return MaxHp; }
	FORCEINLINE float GetCurrentHp() { return CurrentHp; }
	float ApplyDamage(float InDamage);

protected:

	void SetHp(float NewHp);

	// 배치된 캐릭터마다 다른 값을 갖도록 설정
	UPROPERTY(VisibleInstanceOnly, Category = Stat)
	float MaxHp;

	// Transient 키워드 : Stat 컴포넌트라는 오브젝트를 저장할 때, 속성들이 모두 디스크에 저장되는데, 현재 Hp 값은 게임을 새롭게 시작할 때 마다 지정되므로 디스크에 저장할 필요가 없음.
	// 디스크에 저장할 필요가 없는 데이터 -> Transient 키워드 사용
	// 불필요한 메모리 낭비를 줄일 수 있음.

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentHp;
		
};
