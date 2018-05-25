// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostRunner.h"
#include "../Public/BaseLevel.h"

// Sets default values
ABaseLevel::ABaseLevel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (trigger != nullptr)
	{
		trigger->bHiddenInGame = true;
	}
	//trigger->OnComponentBeginOverlap.Add(&ASpawnLevel::spawnRoom);
}

// Called when the game starts or when spawned
void ABaseLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* ABaseLevel::getTrigger()
{
	return trigger;
}

UBoxComponent* ABaseLevel::getSpawnLoc() {
	return spawnLoc;
}

