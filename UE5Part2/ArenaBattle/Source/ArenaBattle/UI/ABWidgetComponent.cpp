// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABWidgetComponent.h"
#include "ABUserWidget.h"

void UABWidgetComponent::InitWidget()
{
	// InitWidget 함수 내부에 CreateWidget 함수를 통해 인스턴스를 만드는 함수가 있기에, Super 이후부터는 위젯에 대한 인스턴스가 존재하므로 GetWidget()이 가능
	Super::InitWidget();

	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());

	if (ABUserWidget)
	{
		ABUserWidget->SetOwningActor(GetOwner());
	}
}