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
