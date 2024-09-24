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
	float _speed; // 속도

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = " true"))
	bool _bIsInAir; // 공중여부

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = " true"))
	bool _bIsInputAccelerating; // 입력 가속도

private:
	// AllowPrivateAccess = private변수들을 사용가능도록하겠다.
	UPROPERTY(BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class AT_Character* _character;
};
