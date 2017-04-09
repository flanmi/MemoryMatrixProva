// Fill out your copyright notice in the Description page of Project Settings.

#include "MemoryMatrixProva.h"
#include "MatrixPlayerController.h"



AMatrixPlayerController::AMatrixPlayerController() {
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	bEnableTouchEvents = true;
}