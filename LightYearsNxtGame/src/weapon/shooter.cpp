#include "weapon/shooter.h"

namespace ly
{
	void Shooter::Shoot()
	{
		if (CanShoot() && !InOnCooldown())
		{
			ShootImpl();
		}
	}

	void Shooter::IncrementLevel(int amt)
	{
		if (_mCurrentLevel == _mMaxLevel) return;
		else
		{
			++_mCurrentLevel;

		}
		
	}

	Shooter::Shooter(Actor* owner)
		: _mOwner{ owner },
		_mCurrentLevel{ 1 },
		_mMaxLevel{ 4 }
	{
	}
}