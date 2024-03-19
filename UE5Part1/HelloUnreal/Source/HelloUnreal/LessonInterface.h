// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LessonInterface.generated.h"

// This class does not need to be modified.
// 타입 정보를 관리하기 위한 언리얼 엔진이 자동으로 생성한 클래스
UINTERFACE(MinimalAPI)
class ULessonInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *  실제로 구현하는 부분
 *	해당 인터페이스를 상속받는 클래스들은 반드시 DoLesson() 함수를 구현해야 함.
 */
class HELLOUNREAL_API ILessonInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// virtual void DoLesson() = 0;

	// 아래 경우에는 더 이상 추상클래스가 아니기 때문에 하위 클래스에서 반드시 구현할 필요는 없음.
	virtual void DoLesson()
	{
		UE_LOG(LogTemp, Log, TEXT("수업에 입장합니다."));
	}
};
