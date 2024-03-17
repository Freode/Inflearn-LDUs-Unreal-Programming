// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	//UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello Unreal!"));

	TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);

	// 배열로 들어가기 때문에 3번째 매크로에 TEXT("%s")를 추가해야 함.
	// %s에 대응될 때는 TCHAR의 포인터 어레이를 반환해줘야 함.
	// FString을 %s에 바로 대응 불가능. 포인터 연산자를 써야함.
	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	// FString -> TCHAR
	const TCHAR* LongCharPtr = *LogCharString;
	// const 사용하지 않고 활용 가능.
	// 메모리제 직접 가능
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData();

	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);

	// 대소문자 무시하고 진행
	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		// 몇 번째 위치에 unreal 글자가 있는지 찾기
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);

		// unreal이 시작되는 위치부터 끝까지 잘라주기
		FString EndString = LogCharString.Mid(Index);

		// 출력
		UE_LOG(LogTemp, Log, TEXT("Find Test : %s"), *EndString);
	}

	// 자르는 함수
	FString Left, Right;
	// 공백을 중심으로 왼쪽과 오른쪽으로 나눔.
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Split Test : %s와 %s"), *Left, *Right);
	}

	// int와 float 출력
	int32 IntValue = 32;
	float FloatValue = 3.141592;

	// Printf 사용해서 바로 출력하기
	FString FloatIntString = FString::Printf(TEXT("Int : %d, Float : %f"), IntValue, FloatValue);

	// 형변환한 다음에 출력하기
	// float는 형변환할려면, 뭔가 조금 복잡함.
	FString FloatString = FString::SanitizeFloat(FloatValue);
	FString IntString = FString::FromInt(IntValue);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int : %s, Float : %s"), *IntString, *FloatString);

	// String을 다시 float와 int형으로 형변환
	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	FString FloatIntString2 = FString::Printf(TEXT("Int : %d, Float : %f"), IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString2);

	// FName

	// 대소문자 구분하지 않음.
	FName Key1(TEXT("PELVIS"));
	FName Key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), Key1 == Key2 ? TEXT("같음") : TEXT("다름"));

	// FName 사용할 때, 주의할 점.
	//for (int i = 0; i < 10000; ++i)
	//{
	//	// 빈번한 작업을 하는데 오버헤드가 있어 적합하지 않음.
	//	// 아래 작업을 하는데 Pool에 존재하는지 키를 통해서 먼저 조사하는 작업을 거침.
	//	FName SearchInNamePool = FName(TEXT("pelvis"));
	//	
	//	// local static으로 선언했으므로 그 다음부터는 찾을 일이 없음.
	//	const static FName StaticOnlyOnce(TEXT("pelvis"));

	//	// 두 번째 방식이 더 효과적이다.
	//}
}