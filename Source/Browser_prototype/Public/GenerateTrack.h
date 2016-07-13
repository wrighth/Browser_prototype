// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenerateTrack.generated.h"

UCLASS()
class BROWSER_PROTOTYPE_API AChipSeqTrack : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AChipSeqTrack();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static float generateFeatureScaleLength(int32 geneStart, int32 geneEnd, int32 featureStart, int32 featureEnd);

	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static float generateXDisplacement(int32 geneStart, int32 geneEnd, float absGeneLength, int32 featureStart, int32 featureEnd);
	
	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static bool isCorrectModel(int32 geneStart, int32 geneEnd, int32 featureStart, int32 featureEnd);

	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static TArray<FString> generateChipSeqInfoArray(FString targetChr, FString featureStart, FString featureEnd, FString featureHeight, FString trackName);

	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static TArray<FString> generateSNPInfoArray(FString targetChr, FString geneName, FString position, FString base, FString trackName);

	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static TArray<FString> generateTranscriptionSiteInfoArray(FString targetChr, FString geneName, FString positionRange, FString name, FString trackName);

	UFUNCTION(BlueprintCallable, Category = "GenerateTrack")
		static TArray<FString> generateArcInfoArray(FString targetChr, FString geneName, FString startRange, FString endRange, FString trackName);
};
