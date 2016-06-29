// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
#include "ChipSeqTrack.h"


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
	float geneToFeature = featureMiddle - geneStart;
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