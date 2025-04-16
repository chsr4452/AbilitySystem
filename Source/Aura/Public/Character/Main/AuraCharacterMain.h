// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacterMain.generated.h"

class AAuraPlayerState;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacterMain : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacterMain();
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AAuraPlayerState> AuraPlayerState;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	void InitCharacterInfo();
};
