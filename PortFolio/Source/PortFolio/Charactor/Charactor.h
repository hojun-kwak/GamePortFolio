// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Charactor.generated.h"

UCLASS()
class PORTFOLIO_API ACharactor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharactor();

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

	UPROPERTY(EditAnyWhere)
	class UCameraComponent* _camera;

	// FVector2D
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void Turn(float InputValue);
	void LookUp(float InputValue);
};
