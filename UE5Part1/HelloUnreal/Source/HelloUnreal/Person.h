// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UPerson : public UObject
{
	GENERATED_BODY()
	
public:
	// 생성자
	UPerson();

	// 
	// UFUNCTION()
	// virtual void DoLesson();

	// 변경되지 않을 것이므로 const로 지정
	// Getter

	// FORCEINLINE 키워드 : Inline으로 작동하는게 더 빠름.
	// Inline으로 전부 다 보장하지는 않음.
	// const로 반환하면, 변경하지 않겠다는 의미인데 & 레퍼런스로 반환하기 때문에
	// const가 무의미해짐. 따라서, FString&도 const FString&로 변경.
	FORCEINLINE const FString& GetName() const { return Name; }

	// Setter
	FORCEINLINE void SetName(const FString& InName) { Name = InName; }

	FORCEINLINE class UCard* GetCard() const { return Card; }
	FORCEINLINE void SetCard(class UCard* InCard) { Card = InCard; }

protected:

	// 언리얼 엔진 리플렉션 시스템에 등록해서 관리할 수 있도록 설정
	// 이름
	UPROPERTY()
	FString Name;

	// 연차
	int32 Year;

	// 언리얼 엔진 4버전까지는 정석
	//UPROPERTY()
	//class UCard* Card;

	// 언리얼 엔진 5 마이그레이션 가이드
	// 4 버전에서 5 버전으로 바꿀 때
	// C++ 오브젝트 포인터 프로퍼티
	// 포인터로 선언되었던 것들은 TObjectPtr<T>로 변경
	// 선언부에서만 그렇고 구현부에서는 상관없음.

	// 언리얼 엔진 5에서 선언하는 방법
	// 이미 포인터이기 때문에, 포인터 연산자를 빼주고 선언하면 됨.
	// 전방선언은 기존대로 이렇게 진행
	UPROPERTY()
	TObjectPtr<class UCard> Card;

private:

};
