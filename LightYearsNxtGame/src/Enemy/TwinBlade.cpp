#include "Enemy/TwinBlade.h"
#include "weapon/bulletshooter.h"

namespace ly
{
	TwinBlade::TwinBlade(World* owingWorld, const std::string& texturePath, const sf::Vector2f& velocity)
		: EnemySpaceShip{ owingWorld, texturePath },
		_mShooterLeft{ new BulletShooter{this, 1.f, {30.f, -30.f}} }, // why we make dynamic pointer on this 
		_mShooterRight{ new BulletShooter{this, 1.f,{-30.f,-30.f}} }

	{
		SetVelocity(velocity);
		SetActorRotation(180.f);
	}
	void TwinBlade::Tick(float deltaTime)
	{
		EnemySpaceShip::Tick(deltaTime);
		Shoot();
	}

	void TwinBlade::Shoot()
	{
		_mShooterLeft->Shoot();
		_mShooterRight->Shoot();
	}


}