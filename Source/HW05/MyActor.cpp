#include "MyActor.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
    start = FVector2D(0.0f, 0.0f);
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Actor Spawned at (%.0f, %.0f)"), start.X, start.Y);

    move();
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

int32 AMyActor::step()
{
    return FMath::RandRange(0, 1);
}

void AMyActor::move()
{
    for (int32 i = 0; i < 10; ++i)
    {
        int32 stepX = step();
        int32 stepY = step();

        float nextX = start.X + stepX;
        float nextY = start.Y + stepY;

        // x, y 둘 다 2 이상이면 이동 불가
        if (nextX >= 2.0f && nextY >= 2.0f)
        {
            UE_LOG(LogTemp, Warning, TEXT("Cannot move to (%.0f, %.0f) - Both coordinates exceed 2"), nextX, nextY);
            continue;
        }

        start.X = nextX;
        start.Y = nextY;

        UE_LOG(LogTemp, Warning, TEXT("Moved to (%.0f, %.0f)"), start.X, start.Y);
    }
}
