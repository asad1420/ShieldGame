// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SHIELDGAME_API ASPlayerState : public APlayerState
{
	GENERATED_BODY()
   
   protected:
     
	UPROPERTY(BlueprintGetter=ScoreCounter)
	float ScoreCount;


	public:
    
	UFUNCTION(BlueprintCallable, Category="PlayerState")
	void AddScore(float ScoreDelta);
    
	UFUNCTION(BlueprintGetter)
    float ScoreCounter();

	

	
};
