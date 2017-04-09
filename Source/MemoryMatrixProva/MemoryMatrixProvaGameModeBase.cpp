// Fill out your copyright notice in the Description page of Project Settings.

#include "MemoryMatrixProva.h"
#include "MemoryMatrixProvaGameModeBase.h"
#include "MatrixPlayerController.h"




AMemoryMatrixProvaGameModeBase::AMemoryMatrixProvaGameModeBase() {
	PlayerControllerClass = AMatrixPlayerController::StaticClass();
}


