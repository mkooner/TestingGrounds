// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AActor* UActorPool::Checkout()
{
	if(Pool.Num() == 0)
	{ return nullptr; }

	return Pool.Pop();
}

void UActorPool::Return(AActor* ActorToReturn)
{
	if(ActorToReturn == nullptr)
	{ return; }

	Pool.Push(ActorToReturn);

}

void UActorPool::Add(AActor* ActorToAdd)
{
	Return(ActorToAdd);
}

