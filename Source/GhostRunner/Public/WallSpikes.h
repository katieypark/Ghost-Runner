// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Spikes.h"
#include "WallSpikes.generated.h"

/**
 * 
 */
UCLASS()
class GHOSTRUNNER_API AWallSpikes : public ASpikes
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AWallSpikes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};
