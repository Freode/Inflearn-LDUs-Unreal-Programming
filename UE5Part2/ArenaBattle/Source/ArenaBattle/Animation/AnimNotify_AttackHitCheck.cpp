// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
#include "Interface/ABAnimationAttackInterface.h"

// notify 경우 매 번 헤더를 추가하는 것은 좋지 않기에
// 노티파이 전용 인터페이스 클래스를 따로 만들어서 모아서 관리하는게 좋음

// 즉, 어쩔 수 없이 의존성이 생기는 경우 범용적으로 관리하기 위해
// 인터페이스로 구현하는 것이 좋음.

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		IABAnimationAttackInterface* AttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());

		if (AttackPawn)
		{
			AttackPawn->AttackHitCheck();
		}
	}
}