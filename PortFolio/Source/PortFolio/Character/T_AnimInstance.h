// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "T_AnimInstance.generated.h"
/**
 * 
 */
UCLASS()
class PORTFOLIO_API UT_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

public:
	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = " true"))
	float _speed; // �ӵ�

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = " true"))
	bool _bIsInAir; // ���߿���

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = " true"))
	bool _bIsInputAccelerating; // �Է� ���ӵ�

private:
	// AllowPrivateAccess = private�������� ��밡�ɵ����ϰڴ�.
	UPROPERTY(BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class AT_Character* _character;
};
