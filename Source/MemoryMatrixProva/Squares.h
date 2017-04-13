// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Squares.generated.h"

UCLASS()
class MEMORYMATRIXPROVA_API ASquares : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASquares();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AutoClick();
	void Click();
	void SetIndex(int NewIndex);
	int GetIndex();
	void SetOwnerGrid(class AGrid* Tabuleiro);



private:
	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* OpenedSprite;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* ClosedSprite;



	int Index;




	UFUNCTION()
	void OnTouchBegin(ETouchIndex::Type type, UPrimitiveComponent* TouchedComponent);


	class AGrid* OwnerGrid;
	
	void Pisca();
	FTimerHandle TempoPiscar;
};
