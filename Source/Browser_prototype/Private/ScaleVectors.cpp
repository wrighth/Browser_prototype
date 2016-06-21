// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h"
#include "ScaleVectors.h"

TArray <float> scaleSmallest(TArray <int> inputArray)
{
	int smallest = inputArray[0];
	TArray <float> newarray;

	// Unreal function to load file into array

	//for (i = 0; i<; i++;)
		//(
			//const FString & InS,
			//FString * LeftS,
			//FString * RightS,
			//ESearchCase::Type SearchCase,
			//ESearchDir::Type SearchDir
			//)

		for (int i = 1; I < sizeof(array); i++)
		{
			if (array[i] < smallest)
				smallest = array[i];
		}

	//cout << “The smallest value is : “ << smallest;


	for (i = 0; i<sizeof(array); i++;)
	{
		newarray[i] = array[i] / smallest;
	}

	//cout << newarray[];

	return newarray;
}


}


