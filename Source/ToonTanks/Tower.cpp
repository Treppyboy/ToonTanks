// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //DrawDebugSphere(GetWorld(), GetActorLocation(), FireRange, 24, FColor::Red, false, -1.0f);


    if (InFireRange())
    {
        RotateTurret(Tank -> GetActorLocation());
    }
    
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
    FireRate = FMath::RandRange(0.5f, 5.0f);

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
    
    if (InFireRange())
    {
        Fire();
    }

}

bool ATower::InFireRange()
{
    if (Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank-> GetActorLocation());

        if (Distance <= FireRange)
        {
            return true;
        }
        
    }

    return false;
    
}
