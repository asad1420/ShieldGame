#include "SGameState.h"
#include "Net/UnrealNetwork.h"
#include "Components/ActorComponent.h"




void ASGameState::OnRep_WaveState(EWaveState OldState)
{
	WaveStateChanged(WaveState, OldState);
}


void ASGameState::SetWaveState(EWaveState NewState)
{
	if (HasAuthority())
	{
		EWaveState OldState = WaveState;

		WaveState = NewState;
		// Call on server
		OnRep_WaveState(OldState);
	}
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASGameState, WaveState);
}