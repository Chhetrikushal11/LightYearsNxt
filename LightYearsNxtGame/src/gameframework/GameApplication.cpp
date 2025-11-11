#include "gameframework/GameApplication.h"
#include "Level/GameLevelOne.h"
#include "framework/AssestManager.h"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication();
}

namespace ly
{
	GameApplication::GameApplication()
		:Application{ 600, 980, "LightYearsNxt", sf::Style::Titlebar | sf::Style::Close }

	{
		AssestManager::Get().SetAssetRootDirectory(GetResourceDir());
		weak<GameLevelOne> newWorld = LoadWorld<GameLevelOne>();
		/*newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();*/
		/*testPlayerSpaceShip = newWorld.lock()->SpawnActor<PlayerSpaceShip>();*/
		/*testPlayerSpaceShip.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");*/
		// actorToDestroy.lock()->SetTexture("C:/Users/kbasnet/Desktop/C++/CompleteGameDevSeries/LightYearsNxt/LightYearsNxtGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		/*testPlayerSpaceShip.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));*/
		// for rotation
		/*testPlayerSpaceShip.lock()->SetActorRotation(0.f);*/

		//weak<Vanguard> testSpaceship = newWorld.lock()->SpawnActor<Vanguard>();
		//testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));
		//to set velocity
		// since we are sending the velocity we will stop giving the velocity
		/*testPlayerSpaceShip.lock()->SetVelocity(sf::Vector2f(0.f, -200.f));*/
		// counter = 0.f;
	}

// 	void GameApplication::Tick(float deltaTime)
//	{
		//counter += deltaTime;
		//if (counter > 10.f)
		//{
		//	if (!testPlayerSpaceShip.expired())
		//	{
		//		testPlayerSpaceShip.lock()->Destroy();
		//	}
		//}
//	}
}