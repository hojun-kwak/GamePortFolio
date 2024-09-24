// Fill out your copyright notice in the Description page of Project Settings.


#include "PortFolio/Character/T_Character.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AT_Character::AT_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	_springArm->SetupAttachment(RootComponent);
	_springArm->TargetArmLength = 180.0f;
	_springArm->bUsePawnControlRotation = true;

	// 카메라 생성
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	_camera->SetupAttachment(_springArm, USpringArmComponent::SocketName);
	_camera->bUsePawnControlRotation = true; // 폰제어 회전
}

// Called when the game starts or when spawned
void AT_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AT_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AT_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!PlayerInputComponent) return;

	// IE_Pressed - 눌렀을때
	// IE_Released - 땟을떄
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AT_Character::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &AT_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AT_Character::MoveRight);

	PlayerInputComponent->BindAxis("TurnCamera", this, &AT_Character::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AT_Character::LookUp);
}

void AT_Character::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void AT_Character::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void AT_Character::Turn(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void AT_Character::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

