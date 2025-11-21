#pragma once

#include <SFML/Graphics.hpp>
#include "weapon/bulletshooter.h"

namespace ly
{
	class ThreeWayShooter : public Shooter
	{
	public:
		ThreeWayShooter(Actor* owner, float cooldownTime = 0.3f, const sf::Vector2f& localOffset = { 0.f, 0.f });

		BulletShooter _mShooterLeft;
		BulletShooter _mShooterMid;
		BulletShooter _mShooterRight;

	private:
		virtual void ShootImpl();
	};
}

