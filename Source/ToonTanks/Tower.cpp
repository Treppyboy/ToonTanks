// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    DrawDebugSphere(GetWorld(), GetActorLocation(), FireRange, 24, FColor::Red, false, -1.0f);

    if (Tank)
    {
        // find distance to the tank
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        // check to see if tank is in range
        if (Distance <= FireRange)
        {
            RotateTurret(Tank-> GetActorLocation());
        }
        
    }
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}
