// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHIELDGAME_SWeapon_generated_h
#error "SWeapon.generated.h already included, missing '#pragma once' in SWeapon.h"
#endif
#define SHIELDGAME_SWeapon_generated_h

#define ShieldGame_Source_ShieldGame_SWeapon_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FHitScanTrace_Statics; \
	SHIELDGAME_API static class UScriptStruct* StaticStruct();


template<> SHIELDGAME_API UScriptStruct* StaticStruct<struct FHitScanTrace>();

#define ShieldGame_Source_ShieldGame_SWeapon_h_32_SPARSE_DATA
#define ShieldGame_Source_ShieldGame_SWeapon_h_32_RPC_WRAPPERS \
	virtual bool ServerFire_Validate(); \
	virtual void ServerFire_Implementation(); \
 \
	DECLARE_FUNCTION(execOnRep_HitScanTrace); \
	DECLARE_FUNCTION(execServerFire);


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerFire_Validate(); \
	virtual void ServerFire_Implementation(); \
 \
	DECLARE_FUNCTION(execOnRep_HitScanTrace); \
	DECLARE_FUNCTION(execServerFire);


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_EVENT_PARMS
#define ShieldGame_Source_ShieldGame_SWeapon_h_32_CALLBACK_WRAPPERS
#define ShieldGame_Source_ShieldGame_SWeapon_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASWeapon(); \
	friend struct Z_Construct_UClass_ASWeapon_Statics; \
public: \
	DECLARE_CLASS(ASWeapon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASWeapon) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		HitScanTace=NETFIELD_REP_START, \
		NETFIELD_REP_END=HitScanTace	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_INCLASS \
private: \
	static void StaticRegisterNativesASWeapon(); \
	friend struct Z_Construct_UClass_ASWeapon_Statics; \
public: \
	DECLARE_CLASS(ASWeapon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASWeapon) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		HitScanTace=NETFIELD_REP_START, \
		NETFIELD_REP_END=HitScanTace	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASWeapon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASWeapon(ASWeapon&&); \
	NO_API ASWeapon(const ASWeapon&); \
public:


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASWeapon(ASWeapon&&); \
	NO_API ASWeapon(const ASWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASWeapon)


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(ASWeapon, MeshComp); } \
	FORCEINLINE static uint32 __PPO__DamageType() { return STRUCT_OFFSET(ASWeapon, DamageType); } \
	FORCEINLINE static uint32 __PPO__MuzzelSocketName() { return STRUCT_OFFSET(ASWeapon, MuzzelSocketName); } \
	FORCEINLINE static uint32 __PPO__MuzzelEffect() { return STRUCT_OFFSET(ASWeapon, MuzzelEffect); } \
	FORCEINLINE static uint32 __PPO__DefaultImpactEffect() { return STRUCT_OFFSET(ASWeapon, DefaultImpactEffect); } \
	FORCEINLINE static uint32 __PPO__FleshImpactEffect() { return STRUCT_OFFSET(ASWeapon, FleshImpactEffect); } \
	FORCEINLINE static uint32 __PPO__TracerTargetName() { return STRUCT_OFFSET(ASWeapon, TracerTargetName); } \
	FORCEINLINE static uint32 __PPO__TracerEffect() { return STRUCT_OFFSET(ASWeapon, TracerEffect); } \
	FORCEINLINE static uint32 __PPO__FireCamShake() { return STRUCT_OFFSET(ASWeapon, FireCamShake); } \
	FORCEINLINE static uint32 __PPO__BaseDamage() { return STRUCT_OFFSET(ASWeapon, BaseDamage); } \
	FORCEINLINE static uint32 __PPO__RateOfFire() { return STRUCT_OFFSET(ASWeapon, RateOfFire); } \
	FORCEINLINE static uint32 __PPO__BulletSpread() { return STRUCT_OFFSET(ASWeapon, BulletSpread); } \
	FORCEINLINE static uint32 __PPO__HitScanTace() { return STRUCT_OFFSET(ASWeapon, HitScanTace); } \
	FORCEINLINE static uint32 __PPO__BeamSound() { return STRUCT_OFFSET(ASWeapon, BeamSound); }


#define ShieldGame_Source_ShieldGame_SWeapon_h_29_PROLOG \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_EVENT_PARMS


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_RPC_WRAPPERS \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_CALLBACK_WRAPPERS \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_INCLASS \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShieldGame_Source_ShieldGame_SWeapon_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_CALLBACK_WRAPPERS \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_INCLASS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_SWeapon_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHIELDGAME_API UClass* StaticClass<class ASWeapon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShieldGame_Source_ShieldGame_SWeapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
