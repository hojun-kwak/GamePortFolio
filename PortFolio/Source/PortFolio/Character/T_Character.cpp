// Fill out your copyright notice in the Description page of Project Settings.


#include "PortFolio/Character/T_Character.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AT_Character::AT_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	_springArm->SetupAttachment(RootComponent);
	_springArm->TargetArmLength = 280.0f;
	_springArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	_springArm->bUsePawnControlRotation = true; // 카메라 회전설정
	_springArm->bEnableCameraLag = true;
	_springArm->CameraLagSpeed = 2;
	_springArm->CameraLagMaxDistance = 1.5f;
	_springArm->bEnableCameraRotationLag = true;

	// 카메라 생성
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	_camera->SetupAttachment(_springArm, USpringArmComponent::SocketName);
	_camera->bUsePawnControlRotation = true; // 폰제어 회전

	// 점프
	GetCharacterMovement()->JumpZVelocity = 500.0f;
	JumpMaxCount = 1;
}

// Called when the game starts or when spawned
void AT_Character::BeginPlay()
{
	Super::BeginPlay();

	playerController = Cast<APlayerController>(Controller);

	if (playerController)
	{
		UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
		if (subSystem)
			subSystem->AddMappingContext(_mappingContext, 0);
	}
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

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComponent->BindAction(_movementAction, ETriggerEvent::Triggered, this, &AT_Character::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AT_Character::Look);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &AT_Character::Jump);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Completed, this, &AT_Character::StopJumping);
		enhancedInputComponent->BindAction(_walkAction, ETriggerEvent::Triggered, this, &AT_Character::Walk);
		enhancedInputComponent->BindAction(_walkAction, ETriggerEvent::Completed, this, &AT_Character::Walking);
	}

	

	// IE_Pressed - 눌렀을때
	// IE_Released - 땟을떄
	//PlayerInputComponent->BindAxis("TurnCamera", this, &AT_Character::Turn);
	//PlayerInputComponent->BindAxis("LookUp", this, &AT_Character::LookUp);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AT_Character::CheckJump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &AT_Character::CheckJump);

}

void AT_Character::Move(const FInputActionValue& value)
{
	const FVector2D movementVector = value.Get<FVector2D>();

	const FRotator rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.0f, rotation.Yaw, 0.0f);

	// forward GetUnitAxis::X값은 고정
	// right GetUnitAxis::Y값은 고정
	const FVector forwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(forwardDirection, movementVector.Y);
	AddMovementInput(RightDirection, movementVector.X);

}

void AT_Character::Look(const FInputActionValue& value)
{
	const FVector2D lookAxisVector = value.Get<FVector2D>();

	AddControllerYawInput(lookAxisVector.X);
	AddControllerPitchInput(lookAxisVector.Y);

	// 위 꺼랑 동일
	//AddControllerYawInput(value.Get<FVector2D>().X);
	//AddControllerPitchInput(value.Get<FVector2D>().Y);
}

void AT_Character::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = 350.0f;
}

void AT_Character::Walking()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void AT_Character::Jump()
{
	Super::Jump();

	// 싱글모드일떄는 가능 player의 첫번째 즉 자기자신만 사용가능
	//APlayerController* PC = GetWorld()->GetFirstPlayerController();
	//if (playerController->WasInputKeyJustPressed(EKeys::AnyKey))
	//	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, TEXT("Jump"));

}

void AT_Character::StopJumping()
{
	Super::StopJumping();
}

