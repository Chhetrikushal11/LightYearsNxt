#pragma once

#include "framework/World.h"
#include "framework/TimerManager.h"
namespace ly
{	

	class PlayerSpaceShip;
	class GamePlayHUD;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApp);

	private:
		virtual void BeginPlay() override;
		/*void TimerCallBack_Test();*/
		weak<PlayerSpaceShip> _mPlayerSpaceShip;
		// need to create weak Pointer for GamePlay HUD
		weak<GamePlayHUD> _mGamePlayHUD;
		void PlayerSpaceShipDestroyed(Actor* destroyedPalyerSpaceship);
		TimerHandle timerHandle_Test;
		virtual void InitGameStages() override;
		void GameOver();
	};
}