// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
#include "LessonInterface.h"
#include "Student.generated.h"

/**
 * Unreal Header Tool에서 generated.h 밑에 다른 헤더 파일이 있으면 안됨.
 * 따라서, 그 위에다가 선언해야 함.
 */
UCLASS()
class HELLOUNREAL_API UStudent : public UPerson, public ILessonInterface
{
	GENERATED_BODY()
	
public:
	// 생성자
	UStudent();

	virtual void DoLesson() override;

	// ======== Part 1 - 9 =========
	// 알림을 받는 함수 필요
	// 델리게이트 전송 함수의 인자와 똑같은 형태의 인자를 가지고 있어야 함.
	void GetNotification(const FString& School, const FString& NewCourseInfo);

private:

	UPROPERTY()
	int32 Id;

};
