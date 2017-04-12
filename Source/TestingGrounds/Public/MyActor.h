// Mehrab Kooner Copyright

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TESTINGGROUNDS_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
