#pragma once
#include "weapon/shooter.h"
#include "weapon/bullet.h"
#include <SFML/System.hpp>


namespace ly
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* owner, 
			float cooldownTime = 1.f, 
			const sf::Vector2f& localPositionOffset={0.f,0.f},
			float localRotationOffset = 0.f,
			const std::string& bulletTexturePath = "SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
		virtual bool InOnCooldown() const override;
		void SetBulletTexturePath(const std::string& newBulletTexturePath);
		virtual void IncrementLevel(int amt) override;
	private:
		
		virtual void ShootImpl() override;
		sf::Clock _mCooldownClock;
		float _mCooldownTime;
		
		sf::Vector2f _mLocalPositionOffset;
		float _mLocalRotationOffset;
		std::string _mBulletTexturePath;
	};
}