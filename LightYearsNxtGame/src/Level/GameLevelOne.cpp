#include "Level/GameLevelOne.h"
#include <framework/Actor.h>
#include "spaceship/spaceship.h"
#include "framework/AssestManager.h"
#include "player/PlayerSpaceship.h"
#include "Enemy/Vanguard.h"

namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{

		testPlayerSpaceShip = SpawnActor<PlayerSpaceShip>();
		/*testPlayerSpaceShip.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");*/
		// actorToDestroy.lock()->SetTexture("C:/Users/kbasnet/Desktop/C++/CompleteGameDevSeries/LightYearsNxt/LightYearsNxtGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		testPlayerSpaceShip.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		// for rotation
		testPlayerSpaceShip.lock()->SetActorRotation(0.f);

		weak<Vanguard> testSpaceship = SpawnActor<Vanguard>();
		testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));
	}
}