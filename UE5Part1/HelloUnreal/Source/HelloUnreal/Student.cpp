// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"
#include "Card.h"

// 생성자
UStudent::UStudent()
{
	Name = TEXT("이학생");
	Year = 1;
	Id = 1;

	// ======== Part 1 - 8 =========
	// 부모 클래스의 생성자가 먼저 실행되고 자식 클래스의 생성자가 실행되기 때문에
	// CreateDefaultSubobject<T>()를 다시 호출할 필요 없음.
	Card->SetCardType(ECardType::Student);
}

void UStudent::DoLesson()
{
	// Super 사용 불가능 -> Super로는 UPerson이 지정되어 있기 때문.
	// 클래스 정보에 대해서는 단일 상속만 지원
	// Super::DoLesson();

	// UE_LOG(LogTemp, Log, TEXT("%d학년 %d번 %s님이 수업을 듣습니다."), Year, Id, *Name);

	// 아래 방식으로 호출해야 함.
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%s님은 공부합니다."), *Name);
}
