#include "gameplay/GameStage.h"
#include "framework/core.h"

namespace ly
{
	GameStage::GameStage(World* world)
		:_mWorld(world),
		_mStageFinished{false}
	{
	}
	void GameStage::StartStage()
	{
		LOG("Stage Started!!!");
	}
	void GameStage::TickStage(float deltaTime)
	{
		
	}

	void GameStage::FinishStage()
	{
		onStageFinished.Broadcast();
		_mStageFinished = true;
		StageFinished();
	}
	void GameStage::StageFinished()
	{
		LOG("Stage Finished.");
	}
}

