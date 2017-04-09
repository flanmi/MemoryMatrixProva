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

	
	void Click();
	void SetIndex(int NewIndex);
	int GetIndex();

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

	void Pisca();
	FTimerHandle TempoPiscar;
};
