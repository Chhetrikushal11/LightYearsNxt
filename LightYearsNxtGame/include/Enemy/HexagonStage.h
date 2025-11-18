#pragma once
#include <SFML/Graphics.hpp>

#include "Enemy/Hexagon.h"
#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"

namespace ly
{
	class HexagonStage : public GameStage
	{
	public:
		HexagonStage(World* world);
		virtual void StartStage() override;
	private:
		virtual void StageFinished() override;
		void SpawnHexagon();

		float _mSpawnInterval;
		float _mSideSpawnOffset;

		int _mSpwanGroupAmt;
		int _mCurrentSpawnCount;

		sf::Vector2f _mMidSpawnLoc;
		sf::Vector2f _mLeftSpawnLoc;
		sf::Vector2f _mRightSpawnLoc;

		TimerHandle _mSpawnTimer;
	};

}