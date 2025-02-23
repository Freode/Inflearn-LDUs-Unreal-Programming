// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "Player/ABPlayerController.h"


AABGameMode::AABGameMode()
{
	// C++ Ŭ������ �ƴ� ���� �츮�� �ּ����κ��� ������ �����;� ��.
	static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));

	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}

	// C++ Ŭ������ �̷��� ������ ������ �� ����.
	PlayerControllerClass = AABPlayerController::StaticClass();

	// C++ Ŭ������ ���� ��� ������ include ���� �ʰ� ���
	// �⺻���� �𸮾� Ŭ������ ������ ���̹Ƿ� ���� 
	//static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerRef(TEXT("/Script/ArenaBattle.ABPlayerController'"));
	//if (PlayerControllerRef.Class)
	//{
	//	PlayerControllerClass = PlayerControllerRef.Class;
	//}

}