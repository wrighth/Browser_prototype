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




