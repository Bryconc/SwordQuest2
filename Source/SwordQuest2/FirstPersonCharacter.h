// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class SWORDQUEST2_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    // Handles input for moving forward and backward.
    UFUNCTION()
        void MoveForward(float Value);

    // Handles input for moving right and left.
    UFUNCTION()
        void MoveRight(float Value);

    // Sets jump flag when key is pressed.
    UFUNCTION()
        void StartJump();

    // Clears jump flag when key is released.
    UFUNCTION()
        void StopJump();

    // FPS camera.
    UPROPERTY(EditAnywhere)
        UCameraComponent* FPSCameraComponent;

    // First-person mesh (arms), visible only to the owning player.
    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
        USkeletalMeshComponent* FPSMesh;
	
};
