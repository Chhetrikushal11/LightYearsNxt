#pragma once
#include <SFML/Graphics.hpp>

#include "Enemy/Vanguard.h"
#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"

namespace ly
{
	class VanguardStage : public GameStage
	{
	public:
		VanguardStage(World* world);
		virtual void StartStage() override;

	private:
		float _mSpawnInterval;
		float _mSwitchInterval;
		float _mSpawnDistanceToEdge;

		sf::Vector2f _mLeftSpawnLoc;
		sf::Vector2f _mRightSpawnLoc;
		sf::Vector2f _mSpawnLoc;

		TimerHandle _mSpawnTimerHandle;
		TimerHandle _mSwitchTimerHandle;

		int _mRowsToSpawn;
		int _mRowSpawnCount;

		int _mVanguardsPerRow;
		int _mCurrentRowVanguardCount;
		virtual void StageFinished() override;
		void SpawnVanguard();
		void SwitchRow();
	};
}

