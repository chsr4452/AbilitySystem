// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Main/AuraCharacterMain.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Game/AuraPlayerState.h"
#include "GameFramework/SpringArmComponent.h"

AAuraCharacterMain::AAuraCharacterMain()
{
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 800;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = false;
	SpringArmComponent->SetWorldRotation(FRotator(-60, 0, 0));
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

void AAuraCharacterMain::BeginPlay()
{
	Super::BeginPlay();
	
	AuraPlayerState = Cast<AAuraPlayerState>(GetPlayerState());
	if (AuraPlayerState)
	{
		AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
		AttributeSet = AuraPlayerState->GetAttributeSet();
	}
}

void AAuraCharacterMain::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AAuraCharacterMain::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void AAuraCharacterMain::InitCharacterInfo()
{
	GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
}
