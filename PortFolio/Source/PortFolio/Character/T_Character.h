// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "Interfaces/PickupInterface.h"
#include "InputActionValue.h"
#include "T_Character.generated.h"

// springArm, camera 전방선언
class USpringArmComponent;
class UCameraComponent;

// EnhancedInput 관련헤더파일
class UInputMappingContext;
class UInputAction;

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
	virtual void Jump() override;

private:
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);

protected:
	// 프로퍼티가 언리얼 엔진 및 에디터에 이러한 프로퍼티가 있음을 알리고, 프로퍼티가 엔진과 연결되었을 때 어떻게 작동할지를 지정하기 위한 것

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* _springArm;

	UPROPERTY(EditAnyWhere) // ue의 권한 부여
	class UCameraComponent* _camera;

	UPROPERTY()
	bool _jumping;

	UPROPERTY(EditAnywhere, Category = HInput)
	UInputMappingContext* _mappingContext;
	UPROPERTY(EditAnywhere, Category = HInput)
	UInputAction* _movementAction;
	UPROPERTY(EditAnywhere, Category = HInput)
	UInputAction* _lookAction;
	UPROPERTY(EditAnywhere, Category = HInput)
	UInputAction* _jumpAction;

};
