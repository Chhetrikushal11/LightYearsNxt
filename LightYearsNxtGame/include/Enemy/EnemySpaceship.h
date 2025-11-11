#pragma once

#include "spaceship/spaceship.h"

namespace ly
{
	class EnemySpaceShip : public Spaceship
	{
	public:
		EnemySpaceShip(World* owningWorld, const std::string& texturePath, float collisionDamage = 200.f);
		virtual void Tick(float deltaTime) override;

	private:
		float _mCollisionDamage;
		virtual void OnActorBeginOverlap(Actor* other) override;

	};

}