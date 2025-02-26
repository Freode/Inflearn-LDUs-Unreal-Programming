// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterNonPlayer.h"

AABCharacterNonPlayer::AABCharacterNonPlayer()
{

}


void AABCharacterNonPlayer::SetDead()
{
	Super::SetDead();

	// 액터를 제거만 하기에 별도의 함수를 만들어서 매핑하는 것이 더 귀찮.
	// 그래서, 람다 함수 사용
	FTimerHandle DeadTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		[&]()
		{
			Destroy();
		}
	), DeadEventDelayTime, false);
}