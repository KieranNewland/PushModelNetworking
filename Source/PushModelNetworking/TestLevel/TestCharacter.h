#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

UCLASS()
class PUSHMODELNETWORKING_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:	
	virtual void Tick(float DeltaTime) override;

};
