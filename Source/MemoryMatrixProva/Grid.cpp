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



}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();

	float LocationX = 0.0f;
	float LocationZ = 0.0f;

	




	UWorld* World = GetWorld();

	if (World != nullptr) {
		for (int i = 1; i < ((MatrixCol*MatrixRow)+1); i++) {
			FActorSpawnParameters SpawnParameters;
			ASquares* Square = World->SpawnActor<ASquares>(Quad, FVector(LocationX, 0, LocationZ), FRotator::ZeroRotator, SpawnParameters);
			Square->SetIndex(0);
			LocationX += 110.0f;
			
			
			
			if ( i % MatrixCol  == 0 ) {
				LocationZ -= 110.0f;
				LocationX = 0;
			}
		}
	}
	
	ViraQuadrado();

	
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrid::ViraQuadrado() {

		int Rand = FMath::RandRange(1, MatrixCol*MatrixRow);
		
		void Click();

	
}

void AGrid::NovoLevel() {
	LevelCont++ ;
	
	if (LevelCont % 2 == 0) {
		MatrixCol = MatrixCol + 1;
	}else{ 
		MatrixRow = MatrixRow + 1;
	}
		
}