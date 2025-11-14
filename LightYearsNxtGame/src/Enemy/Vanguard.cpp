#include "Enemy/Vanguard.h"
#include "weapon/bulletshooter.h"

namespace ly
{

	

	Vanguard::Vanguard(World* owingWorld, const std::string& texturePath, const sf::Vector2f& velocity)
		: EnemySpaceShip{ owingWorld, texturePath },
		_mEnemyShooter{ new BulletShooter{this, 1.f, {0.f, -50.f}} } 
	{
		SetVelocity(velocity);
		SetActorRotation(180.f);
	}

	void Vanguard::Tick(float deltaTime)
	{
		EnemySpaceShip::Tick(deltaTime);
		Shoot();
	}

	void Vanguard::Shoot()
	{
		_mEnemyShooter->Shoot();
	}

}