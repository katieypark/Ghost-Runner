// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Public/BaseLevel.h"
#include "SpawnLevel.generated.h"

UCLASS()
class GHOSTRUNNER_API ASpawnLevel : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnLevel();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void spawnRoom(bool isFirst);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	APawn* player;

	
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room1;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room2;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room3;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room4;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room5;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room6;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room7;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room8;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room9;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> Room10;

	

	TArray<ABaseLevel*> roomList;





};
