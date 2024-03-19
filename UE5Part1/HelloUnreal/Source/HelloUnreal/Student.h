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

private:

	UPROPERTY()
	int32 Id;

};
