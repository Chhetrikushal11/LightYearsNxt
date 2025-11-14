#pragma once
#include <SFML/Graphics.hpp>

#include "Enemy/TwinBlade.h"
#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"

namespace ly
{
	class TwinBladeStage : public GameStage
	{
	public:
		TwinBladeStage(World* world);
		virtual void StartStage() override;
	private:
		float _mSpawnInterval;
		float _mSpawnDistanceToCenter;


		sf::Vector2f _mLeftSpawnLoc;
		sf::Vector2f _mRightSpawnLoc;
		sf::Vector2f _mSpawnLoc;

		TimerHandle _mSpawnTimerHandle;


		int _mSpawnAmt;
		int _mCurrentSpawnCount;

		void SpawnTwinBlade();
		virtual void StageFinshed();

	};
}