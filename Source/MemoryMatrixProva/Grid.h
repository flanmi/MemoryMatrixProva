// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class MEMORYMATRIXPROVA_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NovoLevel();


private:
	
	UPROPERTY(EditAnywhere)
		USceneComponent* Root;
	TSubclassOf<class ASquares> Quad;
	
	int MatrixCol = 3;
	int MatrixRow = 3;

	int LevelCont = 1;
	
	void ViraQuadrado();
	//void NovoLevel();



};
