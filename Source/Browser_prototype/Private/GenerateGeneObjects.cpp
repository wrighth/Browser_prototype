// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
#include "CString.h"
#include "GenerateGeneObjects.h"

TArray<FVector> UGenerateGeneObjects::generateObjectPosition(FString toParse)
{

	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	TArray<float> farr;

	int i = 0;
	while (i < forsplit.Num())
	{
		farr.Push(FCString::Atof(*forsplit[i]));
		++i;
	}

	TArray<FVector> retarr;
	retarr.Push(FVector(farr[0], farr[1], farr[2]));
	retarr.Push(FVector(farr[3], farr[4], farr[5]));
	retarr.Push(FVector(farr[6], farr[7], farr[8]));

	return retarr;

}

float UGenerateGeneObjects::generateOffset(float boxExtent, float scale0, float scale1, float scale2)
{

	return (boxExtent) * (scale1 / scale0) + (boxExtent * scale2 / scale0);

}

TArray<float> UGenerateGeneObjects::generateSegmentVector(FString toParse)
{

	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	TArray<float> farr;
	FString commasplit = forsplit[9];
	FString commadelim = ",";
	commasplit.ParseIntoArrayWS(forsplit, *commadelim);

	int i = 0;
	while (i < forsplit.Num())
	{
		farr.Push(FCString::Atof(*forsplit[i]));
		++i;
	}

	return farr;

}

TArray<FString> UGenerateGeneObjects::generateInfo(FString toParse) {

	TArray<FString> forSplit;
	toParse.ParseIntoArrayWS(forSplit, NULL);

	TArray<FString> retArray;
	retArray.Push(forSplit[13]);
	retArray.Push(forSplit[12]);
	retArray.Push(forSplit[11]);
	retArray.Push(forSplit[10]);

	return retArray;

}