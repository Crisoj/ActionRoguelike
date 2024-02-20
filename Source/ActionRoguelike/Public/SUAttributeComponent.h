// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SUAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API USUAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USUAttributeComponent();

protected:

	// EditAnywhere - edir in BP efito and per-instance in level.
	// VisibleAnywhere - 'read-only' in editor and level. (Use for components)
	// EditDefaultOnly - hide variables per-instance, edit in BP editor only
	// VisibleDefaultsOnly - 'read-only' acces for variable, only in BP editor (uncommon)
	// EditInstanceOnly - allow only editing of instance (eg. when placed in level)
	// --
	// BlueprintReadOnly - read-only in the Blueprint scritpting (does not affect 'details'-panel)
	// BlueprintReadWrite - read-write access in Blueprints
	// --
	// Category = "" - display only for detail panel and blueprint context menu.

	UPROPERTY(EditDefaultOnly, BlueprintReadOnly, Category = "Attribures")
	float Health;

	// HealtMax, Stamina, Strength

	

public:	

	UFUNCTION(BlueprintCallable, category = "Attributes")
	bool ApplyHealthChange(float Delta);



		
};
