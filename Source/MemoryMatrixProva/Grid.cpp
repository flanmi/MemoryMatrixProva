// Fill out your copyright notice in the Description page of Project Settings.

#include "MemoryMatrixProva.h"
#include "Grid.h"
#include "Squares.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"
#include "MatrixPawn.h"

// Sets default values
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ConstructorHelpers::FObjectFinder<UBlueprint> QuadBP(TEXT("Blueprint'/Game/BluePrints/SquaresBP.SquaresBP'"));
	if (QuadBP.Succeeded()) {
		Quad = Cast<UClass>(QuadBP.Object->GeneratedClass);
	}


	ConstructorHelpers::FClassFinder<UUserWidget> Widget(TEXT("WidgetBlueprint'/Game/BluePrints/GameOverBP.GameOverBP_C'"));
	if (Widget.Succeeded()) {
		GameOverWidget = Widget.Class;
	}
}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();

	
	

	Tabuleiro();
	
	ViraQuadrado();
	/*for (int i = 0; i < 10; i++)
	{
		NovoLevel();
	}*/
	
	
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGrid::Tabuleiro() {

	UWorld* World = GetWorld();

	if (World != nullptr) {
		for (int i = 1; i < ((MatrixCol*MatrixRow) + 1); i++) {
			FActorSpawnParameters SpawnParameters;
			ASquares* Square = World->SpawnActor<ASquares>(Quad, FVector(LocationX, 0, LocationZ), FRotator::ZeroRotator, SpawnParameters);
			Square->SetIndex(0);
			Posicao.Add(i);
			Square->SetOwnerGrid(this);
			Quadrados.Add(Square);
			LocationX += 110.0f;
			
			if (i % MatrixCol == 0) {
				LocationZ -= 110.0f;
				LocationX = 0;
			}
		}
	}
}



void AGrid::ViraQuadrado() {
		
		for (int i = 0; i < Sequencia; i++) {
			int Rand = FMath::RandRange(0, (MatrixCol*MatrixRow)-1);
			Quadrados[Rand]->AutoClick();
			Quadrados[Rand]->SetIndex(1);
		}
					
}





void AGrid::NovoLevel() {
	LevelCont++ ;
	Sequencia++;
	LocationZ = 0.0f;
	NumCLicks = 0;
	Quadrados.Empty();

	UWorld* World = GetWorld();
	if (World) {
		APawn* Pawn = UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn();
		AMatrixPawn* MatrixPawn = Cast<AMatrixPawn>(Pawn);
		MatrixPawn->SetScore(MatrixPawn->GetScore() + 1);
	}

	if (LevelCont % 2 == 0) {
		MatrixCol = MatrixCol + 1;
	}else{ 
		MatrixRow = MatrixRow + 1;
	}
	
	Tabuleiro();
	ViraQuadrado();


}

void AGrid::Verificar(class ASquares* Click) {
	if (Click->GetIndex() == 1 ) {

		NumCLicks++;
		if (NumCLicks == Sequencia) {
			NovoLevel();
		}

	}
	else {
		GameOver();
		UE_LOG(LogTemp, Warning, TEXT("GAME OVER!"));
	}


}

void AGrid::GameOver() {
	UWorld* World = GetWorld();
	if (World) {
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
		if (PlayerController && GameOverWidget != NULL) {
			PlayerController->SetPause(true);
			UUserWidget* UserW = UWidgetBlueprintLibrary::Create(World, GameOverWidget, PlayerController);
			if (UserW) {
				UserW->AddToViewport();
			}
		}
	}
}