// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
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