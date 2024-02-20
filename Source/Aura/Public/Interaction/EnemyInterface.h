// Copyright Bruno Galuzzi Corsini

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

public:
	// "=0" makes it a pure virtual function -> abstract class and must be defined in class that implements it //
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
