#include "Enemy/UFOStage.h"
#include "Enemy/UFO.h"
#include "framework/MathUtility.h"
#include "framework/World.h"


namespace ly
{
	UFOStage::UFOStage(World* world)
		:GameStage{world},
		_mSpawnInterval{4.f},
		_mSpawnAmt{10},
		_mCurrentSpawnAmt{0},
		_mUFOSpeed{200.f}
	{
	}
	void UFOStage::StartStage()
	{
		_mSpawnTimer = TimerManager::Get().SetTimer(GetWeakRef(), &UFOStage::SpawnUFO, _mSpawnInterval, true);

	}

	void UFOStage::StageFinished()
	{
		TimerManager::Get().ClearTimer(_mSpawnTimer);
	}



	sf::Vector2f UFOStage::GetRandomSpawnLoc()
	{	
		auto windowSize = GetWorld()->GetWindowsSize();
		float spawnLeft = RandomRange(-1, 1);
		float spawnLocX = 0;
		if (spawnLeft < 0)
		{
			spawnLocX = windowSize.x / 2.f + 100.f;
			LOG("SPAWING IN RIGHT");
		}

		else
		{
			spawnLocX = -50.0f;
			LOG("SPAWING IN LEFT");
		}

		float spawnLocY = RandomRange(0, windowSize.y);
		return sf::Vector2f{ spawnLocX, spawnLocY };
	}
	void UFOStage::SpawnUFO()
	{
		sf::Vector2f spawnLoc = GetRandomSpawnLoc();
		auto windowSize = GetWorld()->GetWindowsSize();
		sf::Vector2f center{ windowSize.x / 2.f, windowSize.y / 2.f };
		sf::Vector2f spawnLocToCenter{ center.x - spawnLoc.x, center.y - spawnLoc.y };
		Normalize(spawnLocToCenter);

		sf::Vector2f spawnVelocity = spawnLocToCenter * _mUFOSpeed;
		weak<UFO> newUFO = GetWorld()->SpawnActor<UFO>(spawnVelocity);
		newUFO.lock()->SetActorLocation(spawnLoc);

		if (++_mCurrentSpawnAmt == _mSpawnAmt)
		{
			FinishStage();
		}

	}

}