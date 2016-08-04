// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
#include "GenerateTrack.h"


// Sets default values
AChipSeqTrack::AChipSeqTrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChipSeqTrack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChipSeqTrack::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

float AChipSeqTrack::generateFeatureScaleLength(int32 geneStart, int32 geneEnd, int32 featureStart, int32 featureEnd) 
{
	float geneLength = geneEnd - geneStart;
	float featureLength = featureEnd - featureStart;
	float lengthRatio = featureLength / geneLength;
	return lengthRatio;
}

float AChipSeqTrack::generateXDisplacement(int32 geneStart, int32 geneEnd, float absGeneLength, int32 featureStart, int32 featureEnd)
{
	float bpLength = geneEnd - geneStart;
	float realBPRatio = absGeneLength / bpLength;

	float featureMiddle = (featureStart + featureEnd) / 2;
	float geneMiddle = (geneStart + geneEnd) / 2;
	float geneToFeature = featureMiddle - geneMiddle;
	float xDisplacement = geneToFeature * realBPRatio;
	return xDisplacement;
}

bool AChipSeqTrack::isCorrectModel(int32 geneStart, int32 geneEnd, int32 featureStart, int32 featureEnd)
{
	if (geneStart <= featureStart) {
		if (geneEnd >= featureEnd) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

TArray<FString> AChipSeqTrack::generateChipSeqInfoArray(FString targetChr, FString featureStart, FString featureEnd, FString featureHeight, FString trackName) 
{
	TArray<FString> returnArray;

	returnArray.Add(targetChr);
	returnArray.Add("Feature Start: " + featureStart);
	returnArray.Add("Feature End: " + featureEnd);
	returnArray.Add("Feature Height: " + featureHeight);
	returnArray.Add(trackName);

	return returnArray;
}

TArray<FString> AChipSeqTrack::generateSNPInfoArray(FString targetChr, FString geneName, FString position, FString base, FString trackName)

{
	TArray<FString> returnArray;

	returnArray.Add(targetChr);
	returnArray.Add("On Gene: " + geneName);
	returnArray.Add("At Position: " + position);
	returnArray.Add("Base Pair: " + base);
	returnArray.Add(trackName);

	return returnArray;
}

TArray<FString> AChipSeqTrack::generateTranscriptionSiteInfoArray(FString targetChr, FString geneName, FString positionRange, FString name, FString trackName)

{
	TArray<FString> returnArray;

	returnArray.Add(targetChr);
	returnArray.Add("On Gene: " + geneName);
	returnArray.Add("Site Position: " + positionRange);
	returnArray.Add("Name: " + name);
	returnArray.Add(trackName);

	return returnArray;
}

TArray<FString> AChipSeqTrack::generateArcInfoArray(FString targetChr, FString geneName, FString startRange, FString endRange, FString trackName)
{
	TArray<FString> returnArray;

	returnArray.Add(geneName);
	returnArray.Add("On chromosome: " + targetChr);
	returnArray.Add("Arc start: " + startRange);
	returnArray.Add("Arc end: " + endRange);
	returnArray.Add(trackName);

	return returnArray;
}