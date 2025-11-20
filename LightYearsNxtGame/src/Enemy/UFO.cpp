#include "Enemy/UFO.h"
#include "weapon/bulletshooter.h"

namespace ly
{
	UFO::UFO(World* owingWorld, const sf::Vector2f& velocity, const std::string& texturePath,float  rotationSpeed)
		:EnemySpaceShip{owingWorld,texturePath},
		_mRotationSpeed{rotationSpeed},
		_mShooter1{ new BulletShooter{this, 1.f,{0.f, 0.f}, -60.f} },
		_mShooter2{ new BulletShooter{this, 1.f,{0.f, 0.f}, 60.f} },
		_mShooter3{ new BulletShooter{this, 1.f,{0.f, 0.f}, 180.f} }
	{
		SetVelocity(velocity);
		SetActorRotation(90.f);
	}
	void UFO::Tick(float deltaTime)
	{
		EnemySpaceShip::Tick(deltaTime);
		Shoot();
		AddActorRotationOffset(_mRotationSpeed * deltaTime);
	}

	void UFO::Shoot()
	{
		_mShooter1->Shoot();
		_mShooter2->Shoot();
		_mShooter3->Shoot();
	}

}