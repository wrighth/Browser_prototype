// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h" //header file for project
#include "CoreMisc.h"	//header file for FFileHelper
#include "CString.h"
#include "../Public/readInputFile.h" //header file for class
#include <string>

using namespace std;

TArray <FString> UreadInputFile::loadArrayFromFile(FString inFileName)
{
	TArray <FString> retstrings; //define return array
	const TCHAR* MyTCharArray = *inFileName; //gets character array from FString input argument
	FFileHelper::LoadANSITextFileToStrings(MyTCharArray, NULL, retstrings); //Reads file to retstring array, needs error checking implemented
	return retstrings;//return object
}

FString UreadInputFile::getFirstLine(TArray<FString> inArray)
{
	return inArray[0];
}

bool UreadInputFile::isChipSeq(TArray<FString> inputArray)
{
	TArray<FString> secondLineArray;
	inputArray[1].ParseIntoArrayWS(secondLineArray, NULL);
	
	if (secondLineArray[3].Contains(TEXT("."))) {
		return true;
	} 
	else {
		return false;
	}
}

bool UreadInputFile::isSNP(TArray<FString> inputArray)
{
	TArray<FString> secondLineArray;
	inputArray[1].ParseIntoArrayWS(secondLineArray, NULL);
	FString testChar = secondLineArray[3];

	if (testChar == "A" || testChar == "C" || testChar == "G" || testChar == "T") {
		return true;
	} else {
		return false;
	}
}

FString UreadInputFile::getTargetName(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	return forsplit[0];
}

int32 UreadInputFile::getFeatureStart(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	int32 retInt = FCString::Atoi(*forsplit[1]);
	return retInt;
}

int32 UreadInputFile::getFeatureEnd(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	int32 retInt = FCString::Atoi(*forsplit[2]);
	return retInt;
}

float UreadInputFile::getFeatureHeight(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	float retFloat = FCString::Atof(*forsplit[3]);
	return retFloat;
}

FString UreadInputFile::getBase(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	FString retString = forsplit[3];
	return retString;
}

FString UreadInputFile::getSiteName(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	FString retString = forsplit[3];
	return retString;
}

TArray <FString> UreadInputFile::getNetwork(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	return forsplit;
}