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
	// 프로퍼티가 언리얼 엔진 및 에디터에 이러한 프로퍼티가 있음을 알리고, 프로퍼티가 엔진과 연결되었을 때 어떻게 작동할지를 지정하기 위한 것

	UPROPERTY(EditAnyWhere)
	class UCameraComponent* _camera;

	// FVector2D
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void Turn(float InputValue);
	void LookUp(float InputValue);
};
