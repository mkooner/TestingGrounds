// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "GrassComponent.h"

UGrassComponent::UGrassComponent()
{

}

void UGrassComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnGrass();

}

void UGrassComponent::SpawnGrass()
{
	for (size_t i = 0; i < SpawnCount; i++)
	{
		FVector Location = FMath::RandPointInBox(SpawningExtents);
		AddInstance(FTransform(Location));
	}
}