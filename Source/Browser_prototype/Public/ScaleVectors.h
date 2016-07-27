// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScaleVectors.generated.h"

/**
 * 
 */
UCLASS()
class BROWSER_PROTOTYPE_API UScaleVectors : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "ScaleVectors")
		static TArray<float> scaleSmallest(TArray<float> inputArray);

	UFUNCTION(BlueprintCallable, Category = "ScaleVectors")
		static TArray<float> scaleMedian(TArray<float> inputArray);
	
	
};
