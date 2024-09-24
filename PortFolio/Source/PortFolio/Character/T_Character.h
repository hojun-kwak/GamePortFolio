// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "T_Character.generated.h"

// springArm, camera ���漱��
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PORTFOLIO_API AT_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AT_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// ������Ƽ�� �𸮾� ���� �� �����Ϳ� �̷��� ������Ƽ�� ������ �˸���, ������Ƽ�� ������ ����Ǿ��� �� ��� �۵������� �����ϱ� ���� ��

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _springArm;

	UPROPERTY(EditAnyWhere) // ue�� ���� �ο�
	class UCameraComponent* _camera;

	// FVector2D
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void Turn(float InputValue);
	void LookUp(float InputValue);
};
