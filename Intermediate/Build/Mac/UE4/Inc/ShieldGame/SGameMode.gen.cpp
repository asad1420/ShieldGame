// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShieldGame/SGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSGameMode() {}
// Cross Module References
	SHIELDGAME_API UFunction* Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ShieldGame();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	SHIELDGAME_API UClass* Z_Construct_UClass_ASGameMode_NoRegister();
	SHIELDGAME_API UClass* Z_Construct_UClass_ASGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics
	{
		struct _Script_ShieldGame_eventOnActorKilled_Parms
		{
			AActor* VictimActor;
			AActor* KillerActor;
			AController* KillerController;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_KillerController;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_KillerActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VictimActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::NewProp_KillerController = { "KillerController", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ShieldGame_eventOnActorKilled_Parms, KillerController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::NewProp_KillerActor = { "KillerActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ShieldGame_eventOnActorKilled_Parms, KillerActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::NewProp_VictimActor = { "VictimActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ShieldGame_eventOnActorKilled_Parms, VictimActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::NewProp_KillerController,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::NewProp_KillerActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::NewProp_VictimActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ShieldGame, nullptr, "OnActorKilled__DelegateSignature", nullptr, nullptr, sizeof(_Script_ShieldGame_eventOnActorKilled_Parms), Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASGameMode::execWaveCounter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->WaveCounter();
		P_NATIVE_END;
	}
	static FName NAME_ASGameMode_SpawnNewBot = FName(TEXT("SpawnNewBot"));
	void ASGameMode::SpawnNewBot()
	{
		ProcessEvent(FindFunctionChecked(NAME_ASGameMode_SpawnNewBot),NULL);
	}
	void ASGameMode::StaticRegisterNativesASGameMode()
	{
		UClass* Class = ASGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "WaveCounter", &ASGameMode::execWaveCounter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASGameMode_SpawnNewBot_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASGameMode_SpawnNewBot_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameMode" },
		{ "Comment", "// Hook for BP to spawn a single bot\n" },
		{ "ModuleRelativePath", "SGameMode.h" },
		{ "ToolTip", "Hook for BP to spawn a single bot" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASGameMode_SpawnNewBot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASGameMode, nullptr, "SpawnNewBot", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASGameMode_SpawnNewBot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASGameMode_SpawnNewBot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASGameMode_SpawnNewBot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASGameMode_SpawnNewBot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASGameMode_WaveCounter_Statics
	{
		struct SGameMode_eventWaveCounter_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SGameMode_eventWaveCounter_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "ModuleRelativePath", "SGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASGameMode, nullptr, "WaveCounter", nullptr, nullptr, sizeof(SGameMode_eventWaveCounter_Parms), Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASGameMode_WaveCounter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASGameMode_WaveCounter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASGameMode_NoRegister()
	{
		return ASGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnActorKilled_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActorKilled;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WaveCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_WaveCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeBetweenWaves_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeBetweenWaves;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ShieldGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASGameMode_SpawnNewBot, "SpawnNewBot" }, // 580940630
		{ &Z_Construct_UFunction_ASGameMode_WaveCounter, "WaveCounter" }, // 1831192118
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SGameMode.h" },
		{ "ModuleRelativePath", "SGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASGameMode_Statics::NewProp_OnActorKilled_MetaData[] = {
		{ "Category", "GameMode" },
		{ "ModuleRelativePath", "SGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASGameMode_Statics::NewProp_OnActorKilled = { "OnActorKilled", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASGameMode, OnActorKilled), Z_Construct_UDelegateFunction_ShieldGame_OnActorKilled__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASGameMode_Statics::NewProp_OnActorKilled_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASGameMode_Statics::NewProp_OnActorKilled_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASGameMode_Statics::NewProp_WaveCount_MetaData[] = {
		{ "BlueprintGetter", "WaveCounter" },
		{ "Category", "SGameMode" },
		{ "ModuleRelativePath", "SGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASGameMode_Statics::NewProp_WaveCount = { "WaveCount", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASGameMode, WaveCount), METADATA_PARAMS(Z_Construct_UClass_ASGameMode_Statics::NewProp_WaveCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASGameMode_Statics::NewProp_WaveCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASGameMode_Statics::NewProp_TimeBetweenWaves_MetaData[] = {
		{ "Category", "GameMode" },
		{ "Comment", "//\x09int32 WaveCount;\n" },
		{ "ModuleRelativePath", "SGameMode.h" },
		{ "ToolTip", "int32 WaveCount;" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASGameMode_Statics::NewProp_TimeBetweenWaves = { "TimeBetweenWaves", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASGameMode, TimeBetweenWaves), METADATA_PARAMS(Z_Construct_UClass_ASGameMode_Statics::NewProp_TimeBetweenWaves_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASGameMode_Statics::NewProp_TimeBetweenWaves_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASGameMode_Statics::NewProp_OnActorKilled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASGameMode_Statics::NewProp_WaveCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASGameMode_Statics::NewProp_TimeBetweenWaves,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASGameMode_Statics::ClassParams = {
		&ASGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASGameMode, 2804219910);
	template<> SHIELDGAME_API UClass* StaticClass<ASGameMode>()
	{
		return ASGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASGameMode(Z_Construct_UClass_ASGameMode, &ASGameMode::StaticClass, TEXT("/Script/ShieldGame"), TEXT("ASGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
