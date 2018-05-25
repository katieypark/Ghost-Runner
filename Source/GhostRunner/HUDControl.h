// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HUDControl.generated.h"

UCLASS()
class GHOSTRUNNER_API AHUDControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHUDControl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> WidgetTemplate;
	UPROPERTY()
		UUserWidget* WidgetInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FString tutorialText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	int score = 0;

	void AdvanceText();
	void AddScore();
	void StopScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int tutorialIndex=0;
	bool isPlayerDead=false;
	FTimerHandle tutorialTimer;
	FTimerHandle scoreTimer;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
