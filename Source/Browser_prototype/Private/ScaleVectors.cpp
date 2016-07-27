// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
#include "ScaleVectors.h"

TArray<float> UScaleVectors::scaleSmallest(TArray<float> inputArray)
{
	int smallest = inputArray[0];
	TArray <float> newarray;

	for (int i = 1; i < inputArray.Num(); ++i)
	{
		if (inputArray[i] < smallest)
			smallest = inputArray[i];
	}

	for (int i = 0; i<inputArray.Num(); ++i)
	{
		newarray.Add((inputArray[i] / smallest));
	}

	return newarray;
}

TArray<float> UScaleVectors::scaleMedian(TArray<float> inputArray)
{
	TArray<float> sortedArray;

	for (int i = 0; i < inputArray.Num(); i++) {
		sortedArray.Add(inputArray[i]);
	}

	for (int i = inputArray.Num() - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (sortedArray[j] > sortedArray[j + 1]) {
				float temp = sortedArray[j];
				sortedArray[j] = sortedArray[j + 1];
				sortedArray[j + 1] = temp;
			}
		}
	}

	float median = 0.0;

	if ((inputArray.Num() % 2) == 0) {
		median = (sortedArray[inputArray.Num() / 2] + sortedArray[(inputArray.Num() / 2) - 1]) / 2.0;
	}
	else {
		median = sortedArray[inputArray.Num() / 2];
	}

	TArray<float> returnArray;

	for (int i = 0; i < inputArray.Num(); i++) {
		returnArray.Add((inputArray[i] / median));
	}

	return returnArray;
}