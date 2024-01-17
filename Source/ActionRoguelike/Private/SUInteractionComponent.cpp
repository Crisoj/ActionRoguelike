// Fill out your copyright notice in the Description page of Project Settings.

#include "SUInteractionComponent.h"
#include "SUGameplayInterface.h"

// Sets default values for this component's properties
USUInteractionComponent::USUInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USUInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USUInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USUInteractionComponent::PrimaryInteract() 
{
	FCollisionObjectQueryParams  objectQueryParams;
	objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();

	//FVector Start;
	
	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
	
	FVector End = EyeLocation + (EyeRotation.Vector() * 1000);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, objectQueryParams);

	AActor* HitActor = Hit.GetActor();
	if (HitActor) 
	{
		if (HitActor->Implements<USUGameplayInterface>())
		{
			APawn* MyPawn = Cast<APawn>(MyOwner);

			ISUGameplayInterface::Execute_Interact(HitActor, MyPawn);
		}
	}
}