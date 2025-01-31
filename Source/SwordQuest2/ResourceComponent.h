// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "ResourceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SWORDQUEST2_API UResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UResourceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        UAnimMontage* AttackAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        UAnimMontage* DeathAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        USoundBase* AgroAudio;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        float AttackDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        float MinimumAttackDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        float MaximumAttackDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        UWidgetComponent* HealthWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        UChildActorComponent* Weapon1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
        UChildActorComponent* Weapon2;
	
};
