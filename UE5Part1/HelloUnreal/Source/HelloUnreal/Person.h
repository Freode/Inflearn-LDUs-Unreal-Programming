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
	FORCEINLINE FString& GetName() { return Name; }

	// Setter
	FORCEINLINE void SetName(const FString& InName) { Name = InName; }

protected:

	// 언리얼 엔진 리플렉션 시스템에 등록해서 관리할 수 있도록 설정
	// 이름
	UPROPERTY()
	FString Name;

	// 연차
	int32 Year;

private:

};
