// Mehrab Kooner Copyright

#pragma once

#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorPool();

protected:
	// Called when the game starts

public:	
	// Public Interface
	AActor* Checkout();
	void Return(AActor* ActorToReturn);
	void Add(AActor* ActorToAdd);
	
};
