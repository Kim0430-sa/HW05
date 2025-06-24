#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class YOURPROJECT_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // FVector2D를 UPROPERTY로 선언 (디버깅 또는 블루프린트 노출을 위해 권장)
    FVector2D start;

    int32 step();
    void move();
};
