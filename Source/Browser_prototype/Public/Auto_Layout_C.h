// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Auto_Layout_C.generated.h"

UCLASS()
class UAuto_Layout_C : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "AutoLayout")
		static TArray<FString> sortGenesAlphabetically(TArray<FString> unsortedNames);

	UFUNCTION(BlueprintCallable, Category = "AutoLayout")
		static TArray<FVector> getAlphabeticalVectors(TArray<FString> sortedNames);

	UFUNCTION(BlueprintCallable, Category = "AutoLayout")
		static TArray<int32> sortUnsortedInts(TArray<int32> unsortedInts);

	UFUNCTION(BlueprintCallable, Category = "AutoLayout")
		static TArray<FString> matchGeneNames(TArray<int32> unsortedInts, TArray<int32> sortedInts, TArray<FString> geneNames);

	UFUNCTION(BlueprintCallable, Category = "AutoLayout")
		static TArray<FVector> generateConnectivityLocations(TArray<int32> sortedInts);

};
