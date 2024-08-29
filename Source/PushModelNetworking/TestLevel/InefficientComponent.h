// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InefficientComponent.generated.h"


UCLASS()
class PUSHMODELNETWORKING_API UInefficientComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInefficientComponent();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(Replicated)
	float TestVar1 = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	float VariableUpdateChance = 0.1f;

	UPROPERTY(EditDefaultsOnly)
	float TimeBetweenTicks = 0.1f;

private:
	void TryToUpdateVar();
};
