// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	// 생성자
	UMyGameInstance();

	virtual void Init() override;

private:

	// 이렇게 선언하면, 언리얼 시스템이 관리하면서
	// 런타임이든 컴파일 타임이든 우리가 언제든지
	// 가져올 수 있음.
	UPROPERTY()
	FString SchoolName;
};
