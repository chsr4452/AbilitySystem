// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

#include "Animation/AuraAnimInstance.h"

// Sets default values		
AAuraCharacterBase::AAuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	AnimInstance = Cast<UAuraAnimInstance>(GetMesh()->GetAnimInstance());
}

void AAuraCharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AnimInstance->MoveSpeed = GetVelocity().Size();
}

