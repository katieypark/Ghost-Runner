// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BaseLevel.generated.h"


UCLASS(Blueprintable)
class GHOSTRUNNER_API ABaseLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Triggers")
		UBoxComponent* trigger;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Triggers")
		UBoxComponent* spawnLoc;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UBoxComponent* getTrigger();

	UBoxComponent* getSpawnLoc();
};
