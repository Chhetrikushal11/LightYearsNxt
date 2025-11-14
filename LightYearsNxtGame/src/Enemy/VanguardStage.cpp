#include "Enemy/VanguardStage.h"
#include "Enemy/Vanguard.h"
#include "framework/World.h"


namespace ly
{
	VanguardStage::VanguardStage(World* world)
		:GameStage{ world },
		_mSpawnInterval{ 2.f },
		_mSwitchInterval{ 6.f },
		_mSpawnDistanceToEdge{ 100.f },
		_mLeftSpawnLoc{ 0.0f,0.0f },
		_mRightSpawnLoc{ 0.0f,0.0f },
		_mSpawnLoc{ 0.0f,0.0f },
		_mRowsToSpawn{ 4 },
		_mRowSpawnCount{ 0 },
		_mVanguardsPerRow{ 5 },
		_mCurrentRowVanguardCount{ 0 }
	{

	}

	void VanguardStage::StartStage()
	{
		auto windowSize = GetWorld()->GetWindowsSize();
		_mLeftSpawnLoc = sf::Vector2f{ _mSpawnDistanceToEdge,  100.f };
		_mRightSpawnLoc = sf::Vector2f{windowSize.x - _mSpawnDistanceToEdge,  100.f };
		SwitchRow();
	}
	void VanguardStage::StageFinished()
	{
		TimerManager::Get().ClearTimer(_mSpawnTimerHandle);
		TimerManager::Get().ClearTimer(_mSwitchTimerHandle);

	}
	void VanguardStage::SpawnVanguard()
	{
		weak<Vanguard> newVanguard = GetWorld()->SpawnActor<Vanguard>();
		newVanguard.lock()->SetActorLocation(_mSpawnLoc);
		++_mCurrentRowVanguardCount;
		if (_mCurrentRowVanguardCount == _mVanguardsPerRow)
		{
			TimerManager::Get().ClearTimer(_mSpawnTimerHandle);
			_mSwitchTimerHandle = TimerManager::Get().SetTimer(GetWeakRef(), &VanguardStage::SwitchRow, _mSwitchInterval, false);
			_mCurrentRowVanguardCount = 0;
		}
	}
	void VanguardStage::SwitchRow()
	{
		LOG("SPAWING STARTED");
		if (_mRowSpawnCount == _mRowsToSpawn)
		{
			FinishStage();
			return;
		}
		else
		{
			if (_mSpawnLoc == _mLeftSpawnLoc)
			{
				_mSpawnLoc = _mRightSpawnLoc;
				LOG("SWITCHING TO RIGHT");
			}
			else
			{
				_mSpawnLoc = _mLeftSpawnLoc;
				LOG("SWITCHING TO LEFT");
			}

			_mSpawnTimerHandle = TimerManager::Get().SetTimer(GetWeakRef(), &VanguardStage::SpawnVanguard, _mSpawnInterval, true);
			++_mRowSpawnCount;
		}

	}
}