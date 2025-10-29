#include "weapon/bulletshooter.h"
#include "framework/core.h"

namespace ly 
{
	BulletShooter::BulletShooter(Actor* owner ,float cooldownTime)
		:Shooter{ owner },
		_mCooldownClock{},
		_mCooldownTime{cooldownTime}
	{
	}
	bool BulletShooter::InOnCooldown() const
	{
		if (_mCooldownClock.getElapsedTime().asSeconds() > _mCooldownTime)
		{
			return false;
		}
		return true;
	}

	void BulletShooter::ShootImpl()
	{
		_mCooldownClock.restart();
		weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
		// to set the location
		newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation());
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation());
	}
}

