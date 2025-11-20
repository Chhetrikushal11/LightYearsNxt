#pragma once

#include "Enemy/EnemySpaceship.h"

namespace ly
{
	class BulletShooter;
	class UFO : public EnemySpaceShip
	{
	public:
			UFO(World* owingWorld, const sf::Vector2f& velocity,const std::string& texturePath = "SpaceShooterRedux/PNG/ufoBlue.png", float rotationSpeed = 40.f);
			virtual void Tick(float deltaTime) override;
			virtual void Shoot() override;

	private:
		unique<BulletShooter> _mShooter1;
		unique<BulletShooter> _mShooter2;
		unique<BulletShooter> _mShooter3;

		float _mRotationSpeed;

	};
}