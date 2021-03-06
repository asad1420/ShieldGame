// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SWeapon.h"
#include "Components/CapsuleComponent.h"
#include "ShieldGame.h"
#include "Component/HealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"


// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
      
	  SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
      SpringArmComp->bUsePawnControlRotation = true;
      SpringArmComp->SetupAttachment(RootComponent);

	  HealthComp1 = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp1"));

	  GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
      
	  GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);
      
	  CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	  CameraComp->SetupAttachment(SpringArmComp);

	  ZoomedFOV = 65.0f;
	  ZoomInterpSpeed = 20.0f;
	  WeaponAttachedSocketName = "WeaponSocket";

	
	//  SetIsReplicatedByDefault(false);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
   
   HealthComp1->OnHealthChanged.AddDynamic(this, &ASCharacter::ChangeHogaHealth);
	
	DefaultFOV = CameraComp->FieldOfView;
    
	
 	if (HasAuthority())
   {
	// Default Weapon


	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	CurrentWeapon = GetWorld()->SpawnActor<ASWeapon>(StarterWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);

	if (CurrentWeapon)
	{   
		CurrentWeapon->SetOwner(this);
		CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponAttachedSocketName);
	}	

    } 

   
}

 void ASCharacter::MoveForward(float value)
 {
	  AddMovementInput(GetActorForwardVector() * value);
 }

 void ASCharacter::MoveRight(float value)
 {
	  AddMovementInput(GetActorRightVector() * value);
 }


// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
	float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
    
	float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

	CameraComp->SetFieldOfView(NewFOV);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASCharacter::BeginCrouch);
    PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASCharacter::EndCrouch);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASCharacter::Jump);
	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &ASCharacter::BeginZoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &ASCharacter::EndZoom);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASCharacter::EndFire);

}

void ASCharacter::BeginCrouch() {
	
      UE_LOG(LogTemp, Log, TEXT("Wave Pressed"));
	  Crouch();
}
 void ASCharacter::EndCrouch() {
	
	UE_LOG(LogTemp, Log, TEXT("Wave Released"));
	UnCrouch();
}
FVector ASCharacter::GetPawnViewLocation() const 
 {
    if (CameraComp)
	{
		return CameraComp->GetComponentLocation();
	}	

	return Super::GetPawnViewLocation();
 }
 
 void ASCharacter::BeginZoom() 
 {
    bWantsToZoom = true;	
 }

void ASCharacter::EndZoom() 
 {
	bWantsToZoom = false;
 }
 
 void ASCharacter::StartFire() 
 {
	 if (CurrentWeapon)
	  {
		  CurrentWeapon->StartFire();
		
	//	UGameplayStatics::SpawnSoundAttached(BeamSound, RootComponent);
	  }
	
 }

 void ASCharacter::EndFire() 
 {
	 if (CurrentWeapon)
	  {
		  CurrentWeapon->StopFire();
	  }
	
 }

 void ASCharacter::ChangeHogaHealth(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser) 
 {
	if (Health <= 0.0f && !bDied)
	{   
		bDied = true;

		GetMovementComponent()->StopMovementImmediately();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		DetachFromControllerPendingDestroy();
		SetLifeSpan(10.0f);
	}
      UE_LOG(LogTemp, Log, TEXT("Health Change Hogaya hurraayyy!!"));

 }

 void ASCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
 {
	 Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	 DOREPLIFETIME(ASCharacter, CurrentWeapon);
	 DOREPLIFETIME(ASCharacter, bDied);
 }


