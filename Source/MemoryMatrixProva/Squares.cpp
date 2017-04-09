// Fill out your copyright notice in the Description page of Project Settings.

#include "MemoryMatrixProva.h"
#include "Squares.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Grid.h"


// Sets default values
ASquares::ASquares()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetSprite(ClosedSprite);
	Sprite->OnInputTouchBegin.AddDynamic(this, &ASquares::OnTouchBegin);
	RootComponent = Sprite;

}

// Called when the game starts or when spawned
void ASquares::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquares::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ASquares::Click() {
	if (Sprite->GetSprite() == (ClosedSprite)) {
		Sprite->SetSprite(OpenedSprite);
	}


}

void ASquares::SetIndex(int NewIndex) {
	Index = NewIndex;
}

int ASquares::GetIndex() {
	return Index;
}


void ASquares::OnTouchBegin(ETouchIndex::Type type, UPrimitiveComponent* TouchedComponent) {

	UE_LOG(LogTemp, Warning, TEXT("It works!"));
	UWorld* World = GetWorld();
	if (World != nullptr) {

		
		Click();

		GetWorldTimerManager().SetTimer(TempoPiscar, this,	&ASquares::Pisca, 0.5f, true);
		
		


	}

}


void ASquares::Pisca() {
	Sprite->SetSprite(ClosedSprite);
	GetWorldTimerManager().ClearTimer(TempoPiscar);
}