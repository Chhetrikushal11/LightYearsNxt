#pragma once
#include "Enemy/EnemySpaceship.h"

namespace ly
{
	class BulletShooter;
	class Hexagon : public EnemySpaceShip
	{
	public:
		Hexagon(World* owingWorld, const std::string& texturePath = "SpaceShooterRedux/PNG/Enemies/enemyGreen4.png", const sf::Vector2f& velocity = { 0.f,100.f });
		virtual void Tick(float deltaTime) override;
		virtual void Shoot() override;
	private:
		unique<BulletShooter> _mShooter1;
		unique<BulletShooter> _mShooter2;
		unique<BulletShooter> _mShooter3;
		unique<BulletShooter> _mShooter4;
		unique<BulletShooter> _mShooter5;
		unique<BulletShooter> _mShooter6;
	};
}