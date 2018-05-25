// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "GhostRunner.h"
#include "GhostRunnerCharacter.h"
#include "Spikes.h"
#include "Public/WallSpikes.h"

AGhostRunnerCharacter::AGhostRunnerCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	//SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
    FVector pos = GetActorLocation();
    zposition = pos.Z + 200.0f;
}

void AGhostRunnerCharacter::BeginPlay()
{
	ACharacter::BeginPlay();
	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGhostRunnerCharacter::OnOverlapBegin);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGhostRunnerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGhostRunnerCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AGhostRunnerCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AGhostRunnerCharacter::TouchStopped);
	PlayerInputComponent->BindAction("Ghost", IE_Pressed, this, &AGhostRunnerCharacter::Ghost);
	PlayerInputComponent->BindAction("Ghost", IE_Released, this, &AGhostRunnerCharacter::StopGhost);

}

void AGhostRunnerCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AGhostRunnerCharacter::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    
    FVector pos = GetActorLocation();
    pos.X += 1000.0f;
    pos.Z = zposition;
    SideViewCameraComponent->SetWorldLocation(pos);
    
}

void AGhostRunnerCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AGhostRunnerCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void AGhostRunnerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		ASpikes* temp1 = Cast<AWallSpikes>(OtherActor);
		ASpikes* temp = Cast<ASpikes>(OtherActor);
		if (temp1) {
			GetMesh()->SetVisibility(false);
			APlayerController* PC = Cast<APlayerController>(GetController());
			if (PC)
			{
				PC->SetCinematicMode(true, true, true);
				GetMesh()->Deactivate();

			}
		}
		if (temp) {
			// Die  
			if (!isGhosting) {
				GetMesh()->SetVisibility(false);
				APlayerController* PC = Cast<APlayerController>(GetController());
				if (PC)
				{
					PC->SetCinematicMode(true, true, true);
					GetMesh()->Deactivate();

				}
			}
			
		}
		
	}
}

void AGhostRunnerCharacter::Ghost() {
	isGhosting = true;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);

}

void AGhostRunnerCharacter::StopGhost() {
	isGhosting = false;	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Block);


}
