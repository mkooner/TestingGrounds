// Mehrab Kooner Copyright

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()
	
	FVector SpawnPoint; 
	float Rotation; 
	float Scale;

};


class UActorPool;
class AMyCharacter;

UCLASS()
class TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
		FVector NavOffSet;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Input)
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);

	UFUNCTION(BlueprintCallable, Category = Input)
		void PlaceAIPawns(TSubclassOf<AMyCharacter> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500);

	UFUNCTION(BlueprintCallable, Category = Pool)
		void SetPool(UActorPool* PoolToSet);

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	FVector Min;
	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	FVector Max;

private:
	bool CastSphere(FVector Location, float Radius);
	bool FindEmptyLocation(FVector& Location, float Radius);
	void PlaceActorsInScene(TSubclassOf<AActor>  ToSpawn, FSpawnPosition SpawnPosition);
	TArray<FSpawnPosition> RandomSpawning(int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale);
	UActorPool* Pool;
	void PostionNavMesh();
	AActor* NavMeshBoundsVolume;
};
