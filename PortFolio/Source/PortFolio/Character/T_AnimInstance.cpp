// Fill out your copyright notice in the Description page of Project Settings.


#include "PortFolio/Character/T_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PortFolio/Character/T_Character.h" // ĳ������ ������ ������������ ����

void UT_AnimInstance::NativeInitializeAnimation()
{
	// ������ �Լ��� super�� �⺻���� �θ� �ҷ��;���
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

	// ���߿���
	_bIsInAir = _character->GetCharacterMovement()->IsFalling();
	// Ű�� �������� true�� ���ӵ��� ������
	_bIsInputAccelerating = _character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.0f ? true : false;
}
