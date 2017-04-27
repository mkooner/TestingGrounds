// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "Tile.h"
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
#include "ActorPool.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale)
{
	if(ToSpawn == nullptr)
	{ return; }


	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);

	for (size_t i = 0; i < NumberToSpawn; i++)
	{		
		FVector SpawnPoint;
		float RandomScale = FMath::RandRange(MinScale, MaxScale);
		if (FindEmptyLocation(SpawnPoint, Radius * RandomScale))
		{
			PlaceActorsInScene(ToSpawn, SpawnPoint, FMath::RandRange(-180.0f,180.f), RandomScale);
		}
		//FVector SpawnPoint = FMath::RandPointInBox(Bounds);
		
	}
}

void ATile::SetPool(UActorPool* PoolToSet)
{
	Pool = PoolToSet;
}

bool ATile::FindEmptyLocation(FVector& Location, float Radius)
{
	FVector Min = FVector(0, -2000, 0);
	FVector Max = FVector(4000, 2000, 0);
	FBox Bounds = FBox(Min, Max);
	
	FVector SpawnPoint;
	bool Hit;

	
	for(size_t i = 0; i < 100; i++)
	{
		SpawnPoint = FMath::RandPointInBox(Bounds);
		Hit = CastSphere(SpawnPoint, Radius);

		if(Hit)
		{
			Location = SpawnPoint;
			return true;
		}

	}

	return  false;
}

void ATile::PlaceActorsInScene(TSubclassOf<AActor>  ToSpawn, FVector SpawnPoint, float Rotation, float Scale)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	Spawned->SetActorRotation(FRotator(0, Rotation, 0));
	Spawned->SetActorScale3D(FVector(Scale));
}

bool ATile::CastSphere(FVector Location, float Radius)
{
	FHitResult HitResult;

	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);

	bool Hit = GetWorld()->SweepSingleByChannel(HitResult, GlobalLocation, GlobalLocation, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel2, FCollisionShape::MakeSphere(Radius));
	
	FColor ResultColor = Hit ? FColor::Red : FColor::Green;

	//DrawDebugSphere(GetWorld(), Location, Radius, 100, ResultColor, true, 100);
	
	return !Hit;
}