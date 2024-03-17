// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
* 
*	객체 이름에다가 .generate.h은 이 프로젝트에 존재하지 않는데
*	어떻게 include 되냐? 일단, 다른 프로젝트에 있음.
 * 언리얼에서의 라이브러리 단위 : DLL
 * HELLOUNREAL_API를 통해 다른 라이브러리, 다른 곳에서도 MyObject를 사용할 수 있게 개방해준다는 것.
 * 없앨 수도 있음. -> 다른 모듈에서는 사용하지 못함. HelloUnreal 모듈 내에서만 작동 가능.
 * 
 */
UCLASS()
class HELLOUNREAL_API UMyObject : public UObject
{
	GENERATED_BODY()
	
};
