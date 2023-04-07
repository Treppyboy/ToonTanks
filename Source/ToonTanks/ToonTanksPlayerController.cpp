// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("ToonTanksPlayerController initialized."));

}

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    UE_LOG(LogTemp, Warning, TEXT("The bPlayerEnabled value is %s"), (bPlayerEnabled ? TEXT("true") : TEXT("false")));

    if (bPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
        UE_LOG(LogTemp, Warning, TEXT("Player EnableInput() was called"));
    }
    else
    {
        GetPawn()->DisableInput(this);
        UE_LOG(LogTemp, Warning, TEXT("Player DisableInput() was called"));
    }
    
    bShowMouseCursor = bPlayerEnabled;
}