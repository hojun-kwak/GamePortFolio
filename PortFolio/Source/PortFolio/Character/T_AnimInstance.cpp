// Fill out your copyright notice in the Description page of Project Settings.


#include "PortFolio/Character/T_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PortFolio/Character/T_Character.h" // 캐릭터의 정보를 가져오기위해 선언

void UT_AnimInstance::NativeInitializeAnimation()
{
	// 재정의 함수는 super를 기본으로 부모를 불러와야함
	Super::NativeInitializeAnimation();

	_character = Cast<AT_Character>(TryGetPawnOwner());
}

// Frame
void UT_AnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (_character == nullptr) return;

	FVector velocity = _character->GetVelocity();
	velocity.Z = 0.0f;
	_speed = velocity.Size();

	// 공중여부
	_bIsInAir = _character->GetCharacterMovement()->IsFalling();
	// 키를 눌렀을떄 true면 가속도를 가져옴
	_bIsInputAccelerating = _character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.0f ? true : false;
}
