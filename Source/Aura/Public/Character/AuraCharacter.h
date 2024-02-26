// Copyright Bruno Galuzzi Corsini

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraBaseCharacter.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraBaseCharacter
{
	GENERATED_BODY()

public:

	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Interface */

private:

	virtual void InitAbilityActorInfo() override;
};
