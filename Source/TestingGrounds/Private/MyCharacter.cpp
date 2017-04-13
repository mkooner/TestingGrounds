// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create dynamic material anywhere u like, Constructor or anywhere .
	UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material, this, FName("Material"));
	//set paramater with Set***ParamaterValue
	//DynMaterial->SetScalarParameterValue("MyParameter", myFloatValue);
	//MyComponent1->SetMaterial(0, DynMaterial);
	//MyComponent2->SetMaterial(0, DynMaterial);
	//...
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

