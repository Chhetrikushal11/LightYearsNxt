#include "framework/World.h"
#include "Enemy/TwinBladeStage.h"

namespace ly
{
	TwinBladeStage::TwinBladeStage(World* world)
		:GameStage{ world },
		_mSpawnInterval{ 2.f },
		_mSpawnDistanceToCenter{ 100.f },
		_mLeftSpawnLoc{ world->GetWindowsSize().x/2 -_mSpawnDistanceToCenter ,100.f },
		_mRightSpawnLoc{ world->GetWindowsSize().x/2 + _mSpawnDistanceToCenter,100.f },
		_mSpawnLoc{ _mLeftSpawnLoc },
		_mSpawnAmt{ 10 },
		_mCurrentSpawnCount{ 0 }
	{

	}
	void TwinBladeStage::StartStage()
	{
		_mSpawnTimerHandle = TimerManager::Get().SetTimer(GetWeakRef(), &TwinBladeStage::SpawnTwinBlade, _mSpawnInterval, true);
	}

	void ly::TwinBladeStage::SpawnTwinBlade()
	{
		weak<TwinBlade> newTwinBlade = GetWorld()->SpawnActor<TwinBlade>();
		newTwinBlade.lock()->SetActorLocation(_mSpawnLoc);
		if(_mSpawnLoc == _mLeftSpawnLoc)
		{
			_mSpawnLoc = _mRightSpawnLoc;
			LOG("Switching");
		}
		else
		{
			_mSpawnLoc = _mLeftSpawnLoc;
			LOG("Switching Again.");
		}
		++_mCurrentSpawnCount;
		if (_mCurrentSpawnCount == _mSpawnAmt)
		{
			FinishStage();

		}
	}

	void TwinBladeStage::StageFinshed()
	{
		TimerManager::Get().ClearTimer(_mSpawnTimerHandle);
		LOG("STAGE FINISHED.");
	}

}