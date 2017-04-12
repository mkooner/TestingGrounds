// Mehrab Kooner Copyright

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolRoute();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Route")
		TArray<AActor*> PatrolPointsCpp;



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<AActor*> GetPatrolPoints();
	
};
