#pragma once
#include "weapon/shooter.h"
#include "weapon/bullet.h"
#include <SFML/System.hpp>


namespace ly
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* owner, float cooldownTime = 1.f);
		virtual bool InOnCooldown() const override;

	private:
		virtual void ShootImpl() override;
		sf::Clock _mCooldownClock;
		float _mCooldownTime;
		

	};
}