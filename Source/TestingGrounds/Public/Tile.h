// Mehrab Kooner Copyright

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Input)
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);

	UFUNCTION(BlueprintCallable, Category = Pool)
		void SetPool(UActorPool* PoolToSet);

private:
	bool CastSphere(FVector Location, float Radius);
	bool FindEmptyLocation(FVector& Location, float Radius);
	void PlaceActorsInScene(TSubclassOf<AActor>  ToSpawn, FVector SpawnPoint, float Rotation, float Scale);
	UActorPool* Pool;
};
