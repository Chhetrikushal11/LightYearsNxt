#include "weapon/bulletshooter.h"
#include "framework/core.h"

namespace ly 
{
	BulletShooter::BulletShooter(Actor* owner, float cooldownTime, const sf::Vector2f& localPositionOffset, float localRotationOffset, const std::string& bulletTexturePath)
		:Shooter{ owner },
		_mCooldownClock{},
		_mCooldownTime{ cooldownTime },
		_mLocalPositionOffset{ localPositionOffset },
		_mLocalRotationOffset{ localRotationOffset },
		_mBulletTexturePath{bulletTexturePath}
	{
	}
	bool BulletShooter::InOnCooldown() const
	{
		if (_mCooldownClock.getElapsedTime().asSeconds() > _mCooldownTime / GetCurrentLevel())
		{
			return false;
		}
		return true;
	}

	void BulletShooter::SetBulletTexturePath(const std::string& newBulletTexturePath)
	{
		_mBulletTexturePath = newBulletTexturePath;
	}

	void BulletShooter::IncrementLevel(int amt)
	{
		Shooter::IncrementLevel(amt);
	}

	void BulletShooter::ShootImpl()
	{
		sf::Vector2f ownerForwardDir = GetOwner()->GetActorForwardDirection();
		sf::Vector2f ownerRightDir = GetOwner()->GetActorRightDirection();

		_mCooldownClock.restart();
		weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner(), _mBulletTexturePath);
		// to set the location
		newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation() + ownerForwardDir * _mLocalPositionOffset.x + ownerRightDir * _mLocalPositionOffset.y);
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation() + _mLocalRotationOffset);
	}
}

