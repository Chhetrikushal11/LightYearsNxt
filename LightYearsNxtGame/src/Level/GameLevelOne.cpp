#include "Level/GameLevelOne.h"
#include "framework/Actor.h"
#include "spaceship/spaceship.h"
#include "framework/AssestManager.h"
#include "player/PlayerSpaceship.h"
#include "framework/TimerManager.h"
#include "Enemy/Vanguard.h"
#include "gameplay/GameStage.h"
#include "gameplay/WaitStage.h"
#include "Enemy/VanguardStage.h"
#include "Enemy/TwinBladeStage.h"
#include "Enemy/HexagonStage.h"
#include "Enemy/UFOStage.h"
#include "player/PlayerManager.h"

namespace ly
{


	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{

		// testPlayerSpaceShip = SpawnActor<PlayerSpaceShip>();
		/*testPlayerSpaceShip.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");*/
		// actorToDestroy.lock()->SetTexture("C:/Users/kbasnet/Desktop/C++/CompleteGameDevSeries/LightYearsNxt/LightYearsNxtGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		// testPlayerSpaceShip.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		// for rotation
		/*testPlayerSpaceShip.lock()->SetActorRotation(0.f);*/

		//weak<Vanguard> testSpaceship = SpawnActor<Vanguard>();
		//testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));

	}
	void GameLevelOne::BeginPlay()
	{
		Player newPlayer = PlayerManager::Get().CreateNewPlayer();
		_mPlayerSpaceShip = newPlayer.SpawnSpaceship(this);
		_mPlayerSpaceShip.lock()->SetActorRotation(0.f);
		_mPlayerSpaceShip.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceShipDestroyed);
	}
	//void GameLevelOne::TimerCallBack_Test()
	//{
	//	LOG("CallBack called!!");
	//	TimerManager::Get().ClearTimer(timerHandle_Test);
	//	// how they are intertwined with Callback
	//}

	void GameLevelOne::PlayerSpaceShipDestroyed(Actor* destroyedPalyerSpaceship)
	{
		_mPlayerSpaceShip = PlayerManager::Get().GetPlayer()->SpawnSpaceship(this);
		_mPlayerSpaceShip.lock()->SetActorRotation(0.f);
		if (!_mPlayerSpaceShip.expired())
		{
			_mPlayerSpaceShip.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceShipDestroyed);
		}
		else
		{
			GameOver();
		}
	}

	void GameLevelOne::InitGameStages()
	{
		AddStage(shared<WaitStage>{new WaitStage{ this, 0.5f }});
	    AddStage(shared<VanguardStage>{new VanguardStage{ this }});
		AddStage(shared<WaitStage>{new WaitStage{ this, 15.f }}); // waiting 15seconds
		AddStage(shared<TwinBladeStage>{new TwinBladeStage{ this }});
		AddStage(shared<WaitStage>{new WaitStage{ this, 15.f }}); // waiting 15seconds
		AddStage(shared<HexagonStage>{new HexagonStage{ this }});              

		AddStage(shared<WaitStage>{new WaitStage{ this, 15.f }}); // waiting 15seconds
		AddStage(shared<UFOStage>{new UFOStage{ this }});
	}

	void GameLevelOne::GameOver()
	{
		LOG("==========Game Over================!!");
	}

}