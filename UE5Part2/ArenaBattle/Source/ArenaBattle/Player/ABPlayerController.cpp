// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"


void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 시작하자 마자 Focus를 뷰포트에 지정
	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}