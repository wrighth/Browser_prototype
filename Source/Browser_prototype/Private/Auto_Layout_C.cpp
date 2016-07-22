// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
#include "Algo/Reverse.h"
#include "Auto_Layout_C.h"

TArray<FString> UAuto_Layout_C::sortGenesAlphabetically(TArray<FString> unsortedNames)
{
	TArray<FString> sortedArray = unsortedNames;
	sortedArray.Sort();

	return sortedArray;
}

TArray<FVector> UAuto_Layout_C::getAlphabeticalVectors(TArray<FString> sortedNames)
{
	TArray<FVector> returnVectorArray;
	int32 columnSize;

	float numSqrt = sqrt(sortedNames.Num());
	int32 numPrev = round(numSqrt);
	int32 numNext = round(numSqrt + 1);
	int32 sqrPrev = numPrev * numPrev;
	int32 sqrNext = numNext * numNext;

	if ((sortedNames.Num() - sqrPrev) < (sqrNext - sortedNames.Num())) {
		columnSize = numPrev;
	}
	else {
		columnSize = numNext;
	}

	int32 currentRow = 1;
	int32 numOff = (columnSize * columnSize) - sortedNames.Num();

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

TArray<int32> UAuto_Layout_C::sortUnsortedInts(TArray<int32> unsortedInts)
{
	unsortedInts.Sort();
	TArray<int32> sortedInts = unsortedInts;
	Algo::Reverse(sortedInts);

	return sortedInts;
}

TArray<FString> UAuto_Layout_C::matchGeneNames(TArray<int32> unsortedInts, TArray<int32> sortedInts, TArray<FString> geneNames)
{
	TArray<FString> matchedGeneNames;
	matchedGeneNames.Init("t", geneNames.Num());

	for (int i = 0; i < geneNames.Num(); i++) {
		int32 correspondingInt = unsortedInts[i];
		int32 sortedIndex = sortedInts.IndexOfByKey(correspondingInt);
		bool continueIndex = true;

		while (continueIndex) {
			if (matchedGeneNames[sortedIndex] == "t") {
				matchedGeneNames[sortedIndex] = geneNames[i];
				continueIndex = false;
			}
			else {
				sortedIndex++;
			}
		}
	}
	
	return matchedGeneNames;
}

TArray<FVector> UAuto_Layout_C::generateConnectivityLocations(TArray<int32> sortedInts)
{
	TArray<FVector> returnVectors;
	int32 length = sortedInts.Num();
	int32 currentColumn = 1;

	for (int i = 0; i < length; i++) {
		if (i == 0) {
			returnVectors.Add(FVector(0, 0, 0));
		}
		else if (sortedInts[i] == sortedInts[i - 1]) {
			returnVectors.Add(FVector(returnVectors[i - 1].X, returnVectors[i - 1].Y, returnVectors[i - 1].Z + 400));
		}
		else {
			returnVectors.Add(FVector(400 * (currentColumn - 1), 0, 0));
			currentColumn++;
		}
	}

	return returnVectors;
}