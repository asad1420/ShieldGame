// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class USkeletalMeshComponent;
class UDamageType;
class UParticleSystem;
class USoundCue;

USTRUCT()
struct FHitScanTrace
{
	GENERATED_BODY()

	public:

	UPROPERTY()
	TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY()
	FVector_NetQuantize TraceTo;
};


UCLASS()
class SHIELDGAME_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	void PlayFireEffects(FVector TraceEnd);

	void PlayImpactEffects(EPhysicalSurface SurfaceType, FVector ImpactPoint);
   
   UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   TSubclassOf<UDamageType> DamageType;
   
   UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   FName MuzzelSocketName;

   UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   UParticleSystem* MuzzelEffect;

   UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   UParticleSystem* DefaultImpactEffect;
   
   UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   UParticleSystem* FleshImpactEffect;

   UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   FName TracerTargetName;

   UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
   UParticleSystem* TracerEffect;

   UPROPERTY(EditDefaultsOnly, Category = "Weapon")
   TSubclassOf<UCameraShake> FireCamShake;
   
   UPROPERTY(EditDefaultsOnly, Category = "Weapon")
   float BaseDamage;

   void Fire();
 
   UFUNCTION(Server, Reliable, WithValidation)
   void ServerFire();

   FTimerHandle TimerHandle_TimeBetweenShots;

   float LastFireTime;
   
   // Bullets per minute fire by weapon
   UPROPERTY(EditDefaultsOnly, Category = "Weapon")
   float RateOfFire;
   
   UPROPERTY(EditDefaultsOnly, Category = "Weapon", meta = (ClampMin=0.0f))
   float BulletSpread;
   
   // derived from RateOfFire
   float TimeBetweenShots;

   UPROPERTY(ReplicatedUsing=OnRep_HitScanTrace)
   FHitScanTrace HitScanTace;

   UFUNCTION()
   void OnRep_HitScanTrace();

   UPROPERTY(EditDefaultsOnly, Category = "PlayerWeapon")
	USoundCue* BeamSound;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StartFire();

	void StopFire();

};
