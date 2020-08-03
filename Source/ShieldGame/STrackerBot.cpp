// Fill out your copyright notice in the Description page of Project Settings.


#include "STrackerBot.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "GameFramework/Character.h"
#include "NavigationPath.h"
#include "DrawDebugHelpers.h"
#include "Component/HealthComponent.h"
#include "Components/SphereComponent.h"
#include "SCharacter.h"
#include "Sound/SoundCue.h"
#include "EngineUtils.h"

// Sets default values
ASTrackerBot::ASTrackerBot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCanEverAffectNavigation(false);
	MeshComp->SetSimulatePhysics(true);
	RootComponent = MeshComp;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));
	HealthComp->OnHealthChanged.AddDynamic(this, &ASTrackerBot::HandleTakeDamage);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetSphereRadius(200);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(RootComponent);


    bUseVelocityChange = false;
	MovementForce = 1000;
	RequiredDistanceToTarget = 100;
	ExplosionDamage = 60;
	ExplosionRadius = 350;
	SelfDamageInterval = 0.25f;

}

// Called when the game starts or when spawned
void ASTrackerBot::BeginPlay()
{
	Super::BeginPlay();

    
	if (HasAuthority())
 {
 	NextPathPoint = GetNextPathPoint();
 }

}

// Called every frame
void ASTrackerBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority() && !bExploded)
 {

	float DistanceToTarget = (GetActorLocation() - NextPathPoint).Size();

	if (DistanceToTarget <= RequiredDistanceToTarget)
	{   
		NextPathPoint = GetNextPathPoint();
		
	}

	else
	{
		// Keep Moving Towords NextTarget
		FVector ForceDirection = NextPathPoint - GetActorLocation();
		ForceDirection.Normalize();
		ForceDirection *= MovementForce;

		MeshComp->AddForce(ForceDirection, NAME_None, bUseVelocityChange);
	}
 }

}



FVector ASTrackerBot::GetNextPathPoint() 
{
    /* ACharacter* PlayerPawn = UGameplayStatics::GetPlayerCharacter(this, 0);

	 AActor* BestTarget = nullptr;
	 float NearestTargetDistance = FLT_MAX;

	 for (TActorIterator<APawn> It(GetWorld()); It; ++It)
    {
      APawn* TestPawn = *It;

      if (TestPawn == nullptr || UHealthComponent::IsFriendly(TestPawn, this))
      {
         continue;
      }

      UHealthComponent* TestPawnHealthComp = Cast<UHealthComponent>(TestPawn->GetComponentByClass(UHealthComponent::StaticClass()));

      if (TestPawnHealthComp && TestPawnHealthComp->GetHealth() > 0.0f)
      {
          float Distance = (TestPawn->GetActorLocation() - GetActorLocation()).Size();

		  if (Distance < NearestTargetDistance)
		  {
			  BestTarget = TestPawn;
			  NearestTargetDistance = Distance;
		  }
      }
    }
	 
	 if (BestTarget)
	 {  
		 */
         ACharacter* PlayerPawn = UGameplayStatics::GetPlayerCharacter(this, 0);
		 UNavigationPath* NavPath = UNavigationSystemV1::FindPathToActorSynchronously(this, GetActorLocation(), PlayerPawn);
         
		 GetWorldTimerManager().ClearTimer(TimerHandle_RefreshPath);
		 GetWorldTimerManager().SetTimer(TimerHandle_RefreshPath, this, &ASTrackerBot::RefreshPath, 2.0f, false);

	     if (NavPath && NavPath->PathPoints.Num() > 1)
	     {
		 return NavPath->PathPoints[1];
	     }

	 
   
	// Failed to find Path
	
 //	UE_LOG(LogTemp, Log, TEXT("NavPath Failed"));
	return GetActorLocation();
}
 void ASTrackerBot::HandleTakeDamage(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) 
 {  

	 
	 if (MatInst == nullptr)
	 {
		 MatInst = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
	 }
     
	 if (MatInst)
	 {
        MeshComp->SetScalarParameterValueOnMaterials("LastTimeDamageTaken", GetWorld()->TimeSeconds);
		
	  //	SetScalarParameterValue
	 }
     
	 UE_LOG(LogTemp, Log, TEXT("TrackBot_Health %s of %s"), *FString::SanitizeFloat(Health), *GetName() );

	if (Health <= 0.0f) 
	{   
		SelfDestruct();
	}
 }
 void ASTrackerBot::SelfDestruct() 
 {  
     
    if (bExploded)
	{
		return;
	}

	 bExploded = true;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    
	UGameplayStatics::PlaySoundAtLocation(this, ExplodeSound, GetActorLocation());

	MeshComp->SetVisibility(false, true);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

 if (HasAuthority())
 {
  
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(this);
    
	//Apply Damage
	UGameplayStatics::ApplyRadialDamage(this, ExplosionDamage, GetActorLocation(), ExplosionRadius, nullptr, IgnoreActors, this, GetInstigatorController(), true);
    
    DrawDebugSphere(GetWorld(), GetActorLocation(), ExplosionRadius, 12, FColor::Red, false, 2.0f, 1.0f);

	SetLifeSpan(2.0f);
 }
 
 }

 void ASTrackerBot::NotifyActorBeginOverlap(AActor* OtherActor) 
  { 
     Super::NotifyActorBeginOverlap(OtherActor);
     
      UE_LOG(LogTemp, Log, TEXT("OverLap Pass"));

	if (!bStartedSelfDestruction && !bExploded)
 {

    ASCharacter* PlayerPawn = Cast<ASCharacter>(OtherActor);
    if (PlayerPawn)
	{   

		
		GetWorldTimerManager().SetTimer(TimerHandle_SelfDamage, this, &ASTrackerBot::DamageSelf, SelfDamageInterval, true, 0.0f);
	  
		
		bStartedSelfDestruction = true;

		UGameplayStatics::SpawnSoundAttached(SelfDestructSound, RootComponent);
	}
 }

  }

 void ASTrackerBot::DamageSelf() 
 {  
	//UE_LOG(LogTemp, Log, TEXT("DamageSelfTrue"));
	UGameplayStatics::ApplyDamage(this, 20, GetInstigatorController(), this, nullptr);
 }
 
 void ASTrackerBot::RefreshPath() 
 {
	NextPathPoint = GetNextPathPoint();
 }

