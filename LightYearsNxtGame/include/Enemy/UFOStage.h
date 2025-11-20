#pragma once
#include <SFML/Graphics.hpp>

#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"

namespace ly
{
	class UFOStage : public GameStage
	{
	public:
		UFOStage(World* world);
		virtual void StartStage() override;

	private:
		virtual void StageFinished() override;
		void SpawnUFO();
		sf::Vector2f GetRandomSpawnLoc();

		float _mSpawnInterval;
		int _mCurrentSpawnAmt;
		int _mSpawnAmt;

		float _mUFOSpeed;

		TimerHandle _mSpawnTimer;

	};
}