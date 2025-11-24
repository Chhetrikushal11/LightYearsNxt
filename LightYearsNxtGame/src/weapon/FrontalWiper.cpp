#include "weapon/FrontalWiper.h"

namespace ly
{
	FrontalWiper::FrontalWiper(Actor* owner, float cooldownTime, const sf::Vector2f& localOffset, float width)
		:Shooter{ owner },
		_mWidth{width},
		_mShooter1{ owner, cooldownTime, localOffset + sf::Vector2f{-30, 10}, 0.f,"SpaceShooterRedux/PNG/Lasers/laserGreen11.png" },
		_mShooter2{ owner, cooldownTime, localOffset + sf::Vector2f{-10,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserBlue13.png" },
		_mShooter3{ owner, cooldownTime, localOffset + sf::Vector2f{10,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserBlue13.png" },
		_mShooter4{ owner, cooldownTime, localOffset + sf::Vector2f{30,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserGreen11.png" },
		_mShooter5{ owner, 0.1, localOffset + sf::Vector2f{-40,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserGreen11.png" },
		_mShooter6{ owner, 0.1, localOffset + sf::Vector2f{40,10},0.f,"SpaceShooterRedux/PNG/Lasers/laserGreen11.png" }
	{
	}

	void FrontalWiper::IncrementLevel(int amt)
	{
		Shooter::IncrementLevel(amt);
		_mShooter1.IncrementLevel(amt);
		_mShooter2.IncrementLevel(amt);
		_mShooter3.IncrementLevel(amt);
		_mShooter4.IncrementLevel(amt);
	}

	void FrontalWiper::ShootImpl()
	{
		_mShooter1.Shoot();
		_mShooter2.Shoot();
		_mShooter3.Shoot();
		_mShooter4.Shoot();

		if (GetCurrentLevel() == GetMaxLevel())
		{
			_mShooter5.Shoot();
			_mShooter6.Shoot();
		}
	}
}