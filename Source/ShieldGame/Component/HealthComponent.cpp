// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "ShieldGame/SGameMode.h"
#include "Net/UnrealNetwork.h"
#include "Components/ActorComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	DefaultHealth = 100;
	bIsDead = false;
    TeamNum = 255;

//	SetIsReplicated(true);
   
  //  SetIsReplicatedByDefault(false);
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

   // SetIsReplicatedByDefault(false);

 	if (GetOwnerRole() == ROLE_Authority)
   {

	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}

   }

	Health = DefaultHealth;
	
}


void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) 
{
	if (Damage <= 0.0f || bIsDead)
	{
		return;
	}
     
    

	// Update Health Clamped
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"), *FString::SanitizeFloat(Health));

	bIsDead = Health <= 0.0f;

	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);
    
	if (bIsDead)
	{
    
	 ASGameMode* GM = Cast<ASGameMode>(GetWorld()->GetAuthGameMode());
	 
	 if (GM)
	 {
	 	GM->OnActorKilled.Broadcast(GetOwner(), DamageCauser, InstigatedBy);
	 }
	} 
}  

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
 {
	 Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	 DOREPLIFETIME(UHealthComponent, Health);
 }

 void UHealthComponent::OnRep_Health(float Old_Health) 
 {
	float Damage = Health - Old_Health;

	OnHealthChanged.Broadcast(this, Health, Damage, nullptr, nullptr, nullptr);
 }
 
 void UHealthComponent::Heal(float HealAmount) 
 {
	if (HealAmount <= 0.0f || Health <= 0.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("Health Change Failed!!"));
		return;
	}

	Health = FMath::Clamp(Health + HealAmount, 0.0f, DefaultHealth);

	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s (+%s)"), *FString::SanitizeFloat(Health), *FString::SanitizeFloat(HealAmount));

	OnHealthChanged.Broadcast(this, Health, -HealAmount, nullptr, nullptr, nullptr);
 }
 
 float UHealthComponent::GetHealth() const 
 {
	return Health;
 }
 
 bool UHealthComponent::IsFriendly(AActor* ActorA, AActor* ActorB) 
 {
	if (ActorA == nullptr ||  ActorB == nullptr)
	{
		//Assume Friendly
		return true;
	}
 	UHealthComponent* HealthCompA = Cast<UHealthComponent>(ActorA->GetComponentByClass(UHealthComponent::StaticClass()));
    UHealthComponent* HealthCompB = Cast<UHealthComponent>(ActorB->GetComponentByClass(UHealthComponent::StaticClass()));

	if (HealthCompA == nullptr || HealthCompB == nullptr)
	{   
		//Assume Friendly
		return true;
	}

	return HealthCompA->TeamNum == HealthCompB->TeamNum;
 }
