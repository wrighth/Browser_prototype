// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenerateGeneObjects.generated.h"

/**
 * 
 */
UCLASS()
class BROWSER_PROTOTYPE_API UGenerateGeneObjects : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "GenerateGeneObjects")
		static TArray <FVector> generateObjectPosition(FString toParse);
	
	
	
};
