// Fill out your copyright notice in the Description page of Project Settings.


#include "SUAttributeComponent.h"

// Sets default values for this component's properties
USUAttributeComponent::USUAttributeComponent()
{
	Health = 100;
}

bool USUAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;

	return true;
}



