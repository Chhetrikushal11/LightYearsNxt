#pragma once

#include "spaceship/spaceship.h"
#include "player/Reward.h"

namespace ly
{
	class EnemySpaceShip : public Spaceship
	{
	public:
		EnemySpaceShip(World* owningWorld, 
			const std::string& texturePath, 
			float collisionDamage = 200.f,
			const List<RewardFactoryFunc> rewards =
			{
				CreateHealthReward,
				CreateThreeWayShooterReward,
				CreateFrontalWiperReward
			}
		);
		virtual void Tick(float deltaTime) override;

	private:
		void SpawnReward();
		float _mCollisionDamage;
		virtual void OnActorBeginOverlap(Actor* other) override;
		virtual void Blew() override;
		List<RewardFactoryFunc> _mRewardFactories;

	};

}