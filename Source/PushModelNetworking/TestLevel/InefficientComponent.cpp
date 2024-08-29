#include "InefficientComponent.h"

#include "Net/UnrealNetwork.h"
#include "Net/Core/PushModel/PushModel.h"

UInefficientComponent::UInefficientComponent()
{
	SetIsReplicatedByDefault(true);

	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;
}

void UInefficientComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams Params;
	Params.bIsPushBased = true;
	
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, TestVar1, Params);
}

void UInefficientComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!IsNetMode(NM_Client))
	{
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &UInefficientComponent::TryToUpdateVar, TimeBetweenTicks, true);
	}
}

void UInefficientComponent::TryToUpdateVar()
{
	if (FMath::RandRange(0.0f, 1.0f) > VariableUpdateChance * TimeBetweenTicks)
	{
		return;
	}
	
	TestVar1 = FMath::RandRange(0.0f, 1000.0f);
	MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, TestVar1, this);
}