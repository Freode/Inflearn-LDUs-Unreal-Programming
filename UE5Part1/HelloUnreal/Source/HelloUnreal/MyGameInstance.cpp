// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"

// cpp 파일 오브젝트에서도 헤더 순서를 조심해야 함.
// 현재 클래스 이름의 헤더가 가장 위에 선언되어야 함.

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

	// ================ Part 1 - 5 ================
	UE_LOG(LogTemp, Log, TEXT("====================="));
	// 런타임에서 클래스 정보 가져오기
	// 아래 둘을 동일한 객체를 가리킴.
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();
	// if 문 보다는 제대로 검증하고 다음 단계로 넘어가기 위해서
	// check 라는 어설션(Assertion) 함수를 사용

	// 만약에, Assertion이 실패하면, 에디터 꺼지고 크래쉬 오류가 나면서
	// 오류 원인을 알려줌.
	// 게임 모드로 구동하는 경우에는 해당 Assertion이 모두 사라지므로 안심하고 사용해도 됨.
	check(ClassRuntime == ClassCompile);
	// check(ClassRuntime != ClassCompile);

	// check는 에디터가 꺼지기 때문에, 불편할 수 있음.
	// 따라서, ensure를 사용해서 에디터가 꺼지지 않고도 문제점을 확일할 수 있음.
	// 오류 구문은 Output Log에서 "=== Handled ensure: ==="로 출력됨.
	// ensure(ClassRuntime == ClassCompile);

	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName());

	// 메시지를 남기고 싶을 때
	// ensureMsgf(ClassRuntime != ClassCompile, TEXT("일부러 에러를 발생시킨 코드"));

	// 이렇게 해도 생성자에서 기본값을 설정된 값은 사라지지 않음.
	// CDO 템플릿 객체에 저장되기 때문
	SchoolName = TEXT("울산대학교");

	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);

	// 출력되지 않는 경우가 종종 발생함.
	// CDO는 에디터가 활성화되기 이전에 초기화되는 순서를 가지고 있어서
	// 생성자에서 초기화를 해도 에디터에서 인지못하는 경우가 종종 있음.
	// <중요> CDO를 고쳐주는 생성자를 고칠 때는, Header파일과 똑같이 에디터를 끈 후에 에디터에서 컴파일 해줘야 함.
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("====================="));

	// ================ Part 1 - 6 ================
	// 객체 생성
	// NewObject<>를 통해서 생성해야 함.
	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();

	Student->SetName(TEXT("학생 1"));
	// Getter로 이름 가져오기
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 : %s"), *Student->GetName());

	// 리플렉션 시스템에서 지원하는 기능(프로퍼티 디시져)을 사용해 이름 가져오기
	// 속성 포인터를 이름으로 가져오기 -> 해당 속성에 대한 포인터를 가져오는 것
	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("이득우"));
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	// null이 아니면 사용 가능
	if (NameProp)
	{
		// NameProp에서 속성에 대해서 우리가 지정한 인스턴스에 대한 값을 가져오는 방법
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 : %s"), *CurrentTeacherName);

		NameProp->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 : %s"), *Teacher->GetName());
	}

	UE_LOG(LogTemp, Log, TEXT("====================="));

	//Student->DoLesson();
	//// 리플렉션 시스템을 통해서 함수 호출하기 위해서는 UFUNCTION에 대한 포인터 값을 알아야 함.
	//UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	//// Function에 대한 객체를 찾은 경우
	//if (DoLessonFunc)
	//{
	//	// 함수 포인터를 통해서 호출
	//	// DoLesson 함수는 인자가 없기 때문에, nullptr로 넣음.
	//	Teacher->ProcessEvent(DoLessonFunc, nullptr);
	//}

	// ================ Part 1 - 7 ================
	// TArray 사용해보기 : 동적 가변 배열
	UE_LOG(LogTemp, Log, TEXT("====================="));
	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>() };

	for (const auto Person : Persons)
	{
		UE_LOG(LogTemp, Log, TEXT("구성원 이름 : %s"), *Person->GetName());
	}
	UE_LOG(LogTemp, Log, TEXT("====================="));

	for (const auto Person : Persons)
	{
		// 형변환
		// 해당 인터페이스를 가지고 있지 않으면, null 값이 반환됨.
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if (LessonInterface)
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 있습니다."), *Person->GetName());
			LessonInterface->DoLesson();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 없습니다."), *Person->GetName());
		}
	}
	UE_LOG(LogTemp, Log, TEXT("====================="));

	// ======== Part 1 - 8 =========

	for (const auto Person : Persons)
	{
		const UCard* OwnCard = Person->GetCard();
		// 어차피 포함관계이기 때문에 반드시 존재함. 따라서, if문 쓰면 코드가 복잡해지므로 check를 쓰는것도 하나의 방법
		// if(OwnCard)
		check(OwnCard);
		ECardType CardType = OwnCard->GetCardType();
		UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %d"), *Person->GetName(), CardType);

		// 열거형에 적혀있는 META 타입의 DisplayName 출력하기
		// TEXT에 들어가는 절대 값, 절대 주솟값을 사용해서 원하는 타입을 가져올 수 있음. 
		// /Script/모듈이름.찾고 싶은 타입
		const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/HelloUnreal.ECardType"));
		if (CardEnumType)
		{
			// 텍스트로 반환되기 때문에, 출력할 때는 String으로 변경
			FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
			UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %s"), *Person->GetName(), *CardMetaData);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("====================="));
}

// 생성자
UMyGameInstance::UMyGameInstance()
{
	// 여기에 F9 키를 통해 브레이크를 걸어준 뒤, F5로 디버깅하면
	// 75%가 지난 시점에서 브레이크 포인트가 잡힘.
	// 엔진이 초기화되는 과정에서 CDO, UClass 정보가 만들어지고
	// 해당 정보가 다 만들어진 후에, 에디터, 게임과 같은 어플리케이션이 진행됨.

	// 기본값 지정해주기
	// CDO라고 하는 템플릿 객체에 저장됨.
	SchoolName = TEXT("기본학교");
}