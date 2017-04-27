// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "InfiniteTerrianGameMode.h"
#include "TestingGroundsHUD.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrianGameMode::AInfiniteTerrianGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Lion/Lion_Character_BP"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundsHUD::StaticClass();

	VolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Pool"));

}

void AInfiniteTerrianGameMode::PopulateBoundsVolumePool()
{

	TActorIterator<ANavMeshBoundsVolume> VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());

	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}

}

void AInfiniteTerrianGameMode::AddToPool(ANavMeshBoundsVolume *VolumeToAdd)
{
	VolumePool->Add(VolumeToAdd);
	UE_LOG(LogTemp, Warning, TEXT("Found ->%s"), *VolumeToAdd->GetName());

}