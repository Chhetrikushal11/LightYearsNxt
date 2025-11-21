#include "weapon/FrontalWiper.h"

namespace ly
{
	FrontalWiper::FrontalWiper(Actor* owner, float cooldownTime, const sf::Vector2f& localOffset)
		:Shooter{ owner },
		_mShooter1{ owner, cooldownTime, localOffset + sf::Vector2f{-30, 10}, 0.f,"SpaceShooterRedux/PNG/Lasers/laserGreen11.png" },
		_mShooter2{ owner, cooldownTime, localOffset + sf::Vector2f{-10,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserBlue13.png" },
		_mShooter3{ owner, cooldownTime, localOffset + sf::Vector2f{10,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserBlue13.png" },
		_mShooter4{ owner, cooldownTime, localOffset + sf::Vector2f{30,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserGreen11.png" }
	{
	}

	void FrontalWiper::ShootImpl()
	{
		_mShooter1.Shoot();
		_mShooter2.Shoot();
		_mShooter3.Shoot();
		_mShooter4.Shoot();
	}
}