// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostRunner.h"
#include "SpawnLevel.h"
#include "Engine.h"


// Sets default values
ASpawnLevel::ASpawnLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnLevel::BeginPlay()
{
	Super::BeginPlay();
	player = UGameplayStatics::GetPlayerPawn(this, 0);
	spawnRoom(true);
	spawnRoom(false);
	spawnRoom(false);
	spawnRoom(false);

	
}

// Called every frame
void ASpawnLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ASpawnLevel::spawnRoom(bool isFirst) {

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spawned Room"));

	//Get the right loc for the room to be spawned (Should be TriggerLoc)
	
	FVector Location(1200.0f, -2480.0f, 180.0f);
	FRotator Rotation(0, -90, 0);
	FActorSpawnParameters SpawnInfo;

	if (!isFirst) {
		ABaseLevel* lastRoom = roomList.Last();
		Location = lastRoom->getSpawnLoc()->GetComponentTransform().GetTranslation();
	}


	//Spawn a new room
	//AActor* temproom = GetWorld()->SpawnActor(ABaseLevel::StaticClass(), new FVector(0.0f, 0.0f, 0.0f));

	int x = FMath::RandRange(1, 10);
	ABaseLevel* room = nullptr;
	if (x == 1) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room1, Location, Rotation, SpawnInfo);
	}
	else if (x == 2) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room2, Location, Rotation, SpawnInfo);
	}
	else if (x == 3) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room3, Location, Rotation, SpawnInfo);
	}
	else if (x == 4) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room4, Location, Rotation, SpawnInfo);
	}
	else if (x == 5) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room5, Location, Rotation, SpawnInfo);
	}
	else if (x == 6) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room6, Location, Rotation, SpawnInfo);
	}
	else if (x == 7) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room7, Location, Rotation, SpawnInfo);
	}
	else if (x == 8) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room8, Location, Rotation, SpawnInfo);
	}
	else if (x == 9) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room9, Location, Rotation, SpawnInfo);
	}
	else if (x == 10) {
		room = GetWorld()->SpawnActor<ABaseLevel>(Room10, Location, Rotation, SpawnInfo);
	}


	
	
	
	// set up a notification for when this component overlaps something
	if (room) {
		if (room->getTrigger()) {
                         
			room->getTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpawnLevel::OnBeginOverlap);
		}
		
		

				
	}

	
	//Add it to the list
	roomList.Add(room);
	if (roomList.Num() > 5) {
		roomList.RemoveAt(0);
	}
}



void ASpawnLevel::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	spawnRoom(false);
}

