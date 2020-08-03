// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHIELDGAME_SPickupActor_generated_h
#error "SPickupActor.generated.h already included, missing '#pragma once' in SPickupActor.h"
#endif
#define SHIELDGAME_SPickupActor_generated_h

#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_SPARSE_DATA
#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_RPC_WRAPPERS
#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASPickupActor(); \
	friend struct Z_Construct_UClass_ASPickupActor_Statics; \
public: \
	DECLARE_CLASS(ASPickupActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASPickupActor)


#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_INCLASS \
private: \
	static void StaticRegisterNativesASPickupActor(); \
	friend struct Z_Construct_UClass_ASPickupActor_Statics; \
public: \
	DECLARE_CLASS(ASPickupActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASPickupActor)


#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASPickupActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASPickupActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASPickupActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASPickupActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASPickupActor(ASPickupActor&&); \
	NO_API ASPickupActor(const ASPickupActor&); \
public:


#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASPickupActor(ASPickupActor&&); \
	NO_API ASPickupActor(const ASPickupActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASPickupActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASPickupActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASPickupActor)


#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SphereComp() { return STRUCT_OFFSET(ASPickupActor, SphereComp); } \
	FORCEINLINE static uint32 __PPO__DecalComp() { return STRUCT_OFFSET(ASPickupActor, DecalComp); } \
	FORCEINLINE static uint32 __PPO__PowerUpClass() { return STRUCT_OFFSET(ASPickupActor, PowerUpClass); } \
	FORCEINLINE static uint32 __PPO__CooldownDuration() { return STRUCT_OFFSET(ASPickupActor, CooldownDuration); }


#define ShieldGame_Source_ShieldGame_SPickupActor_h_11_PROLOG
#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_RPC_WRAPPERS \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_INCLASS \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShieldGame_Source_ShieldGame_SPickupActor_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_INCLASS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_SPickupActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHIELDGAME_API UClass* StaticClass<class ASPickupActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShieldGame_Source_ShieldGame_SPickupActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
