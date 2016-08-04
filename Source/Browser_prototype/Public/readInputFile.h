// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"// header for Blueprint accecssible function class
#include "readInputFile.generated.h" // generated header for the class, must be last entry in the include block

/**
 * 
 */


UCLASS() // Macro to build Unreal class(required)
class UreadInputFile : public UBlueprintFunctionLibrary // Defines inheritance from UBluePrintFunctionLibrary class, required to expose functions to Blueprints
{
	GENERATED_BODY()
public:

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isValidFilePath(FString filepath);

		UFUNCTION(BlueprintCallable, Category = "readInputFile") // Macro to define functions called from Blueprints. Category argument defines heading for menus in Blueprint interface
			static TArray <FString> loadArrayFromFile(FString inFileName); // Defined as static to make accessible, actual function name is U + function name (e.g. UreadInputFile) in code.
		
		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static FString getFirstLine(TArray <FString> inArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isGeneModelFile(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isTrackFile(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isTransformFile(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isChipSeq(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isSNP(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isArcTrack(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static bool isNetworkFile(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static FString getTrackName(FString toParse);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static TArray<FString> getTrackInfo(FString toParse);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static FVector getEndPoint(FString toParse);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static TArray<FString> getNetwork(FString toParse);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static TArray<FVector> getGenePositions(TArray<FString> inputArray);

		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static TArray<FVector> generateGeneVectors(int32 length);
};
