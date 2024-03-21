// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"
#include "Card.h"

// 생성자
UPerson::UPerson()
{
	Name = TEXT("홍길동");
	Year = 1;

	// ======== Part 1 - 8 =========
	// CreateDefaultSubobject()의 첫 파라미터는 고유한 이름을 넣어줘야 함.
	// 접두사 NAME을 넣으면, 가독성 향상.
	Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card"));
}

//void UPerson::DoLesson()
//{
//	UE_LOG(LogTemp, Log, TEXT("%s님이 수업에 참여합니다."), *Name);
//}

//const FString& UPerson::GetName() const
//{
//	// TODO: insert return statement here
//	return Name;
//}
//
//void UPerson::SetName(const FString& InName)
//{
//	Name = InName;
//}
