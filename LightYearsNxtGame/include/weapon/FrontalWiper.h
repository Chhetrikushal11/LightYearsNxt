#pragma once

#include <SFML/Graphics.hpp>
#include "weapon/bulletshooter.h"

namespace ly
{
	class FrontalWiper : public Shooter
	{
	public:
		FrontalWiper(Actor* owner, float cooldownTime = 0.3f, const sf::Vector2f& localOffset = { 0.f, 0.f } );

		BulletShooter _mShooter1;
		BulletShooter _mShooter2;
		BulletShooter _mShooter3;
		BulletShooter _mShooter4;

	private:
		virtual void ShootImpl();

	};

}