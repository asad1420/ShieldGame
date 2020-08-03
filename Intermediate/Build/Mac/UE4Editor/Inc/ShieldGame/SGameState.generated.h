// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EWaveState : uint8;
#ifdef SHIELDGAME_SGameState_generated_h
#error "SGameState.generated.h already included, missing '#pragma once' in SGameState.h"
#endif
#define SHIELDGAME_SGameState_generated_h

#define ShieldGame_Source_ShieldGame_SGameState_h_31_SPARSE_DATA
#define ShieldGame_Source_ShieldGame_SGameState_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRep_WaveState);


#define ShieldGame_Source_ShieldGame_SGameState_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_WaveState);


#define ShieldGame_Source_ShieldGame_SGameState_h_31_EVENT_PARMS \
	struct SGameState_eventWaveStateChanged_Parms \
	{ \
		EWaveState NewState; \
		EWaveState OldState; \
	};


#define ShieldGame_Source_ShieldGame_SGameState_h_31_CALLBACK_WRAPPERS
#define ShieldGame_Source_ShieldGame_SGameState_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASGameState(); \
	friend struct Z_Construct_UClass_ASGameState_Statics; \
public: \
	DECLARE_CLASS(ASGameState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASGameState) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		WaveState=NETFIELD_REP_START, \
		NETFIELD_REP_END=WaveState	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define ShieldGame_Source_ShieldGame_SGameState_h_31_INCLASS \
private: \
	static void StaticRegisterNativesASGameState(); \
	friend struct Z_Construct_UClass_ASGameState_Statics; \
public: \
	DECLARE_CLASS(ASGameState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShieldGame"), NO_API) \
	DECLARE_SERIALIZER(ASGameState) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		WaveState=NETFIELD_REP_START, \
		NETFIELD_REP_END=WaveState	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define ShieldGame_Source_ShieldGame_SGameState_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASGameState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASGameState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASGameState(ASGameState&&); \
	NO_API ASGameState(const ASGameState&); \
public:


#define ShieldGame_Source_ShieldGame_SGameState_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASGameState(ASGameState&&); \
	NO_API ASGameState(const ASGameState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASGameState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASGameState)


#define ShieldGame_Source_ShieldGame_SGameState_h_31_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__WaveState() { return STRUCT_OFFSET(ASGameState, WaveState); }


#define ShieldGame_Source_ShieldGame_SGameState_h_28_PROLOG \
	ShieldGame_Source_ShieldGame_SGameState_h_31_EVENT_PARMS


#define ShieldGame_Source_ShieldGame_SGameState_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_SGameState_h_31_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_SGameState_h_31_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_SGameState_h_31_RPC_WRAPPERS \
	ShieldGame_Source_ShieldGame_SGameState_h_31_CALLBACK_WRAPPERS \
	ShieldGame_Source_ShieldGame_SGameState_h_31_INCLASS \
	ShieldGame_Source_ShieldGame_SGameState_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShieldGame_Source_ShieldGame_SGameState_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShieldGame_Source_ShieldGame_SGameState_h_31_PRIVATE_PROPERTY_OFFSET \
	ShieldGame_Source_ShieldGame_SGameState_h_31_SPARSE_DATA \
	ShieldGame_Source_ShieldGame_SGameState_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_SGameState_h_31_CALLBACK_WRAPPERS \
	ShieldGame_Source_ShieldGame_SGameState_h_31_INCLASS_NO_PURE_DECLS \
	ShieldGame_Source_ShieldGame_SGameState_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHIELDGAME_API UClass* StaticClass<class ASGameState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShieldGame_Source_ShieldGame_SGameState_h


#define FOREACH_ENUM_EWAVESTATE(op) \
	op(EWaveState::WaitingToStart) \
	op(EWaveState::WaveInProgress) \
	op(EWaveState::WaitingToComplete) \
	op(EWaveState::WaveComplete) \
	op(EWaveState::GameOver) 

enum class EWaveState : uint8;
template<> SHIELDGAME_API UEnum* StaticEnum<EWaveState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
