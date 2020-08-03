// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHealthComponent;
class UDamageType;
class AController;
class AActor;
#ifdef SHIELDGAME_STrackerBot_generated_h
#error "STrackerBot.generated.h already included, missing '#pragma once' in STrackerBot.h"
#endif
#define SHIELDGAME_STrackerBot_generated_h

#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_SPARSE_DATA
#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHandleTakeDamage);


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleTakeDamage);


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASTrackerBot(); \
	friend struct Z_Construct_UClass_ASTrackerBot_Statics; \
public: \
	DECLARE_CLASS(ASTrackerBot, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASTrackerBot)


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_INCLASS \
private: \
	static void StaticRegisterNativesASTrackerBot(); \
	friend struct Z_Construct_UClass_ASTrackerBot_Statics; \
public: \
	DECLARE_CLASS(ASTrackerBot, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASTrackerBot)


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASTrackerBot(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASTrackerBot) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASTrackerBot); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASTrackerBot); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASTrackerBot(ASTrackerBot&&); \
	NO_API ASTrackerBot(const ASTrackerBot&); \
public:


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASTrackerBot(ASTrackerBot&&); \
	NO_API ASTrackerBot(const ASTrackerBot&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASTrackerBot); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASTrackerBot); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASTrackerBot)


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(ASTrackerBot, MeshComp); } \
	FORCEINLINE static uint32 __PPO__HealthComp() { return STRUCT_OFFSET(ASTrackerBot, HealthComp); } \
	FORCEINLINE static uint32 __PPO__SphereComp() { return STRUCT_OFFSET(ASTrackerBot, SphereComp); } \
	FORCEINLINE static uint32 __PPO__MovementForce() { return STRUCT_OFFSET(ASTrackerBot, MovementForce); } \
	FORCEINLINE static uint32 __PPO__bUseVelocityChange() { return STRUCT_OFFSET(ASTrackerBot, bUseVelocityChange); } \
	FORCEINLINE static uint32 __PPO__RequiredDistanceToTarget() { return STRUCT_OFFSET(ASTrackerBot, RequiredDistanceToTarget); } \
	FORCEINLINE static uint32 __PPO__ExplosionEffect() { return STRUCT_OFFSET(ASTrackerBot, ExplosionEffect); } \
	FORCEINLINE static uint32 __PPO__ExplosionRadius() { return STRUCT_OFFSET(ASTrackerBot, ExplosionRadius); } \
	FORCEINLINE static uint32 __PPO__ExplosionDamage() { return STRUCT_OFFSET(ASTrackerBot, ExplosionDamage); } \
	FORCEINLINE static uint32 __PPO__SelfDamageInterval() { return STRUCT_OFFSET(ASTrackerBot, SelfDamageInterval); } \
	FORCEINLINE static uint32 __PPO__SelfDestructSound() { return STRUCT_OFFSET(ASTrackerBot, SelfDestructSound); } \
	FORCEINLINE static uint32 __PPO__ExplodeSound() { return STRUCT_OFFSET(ASTrackerBot, ExplodeSound); }


#define ShieldGame_Source_ShieldGame_STrackerBot_h_11_PROLOG
#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_RPC_WRAPPERS \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_INCLASS \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShieldGame_Source_ShieldGame_STrackerBot_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_INCLASS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_STrackerBot_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHIELDGAME_API UClass* StaticClass<class ASTrackerBot>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShieldGame_Source_ShieldGame_STrackerBot_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
