#pragma once

#include "framework/World.h"
#include "framework/TimerManager.h"
namespace ly
{	



	class PlayerSpaceShip;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApp);

	private:
		virtual void BeginPlay() override;
		/*void TimerCallBack_Test();*/
		weak<PlayerSpaceShip> testPlayerSpaceShip;
		TimerHandle timerHandle_Test;
		virtual void InitGameStages() override;
	};
}