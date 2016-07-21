// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h" //header file for project
#include "CoreMisc.h"	//header file for FFileHelper
#include "CString.h"
#include "../Public/readInputFile.h" //header file for class
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

bool UreadInputFile::isValidFilePath(FString filepath)
{
	string CStyleFilePath(TCHAR_TO_UTF8(*filepath));
	std::ifstream test(CStyleFilePath);

	if (!test) {
		return false;
	}
	else {
		return true;
	}
}

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

bool UreadInputFile::isGeneModelFile(TArray<FString> inputArray)
{
	TArray<FString> testLineArray;
	inputArray[0].ParseIntoArrayWS(testLineArray, NULL);

	if (testLineArray.Num() < 9) {
		return false;
	}
	else {
		return true;
	}
}

bool UreadInputFile::isTrackFile(TArray<FString> inputArray)
{
	FString firstLine = inputArray[0];
	TArray<FString> secondLineArray;
	inputArray[1].ParseIntoArrayWS(secondLineArray, NULL);

	bool firstLineCheck;
	bool secondLineCheck;

	if (firstLine.Contains("track name=\"")) {
		firstLineCheck = true;
	}
	else {
		firstLineCheck = false;
	}

	if (secondLineArray.Num() <= 6) {
		secondLineCheck = true;
	}
	else {
		secondLineCheck = false;
	}

	return firstLineCheck && secondLineCheck;
}

bool UreadInputFile::isTransformFile(TArray<FString> inputArray)
{
	FString firstLine = inputArray[0];
	TArray<FString> secondLineArray;
	inputArray[1].ParseIntoArrayWS(secondLineArray, NULL);

	if (!firstLine.Contains("track name=\"")) {
		if (secondLineArray.Num() == 4) {
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

bool UreadInputFile::isArcTrack(TArray<FString> inputArray)
{
	TArray<FString> secondLineArray;
	inputArray[1].ParseIntoArrayWS(secondLineArray, NULL);
	int len = secondLineArray.Num();

	if (len > 4) {
		return true;
	}
	else {
		return false;
	}
}

FString UreadInputFile::getTrackName(FString toParse)
{
	FString retString = toParse;
	retString = retString.LeftChop(1);
	retString = retString.RightChop(12);

	return retString;
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

int32 UreadInputFile::getStartStart(FString toParse)
{
	return getFeatureStart(toParse);
}

int32 UreadInputFile::getStartEnd(FString toParse)
{
	return getFeatureEnd(toParse);
}

int32 UreadInputFile::getEndStart(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	int32 endStart = FCString::Atoi(*forsplit[4]);
	return endStart;
}

int32 UreadInputFile::getEndEnd(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	int32 endEnd = FCString::Atoi(*forsplit[5]);
	return endEnd;
}

FVector UreadInputFile::getEndPoint(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	float xCoor = FCString::Atof(*forsplit[1]);
	float yCoor = FCString::Atof(*forsplit[2]);
	float zCoor = FCString::Atof(*forsplit[3]);

	FVector retVector = FVector(xCoor, yCoor, zCoor);
	return retVector;
}

TArray <FString> UreadInputFile::getNetwork(FString toParse)
{
	TArray<FString> forsplit;
	toParse.ParseIntoArrayWS(forsplit, NULL);

	return forsplit;
}

TArray<FVector> UreadInputFile::getGenePositions(TArray<FString> inputArray)
{
	TArray<FVector> returnArray;
	FVector currentVector;
	TArray<FString> forRead;

	for (int i = 0; i < inputArray.Num(); i++) {
		inputArray[i].ParseIntoArrayWS(forRead, NULL);
		currentVector = FVector(FCString::Atof(*forRead[0]), FCString::Atof(*forRead[1]), FCString::Atof(*forRead[2]));
		returnArray.Add(currentVector);
	}

	return returnArray;
}

TArray<FVector> UreadInputFile::generateGeneVectors(int32 length)
{
	TArray<FVector> returnVectorArray;
	int32 columnSize;

	float numSqrt = sqrt(length);
	int32 numPrev = round(numSqrt);
	int32 numNext = round(numSqrt + 1);
	int32 sqrPrev = numPrev * numPrev;
	int32 sqrNext = numNext * numNext;

	if ((length - sqrPrev) < (sqrNext - length)) {
		columnSize = numPrev;
	}
	else {
		columnSize = numNext;
	}

	int32 currentRow = 1;
	int32 numOff = (columnSize * columnSize) - length;
	
	if (numOff < 0) {
		while (currentRow <= columnSize) {
			for (int32 i = 0; i < columnSize; i++) {
				int32 currentX = 400 * (currentRow - 1);
				int32 currentZ = 400 * (columnSize - (i + 1));

				returnVectorArray.Add(FVector(currentX, 0, currentZ));

			}
			currentRow += 1;
		}
		int32 lastSquareX = returnVectorArray[returnVectorArray.Num() - 1].X;
		int32 lastSquareZ = returnVectorArray[returnVectorArray.Num() - 1].Z;

		for (int32 i = 0; i < abs(numOff); i++) {
			int32 currentX = lastSquareX + 400;
			int32 currentZ = lastSquareZ + (400 * (columnSize - (i + 1)));

			returnVectorArray.Add(FVector(currentX, 0, currentZ));
		}
	}

	else if (numOff > 0) {
		while (currentRow <= columnSize - 1) {
			for (int32 i = 0; i < columnSize; i++) {
				int32 currentX = 400 * (currentRow - 1);
				int32 currentZ = 400 * (columnSize - (i + 1));

				returnVectorArray.Add(FVector(currentX, 0, currentZ));
			}
			currentRow += 1;
		}
		int32 lastSquareX = returnVectorArray[returnVectorArray.Num() - 1].X;
		int32 lastSquareZ = returnVectorArray[returnVectorArray.Num() - 1].Z;

		for (int32 i = 0; i < columnSize - numOff; i++) {
			int32 currentX = lastSquareX + 400;
			int32 currentZ = lastSquareZ + (400 * (columnSize - (i + 1)));

			returnVectorArray.Add(FVector(currentX, 0, currentZ));
		}
	}

	else {
		while (currentRow <= columnSize) {
			for (int32 i = 0; i < columnSize; i++) {
				int32 currentX = 400 * (currentRow - 1);
				int32 currentZ = 400 * (columnSize - (i + 1));

				returnVectorArray.Add(FVector(currentX, 0, currentZ));
			}
			currentRow += 1;
		}
	}

	return returnVectorArray;
}