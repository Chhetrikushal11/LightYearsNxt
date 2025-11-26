#include "player/player.h"
#include "framework/World.h"
#include "player/PlayerSpaceship.h"
#include "framework/Actor.h"

namespace ly
{
	Player::Player()
		: _mLifeCount{ 3 },
		_mScore{ 0 },
		_mCurrentPlayerSpaceship{}
	{
	}
	weak<PlayerSpaceShip> Player::SpawnSpaceship(World * world)
	{
		if (_mLifeCount > 0)
		{
			--_mLifeCount;
			auto windowSize = world->GetWindowsSize();
			_mCurrentPlayerSpaceship = world->SpawnActor<PlayerSpaceShip>();
			_mCurrentPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(windowSize.x/2, windowSize.y/2 - 50.f));
			// for rotation
			_mCurrentPlayerSpaceship.lock()->SetActorRotation(-90.f);
			onLifeChange.Broadcast(_mLifeCount);
			return _mCurrentPlayerSpaceship;

		}
		else
		{
			onLifeExhausted.Broadcast();
		}

		return weak<PlayerSpaceShip>{};

	}
	void Player::AddLifeCount(unsigned int count)
	{
		if (count > 0)
		{
			_mLifeCount += count;
			onLifeChange.Broadcast(_mLifeCount);
		}
		
	}
	void Player::AddScore(unsigned int amt)
	{
		if (amt > 0)
		{
			_mScore = amt;
			onScoreChange.Broadcast(_mScore);
		}
		
	}
	
}