// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostRunner.h"
#include "RealSpawner.h"


// Sets default values
ARealSpawner::ARealSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARealSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARealSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

