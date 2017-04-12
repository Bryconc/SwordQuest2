// Fill out your copyright notice in the Description page of Project Settings.

#include "SwordQuest2.h"
#include "ResourceCharacterBase.h"


// Sets default values
AResourceCharacterBase::AResourceCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AResourceCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResourceCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AResourceCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

