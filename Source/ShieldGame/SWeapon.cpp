// Fill out your copyright notice in the Description page of Project Settings.


#include "SWeapon.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Components/SkeletalMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "ShieldGame.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"
#include "Sound/SoundCue.h"
#include "Components/ActorComponent.h"

// Sets default values
ASWeapon::ASWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
    RootComponent = MeshComp;

	MuzzelSocketName = "MuzzleSocket";
	TracerTargetName = "Target";
	BaseDamage = 20.f;
	BulletSpread = 2.0f;
	RateOfFire = 600;

 //	SetReplicates(true);
	NetUpdateFrequency = 66.0f;
	MinNetUpdateFrequency = 33.0f;

	//SetIsReplicatedByDefault(false);
}

// Called when the game starts or when spawned
void ASWeapon::BeginPlay()
{
	Super::BeginPlay();
  
  // SetReplicates(true);

	TimeBetweenShots = 60 / RateOfFire;
	
}

// Called every frame
void ASWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASWeapon::Fire() {

       if (GetLocalRole() < ROLE_Authority)
	   {
		   ServerFire();
	   }

      
	  AActor* MyOwner = GetOwner();

	  if (MyOwner)
	  {
		  FVector EyeLocation;
		  FRotator EyeRotation;

		  MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		  FVector ShotDirection = EyeRotation.Vector();

		  // Bullet Spread
		  float HalfRad = FMath::DegreesToRadians(BulletSpread);
		  ShotDirection = FMath::VRandCone(ShotDirection, HalfRad, HalfRad);

		  FVector TraceEnd = EyeLocation + (ShotDirection * 10000);

		  FCollisionQueryParams QueryParams;
		  QueryParams.AddIgnoredActor(MyOwner);
		  QueryParams.AddIgnoredActor(this);
		  QueryParams.bTraceComplex = true;
		  QueryParams.bReturnPhysicalMaterial = true;
          
		  FVector TracerEndPoint = TraceEnd;
         
          EPhysicalSurface SurfaceType = SurfaceType_Default;
          
		  UGameplayStatics::SpawnSoundAttached(BeamSound, RootComponent);
		  

		  FHitResult Hit;

		  if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
		   {
              
			  AActor* HitActor = Hit.GetActor();
              
			  SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
              
			  float ActualDamage = BaseDamage;

			  if (SurfaceType == SURFACE_FLESHVULNERABLE)
			  {
				  ActualDamage *= 4.0f; 
			  }

			  UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), MyOwner, DamageType);
              
               PlayImpactEffects(SurfaceType, Hit.ImpactPoint);

		      TracerEndPoint = Hit.ImpactPoint;
		   }

		   DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false, 1.0f, 1.0f);

		   PlayFireEffects(TracerEndPoint);


		   if (HasAuthority())
		   {
			   HitScanTace.TraceTo = TracerEndPoint;
			   HitScanTace.SurfaceType = SurfaceType;
		   }

           LastFireTime = GetWorld()->TimeSeconds;
	  }

}
  void ASWeapon::PlayFireEffects(FVector TraceEnd) 
  {
	  if (MuzzelEffect)
		   {
			   UGameplayStatics::SpawnEmitterAttached(MuzzelEffect, MeshComp, MuzzelSocketName);
		   }

		   if (TracerEffect)
		   {
			   FVector MuzzelLocation = MeshComp->GetSocketLocation(MuzzelSocketName);

			   UParticleSystemComponent* TracerComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TracerEffect, MuzzelLocation);

			   if (TracerComp)
			   {
				   TracerComp->SetVectorParameter(TracerTargetName, TraceEnd);
			   }
		   }

		   APawn* MyOwner = Cast<APawn>(GetOwner());
		   
		   if (MyOwner)
		   {
			   APlayerController* PC = Cast<APlayerController>(MyOwner->GetController());

			   if (PC)
			   {
				   PC->ClientPlayCameraShake(FireCamShake);
			   }
		   }
	
  }
  
  void ASWeapon::StartFire() 
  { 
	  float FirstDelay = FMath::Max(LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);

	  GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &ASWeapon::Fire, TimeBetweenShots, true, FirstDelay);

	  

  }
 
  void ASWeapon::StopFire() 
  {
	GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
  }
  
  
  void ASWeapon::ServerFire_Implementation() 
  {
	Fire();
  }

  bool ASWeapon::ServerFire_Validate()
  {
     return true;
  }
     
  void ASWeapon::OnRep_HitScanTrace() 
  {
	PlayFireEffects(HitScanTace.TraceTo);
	PlayImpactEffects(HitScanTace.SurfaceType, HitScanTace.TraceTo);
  }

  void ASWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
 {
	 Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	 DOREPLIFETIME_CONDITION(ASWeapon, HitScanTace, COND_SkipOwner);
 }
 void ASWeapon::PlayImpactEffects(EPhysicalSurface SurfaceType, FVector ImpactPoint) 
 {
	
			 UParticleSystem* SelectedEffect;
             SelectedEffect = nullptr;

			 switch (SurfaceType)
			 {
			 case SURFACE_FLESHDEFAULT:
			 case SURFACE_FLESHVULNERABLE:
				 SelectedEffect = FleshImpactEffect;
				 break;

			 default:
			     SelectedEffect = DefaultImpactEffect;
				 break;
			 }

			 if (SelectedEffect)
			  {
				  FVector MuzzelLocation = MeshComp->GetSocketLocation(MuzzelSocketName);

				  FVector ShotDirection = ImpactPoint - MuzzelLocation;
				  ShotDirection.Normalize();
				  UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SelectedEffect, ImpactPoint, ShotDirection.Rotation());
			  }
 }
