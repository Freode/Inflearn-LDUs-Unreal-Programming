// Fill out your copyright notice in the Description page of Project Settings.


#include "Staff.h"
#include "Card.h"

UStaff::UStaff()
{
	Name = TEXT("이직원");

	// ======== Part 1 - 8 =========
	// 부모 클래스의 생성자가 먼저 실행되고 자식 클래스의 생성자가 실행되기 때문에
	// CreateDefaultSubobject<T>()를 다시 호출할 필요 없음.
	Card->SetCardType(ECardType::Staff);
}