#include "Enemy/Hexagon.h"
#include "weapon/bulletshooter.h"

namespace ly
{

		Hexagon::Hexagon(World* owingWorld, const std::string& texturePath, const sf::Vector2f& velocity)
		: EnemySpaceShip{ owingWorld, texturePath },
		_mShooter1{ new BulletShooter{this, 1.f, {30.f, -30.f},30.f} },
		_mShooter2{ new BulletShooter{this, 1.f, {-30.f, -30.f},-30.f} },
		_mShooter3{ new BulletShooter{this, 1.f, {10.f, 0.f},180.f} },
		_mShooter4{ new BulletShooter{this, 1.f, {-10.f,0.f}, 180.f} },
		_mShooter5{ new BulletShooter{this, 1.f, {30.f, 60.f}, 210.f} },
		_mShooter6{ new BulletShooter{this, 1.f, {-30.f, 60.f}, -210.f} }
	{
			SetVelocity(velocity);
			SetActorRotation(0.f);
	}
	void Hexagon::Tick(float deltaTime)
	{	
		EnemySpaceShip::Tick(deltaTime);
		Shoot();
	}

	void Hexagon::Shoot()
	{
		_mShooter1->Shoot();
		_mShooter2->Shoot();
		_mShooter3->Shoot();
		_mShooter4->Shoot();
		_mShooter5->Shoot();
		_mShooter6->Shoot();
	}


}
