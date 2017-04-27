// Mehrab Kooner Copyright

#pragma once

#include "GameFramework/GameModeBase.h"
#include "InfiniteTerrianGameMode.generated.h"

class UActorPool;
/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrianGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	AInfiniteTerrianGameMode();
	
	UFUNCTION(BlueprintCallable, Category = Bounds)
			void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
		UActorPool* VolumePool;


private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

};
