// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

// 열거형
// 1. 접두사 E를 붙여야 함.
// 2. 보통 8bit = 1byte 형태로 해줌.
// 3. UENUM() 매크로를 붙여야 언리얼 엔진이 파악해서 사용할 수 있음.
UENUM()
enum class ECardType : uint8
{
	// 열거형마다 메타 정보를 넣을 수 있음.
	Student = 1 UMETA(DisplayName = "For Student"),
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
};

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UCard : public UObject
{
	GENERATED_BODY()
	
public:
	UCard();

	ECardType GetCardType() const { return CardType; }
	void SetCardType(ECardType InCardType) { CardType = InCardType; }

private:

	// 누구의 출입증인지 구별하기 위한 타입
	UPROPERTY()
	ECardType CardType;

	UPROPERTY()
	uint32 Id;
};
