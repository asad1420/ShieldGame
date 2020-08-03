// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerState.h"

void ASPlayerState::AddScore(float ScoreDelta) 
{
   
   Score += ScoreDelta;
   ScoreCount = Score;

    UE_LOG(LogTemp, Log, TEXT("Score Value: %f"), ScoreCount);
}

 float ASPlayerState::ScoreCounter() 
 {
	return ScoreCount;
 }