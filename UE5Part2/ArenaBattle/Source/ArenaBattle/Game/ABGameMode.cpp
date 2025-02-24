// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "Player/ABPlayerController.h"


AABGameMode::AABGameMode()
{

	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/ArenaBattle.ABCharacterPlayer"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	// C++ 클래스가 아닌 것은 우리가 애셋으로부터 정보를 가져와야 함.
	//static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));

	//if (ThirdPersonClassRef.Class)
	//{
	//	DefaultPawnClass = ThirdPersonClassRef.Class;
	//}

	// C++ 클래스는 이렇게 정보를 가져올 수 있음.
	PlayerControllerClass = AABPlayerController::StaticClass();

	// C++ 클래스에 대한 헤더 파일을 include 하지 않고 사용
	// 기본으로 언리얼 클래스가 복제된 것이므로 가능 
	//static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerRef(TEXT("/Script/ArenaBattle.ABPlayerController'"));
	//if (PlayerControllerRef.Class)
	//{
	//	PlayerControllerClass = PlayerControllerRef.Class;
	//}

}