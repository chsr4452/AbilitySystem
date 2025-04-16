// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/AuraCharacterEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraCharacterEnemy::AAuraCharacterEnemy()
{
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
}

void AAuraCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
}
