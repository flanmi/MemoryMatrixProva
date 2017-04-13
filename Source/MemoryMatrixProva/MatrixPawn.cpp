// Fill out your copyright notice in the Description page of Project Settings.

#include "MemoryMatrixProva.h"
#include "MatrixPawn.h"
#include "Grid.h"

// Sets default values
AMatrixPawn::AMatrixPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(RootComponent);	

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AMatrixPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMatrixPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Score = 0;
}

// Called to bind functionality to input
void AMatrixPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Lvup", IE_Pressed, this, &AMatrixPawn::Lvup);

}

void AMatrixPawn::SetScore(int NewScore) {
	Score = NewScore;
}

int AMatrixPawn::GetScore() {
	return Score;
}



/*void AMatrixPawn::Lvup() {
	UWorld* World = GetWorld();

	if (World != nullptr) {

		AGrid* Pawn = Cast <AGrid>(UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn());
		Pawn->NovoLevel();

	}
}*/
