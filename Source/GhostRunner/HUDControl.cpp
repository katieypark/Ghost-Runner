// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostRunner.h"
#include "Blueprint/UserWidget.h"
#include "HUDControl.h"


// Sets default values
AHUDControl::AHUDControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHUDControl::BeginPlay()
{
	Super::BeginPlay();
	tutorialText = "Use WASD to move your character, and space to jump";

	if (WidgetTemplate) {
		// Create the widget and store it.
		WidgetInstance = CreateWidget<UUserWidget>(this->GetGameInstance(), WidgetTemplate);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (WidgetInstance)
		{
			//let add it to the view port
			WidgetInstance->AddToViewport();
		}
	}

	GetWorld()->GetTimerManager().SetTimer(tutorialTimer, this, &AHUDControl::AdvanceText, 3, false);
	GetWorld()->GetTimerManager().SetTimer(scoreTimer, this, &AHUDControl::AddScore, 1, false);
}

// Called every frame
void AHUDControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHUDControl::AdvanceText()
{
	++tutorialIndex;
	if (tutorialIndex == 1)
	{
		tutorialText = "Keep moving to the right to avoid the spike wall!";
		GetWorld()->GetTimerManager().SetTimer(tutorialTimer, this, &AHUDControl::AdvanceText, 3, false);
	}
	else
	{
		tutorialText = "";
	}
}

void AHUDControl::AddScore()
{
	if (!isPlayerDead)
	{
		score +=10;
		GetWorld()->GetTimerManager().SetTimer(scoreTimer, this, &AHUDControl::AddScore, 1, false);
	}
}

void AHUDControl::StopScore()
{
	isPlayerDead=true;
}