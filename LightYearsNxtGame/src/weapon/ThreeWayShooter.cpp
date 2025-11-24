#include "weapon/ThreeWayShooter.h"

namespace ly
{
	ThreeWayShooter::ThreeWayShooter(Actor* owner, float cooldownTime, const sf::Vector2f& localOffset)
		: Shooter{ owner },
		_mShooterLeft{ owner, cooldownTime, localOffset + sf::Vector2f{-2, 10}, -30.f,"SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		_mShooterMid{ owner, cooldownTime, localOffset + sf::Vector2f{0, 10}, 0.f, "SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		_mShooterRight{ owner, cooldownTime, localOffset + sf::Vector2f{2,10}, 30.f,"SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		_mTopLevelShooterLeft{ owner, cooldownTime, localOffset + sf::Vector2f{-2, 10}, -15.f,"SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		_mTopLevelShooterRight{ owner, cooldownTime, localOffset + sf::Vector2f{-2, 10}, 15.f,"SpaceShooterRedux/PNG/Lasers/laserRed01.png" }
	{
	}

	void ThreeWayShooter::IncrementLevel(int amt)
	{	
		_mShooterLeft.IncrementLevel(amt);
		_mShooterRight.IncrementLevel(amt);
		_mShooterMid.IncrementLevel(amt);

		_mTopLevelShooterLeft.IncrementLevel(amt);
		_mTopLevelShooterRight.IncrementLevel(amt);
	}

	void ThreeWayShooter::ShootImpl()
	{
		_mShooterLeft.Shoot();
		_mShooterMid.Shoot();
		_mShooterRight.Shoot();

		if (GetCurrentLevel() == GetMaxLevel())
		{
			_mTopLevelShooterLeft.Shoot();
			_mTopLevelShooterRight.Shoot();
		}
	}
}