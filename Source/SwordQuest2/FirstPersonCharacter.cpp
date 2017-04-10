// Fill out your copyright notice in the Description page of Project Settings.

#include "SwordQuest2.h"
#include "FirstPersonCharacter.h"


// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create a first person camera component.
    FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    // Attach the camera component to our capsule component.
    FPSCameraComponent->AttachTo(GetCapsuleComponent());

    // Position the camera slightly above the eyes.
    FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
    // Allow the pawn to control camera rotation.
    FPSCameraComponent->bUsePawnControlRotation = true;

    // Create a first person mesh component for the owning player.
    FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
    // Only the owning player sees this mesh.
    FPSMesh->SetOnlyOwnerSee(true);
    // Attach the FPS mesh to the FPS camera.
    FPSMesh->AttachTo(FPSCameraComponent);
    // Disable some environmental shadowing to preserve the illusion of having a single mesh.
    FPSMesh->bCastDynamicShadow = false;
    FPSMesh->CastShadow = false;

    // The owning player doesn't see the regular (third-person) body mesh.
    GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Set up "movement" bindings.
    InputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);

    // Set up "look" bindings.
    InputComponent->BindAxis("Turn", this, &AFirstPersonCharacter::AddControllerYawInput);
    InputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::AddControllerPitchInput);

    // Set up "action" bindings.
    InputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::StartJump);
    InputComponent->BindAction("Jump", IE_Released, this, &AFirstPersonCharacter::StopJump);

}

void AFirstPersonCharacter::MoveForward(float Value)
{
    // Find out which way is "forward" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}

void AFirstPersonCharacter::MoveRight(float Value)
{
    // Find out which way is "right" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}

void AFirstPersonCharacter::StartJump()
{
    bPressedJump = true;
}

void AFirstPersonCharacter::StopJump()
{
    bPressedJump = false;
}
