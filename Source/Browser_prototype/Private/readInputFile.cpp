// Fill out your copyright notice in the Description page of Project Settings.

#include "Browser_prototype.h" //header file for project
#include "CoreMisc.h"	//header file for FFileHelper
#include "../Public/readInputFile.h" //header file for class


//TArray <FString> loadArrayFromFile(const TCHAR * inFileName)
//{
//	TArray <FString> retstrings;
//	FFileHelper::LoadANSITextFileToStrings(inFileName, NULL, retstrings);
//	return retstrings;
//}

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
