#include "Enemy/EnemySpaceShip.h"

namespace ly
{
	EnemySpaceShip::EnemySpaceShip(World* owningWorld, const std::string& texturePath, float collisionDamage)
		: Spaceship{ owningWorld, texturePath },
		_mCollisionDamage{ collisionDamage }
	{
		SetTeamID(2);
	}
	void EnemySpaceShip::Tick(float deltaTime)
	{
		Spaceship::Tick(deltaTime);
		if (IsActorOutofWindowBounds(GetActorGlobalBounds().width))
		{
			Destroy();
		}
	}

	void EnemySpaceShip::OnActorBeginOverlap(Actor* other)
	{

		Spaceship::OnActorBeginOverlap(other);
		if (IsOtherHostile(other))
		{
			other->ApplyDamage(_mCollisionDamage);
		}
	}
}