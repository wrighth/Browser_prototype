// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"//header for Blueprint accecssible function class
#include "readInputFile.generated.h" //generated header for the class, must be last entry in the include block


/**
 * 
 */
UCLASS()//Macro to build Unreal class(required)
class UreadInputFile : public UBlueprintFunctionLibrary //Defines inheritance from UBluePrintFunctionLibrary class, required to expose functions to Blueprints
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "readInputFile")//Macro to define functions called from Blueprints. Category argument defines heading for menus in Blueprint interface
		static TArray <FString> loadArrayFromFile(FString inFileName);//Defined as static to make accessible, actual function name is U + function name (e.g. UreadInputFile) in code.
		
		UFUNCTION(BlueprintCallable, Category = "readInputFile")
			static FString getFirstLine(TArray <FString> inArray);
	
};
