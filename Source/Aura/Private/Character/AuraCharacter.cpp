// Copyright Bruno Galuzzi Corsini


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0,0,400.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	if (AuraPlayerState)
	{
		AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
		// Set pointers for character, since they are in the PS
		AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
		AttributeSet = AuraPlayerState->GetAttributeSet();

		// Initialize Overlay
		AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController());
		if (AuraPlayerController)
		{
			AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD());
			if (AuraHUD)
			{
				AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			}
		}
	}
}
