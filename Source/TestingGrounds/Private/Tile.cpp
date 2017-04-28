// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "Tile.h"
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
#include "ActorPool.h"
#include "MyCharacter.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NavOffSet = FVector(2000, 0, 0);
	Min = FVector(0, -2000, 0);
	Max = FVector(4000, 2000, 0);
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();

}

// Called when the game ends
void ATile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Pool->Return(NavMeshBoundsVolume);
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

	TArray<FSpawnPosition> SpawnPositions = RandomSpawning(MinSpawn, MaxSpawn, Radius, MinScale, MaxScale);

	for (FSpawnPosition Spawn : SpawnPositions)
	{
		PlaceActorsInScene(ToSpawn, Spawn);
	}
}

void ATile::PlaceAIPawns(TSubclassOf<AMyCharacter> ToSpawn, int MinSpawn, int MaxSpawn, float Radius)
{
	if (ToSpawn == nullptr)
	{  return;	}

	TArray<FSpawnPosition> SpawnPositions = RandomSpawning(MinSpawn, MaxSpawn, Radius, 1.0f, 1.0f);
	for (FSpawnPosition Spawn : SpawnPositions)
	{
		AMyCharacter* Spawned = GetWorld()->SpawnActor<AMyCharacter>(ToSpawn);
		Spawned->SetActorRelativeLocation(Spawn.SpawnPoint + FVector(0,0,500.0f));
		Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		Spawned->SetActorRotation(FRotator(0, Spawn.Rotation, 0));
		Spawned->SpawnDefaultController();
		Spawned->Tags.Add(FName("Enemy"));
		Spawned->Death();
	}
}

TArray<FSpawnPosition> ATile::RandomSpawning(int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale)
{

	TArray<FSpawnPosition> SpawnPositions;


	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);

	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FSpawnPosition Spawn;
		Spawn.Scale = FMath::RandRange(MinScale, MaxScale);
		if (FindEmptyLocation(Spawn.SpawnPoint, Radius * Spawn.Scale))
		{
			Spawn.Rotation = FMath::RandRange(-180.0f, 180.0f);
			SpawnPositions.Add(Spawn);
		}
		//FVector SpawnPoint = FMath::RandPointInBox(Bounds);

	}
	return SpawnPositions;
}

void ATile::SetPool(UActorPool* PoolToSet)
{
	Pool = PoolToSet;
	PostionNavMesh();

}

void ATile::PostionNavMesh()
{
	NavMeshBoundsVolume = Pool->Checkout();
	
	if(NavMeshBoundsVolume == nullptr)
	{ return; }


	NavMeshBoundsVolume->SetActorLocation(GetActorLocation() + NavOffSet);
	GetWorld()->GetNavigationSystem()->Build();
}

bool ATile::FindEmptyLocation(FVector& Location, float Radius)
{
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

void ATile::PlaceActorsInScene(TSubclassOf<AActor>  ToSpawn, FSpawnPosition SpawnPosition)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPosition.SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	Spawned->SetActorRotation(FRotator(0, SpawnPosition.Rotation, 0));
	Spawned->SetActorScale3D(FVector(SpawnPosition.Scale));
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