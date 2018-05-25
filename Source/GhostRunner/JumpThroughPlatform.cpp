// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostRunner.h"
#include "JumpThroughPlatform.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>


// Sets default values for this component's properties
UJumpThroughPlatform::UJumpThroughPlatform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJumpThroughPlatform::BeginPlay()
{
	Super::BeginPlay();
	player = UGameplayStatics::GetPlayerPawn(this,0);
	// ...
	GetOwner()->FindComponentByClass<UPrimitiveComponent>()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
}


// Called every frame
void UJumpThroughPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
	float distance = (player->GetTransform().GetLocation().Z + minJumpHeight)- GetOwner()->GetTransform().GetLocation().Z;

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, (distance>0) ? FColor::Green : FColor::Red, FString::Printf(TEXT("Distance: %f"), player->GetVelocity().Z));
	if (distance >0  && player->GetVelocity().Z > 450)
	{
		GetOwner()->FindComponentByClass<UPrimitiveComponent>()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Block);
	}
	else if (distance<=0)
	{
		GetOwner()->FindComponentByClass<UPrimitiveComponent>()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	}
}

