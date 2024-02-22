// Fill out your copyright notice in the Description page of Project Settings.


#include "SUMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "SUAttributeComponent.h"

// Sets default values
ASUMagicProjectile::ASUMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	/*
	SphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	*/
	SphereComp->SetCollisionProfileName("Projectile");
<<<<<<< HEAD
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASUMagicProjectile::OnActorOverlap);
=======
>>>>>>> parent of 1fd2175 (added new things)
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;

}

void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) 
	{
		USUAttributeComponent* AttributeComp = Cast<USUAttributeComponent>(OtherActor->GetComponentByClass(USUAttributeComponent::StaticClass()));
		if (AttributeComp) 
		{
			AttributeComp->ApplyHealthChange(-20.0f);

			bool Destroy();
		}
	}
}

// Called when the game starts or when spawned
void ASUMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

