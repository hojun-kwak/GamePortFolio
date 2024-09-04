// Fill out your copyright notice in the Description page of Project Settings.


#include "PortFolio/Charactor/Charactor.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACharactor::ACharactor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	_camera->SetupAttachment(RootComponent); // 카메라연결
	_camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ACharactor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// IE_Pressed : 입력했을때
	// IE_Released : 입력을 땔때
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharactor::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACharactor::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharactor::MoveRight);

	PlayerInputComponent->BindAxis("TurnCamera", this, &ACharactor::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharactor::LookUp);
}

void ACharactor::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void ACharactor::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void ACharactor::Turn(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void ACharactor::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

