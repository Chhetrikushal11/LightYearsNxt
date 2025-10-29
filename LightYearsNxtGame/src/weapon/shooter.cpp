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

	Shooter::Shooter(Actor* owner)
		: _mOwner{owner}
	{
	}
}