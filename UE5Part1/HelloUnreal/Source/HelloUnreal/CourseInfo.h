// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CourseInfo.generated.h"

// ======== Part 1 - 9 =========
// 두 개의 인자를 갖는 일대다 형태의 멀티캐스트
// CourseInfo가 변경되었음을 알려주므로 OnChanged를 붙이고
// Signature 접미사를 붙임.
DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangedSignature, const FString&, const FString&);

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UCourseInfo : public UObject
{
	GENERATED_BODY()
	
	
public:
	UCourseInfo();

	// 델리게이트 객체 선언
	FCourseInfoOnChangedSignature OnChanged;

	// 외부에서 학사 정보를 변경할 때, 사용하는 함수
	void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents);

private:

	// UPROPERTY() 매크로 붙여도 되고 안붙여도 됨.
	// 붙인다고 해서 이 변수를 동적 관리할 필요 없고
	// 블루프린트나 리플렉션을 통해 사용하지 않을 거면, 안 붙여도 상관 없음.
	FString Contents;
};
