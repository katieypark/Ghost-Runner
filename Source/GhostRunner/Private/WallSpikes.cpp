// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostRunner.h"
#include "../Public//WallSpikes.h"

AWallSpikes::AWallSpikes()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallSpikes::BeginPlay()
{
	Super::BeginPlay();
	this->GetRootComponent()->ComponentVelocity = FVector(0, 25, 0);
}

// Called every frame
void AWallSpikes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(0, -350 * DeltaTime, 0), true);
	//AddActorLocalOffset(FVector(0, -100*DeltaTime, 0), true);
}

