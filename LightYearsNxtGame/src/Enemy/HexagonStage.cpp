#include "Enemy/HexagonStage.h"
#include "framework/World.h"

namespace ly
{
	HexagonStage::HexagonStage(World* world)
		:GameStage{ world },
		_mSpawnInterval{ 5.f },
		_mSideSpawnOffset{ 80.f },
		_mSpwanGroupAmt{ 5 },
		_mCurrentSpawnCount{ 0 },
		_mMidSpawnLoc{ world->GetWindowsSize().x / 2.f  ,100.f + _mSideSpawnOffset },
		_mLeftSpawnLoc{ world->GetWindowsSize().x / 2.f + _mSideSpawnOffset, 100.f + _mSideSpawnOffset /2.f},
		_mRightSpawnLoc{ world->GetWindowsSize().x / 2.f - _mSideSpawnOffset, 100.f + _mSideSpawnOffset/2.f }
	{

	}

	void HexagonStage::StartStage()
	{
		_mSpawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &HexagonStage::SpawnHexagon, _mSpawnInterval, true);
	}

	void HexagonStage::StageFinished()
	{
	TimerManager::Get().ClearTimer(_mSpawnTimer);
	}

	void HexagonStage::SpawnHexagon()
	{
		weak<Hexagon> newHexagon = GetWorld()->SpawnActor<Hexagon>();
		newHexagon.lock()->SetActorLocation(_mMidSpawnLoc);
		LOG("SPAWNED MID");
		newHexagon = GetWorld()->SpawnActor<Hexagon>();
		newHexagon.lock()->SetActorLocation(_mLeftSpawnLoc);
		LOG("SPAWNED LEFT");
		newHexagon = GetWorld()->SpawnActor<Hexagon>();
		newHexagon.lock()->SetActorLocation(_mRightSpawnLoc);
		LOG("SPAWNED RIGHT");
		if (++_mCurrentSpawnCount == _mSpwanGroupAmt)
		{
			LOG("STAGE COMPLETED");
			FinishStage();
		}

	}

}