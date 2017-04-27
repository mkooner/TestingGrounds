// Mehrab Kooner Copyright

#pragma once

#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GrassComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UGrassComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	UGrassComponent();

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
		FBox SpawningExtents;
	UPROPERTY(EditDefaultsOnly, Category = Spawn)
		int SpawnCount;

protected:
	virtual void BeginPlay() override;
	

private:
	void SpawnGrass();
	
	
};
