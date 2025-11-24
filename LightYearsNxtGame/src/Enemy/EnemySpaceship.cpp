#include "Enemy/EnemySpaceShip.h"
#include "framework/MathUtility.h"

namespace ly
{
	EnemySpaceShip::EnemySpaceShip(World* owningWorld, const std::string& texturePath, float collisionDamage, const List<RewardFactoryFunc> rewards)
		: Spaceship{ owningWorld, texturePath },
		_mCollisionDamage{ collisionDamage },
		_mRewardFactories{rewards}
	{
		SetTeamID(2);
	}
	void EnemySpaceShip::Tick(float deltaTime)
	{
		Spaceship::Tick(deltaTime);
		if (IsActorOutofWindowBounds(GetActorGlobalBounds().width * 2.f))
		{
			Destroy();
		}
	}

	void EnemySpaceShip::SpawnReward()
	{
		// 1. Safety Check: Do we have rewards to give?
		if (_mRewardFactories.size() == 0) return;

		// 2. Logic Fix: Ensure the pick is always a valid index
		// RandomRange(0, size) might return size (e.g., 3.0), so we must handle that.
		int pick = (int)RandomRange(0, _mRewardFactories.size());

		// If pick turned out to be exactly the size (rare floating point edge case), clamp it.
		if (pick >= _mRewardFactories.size())
		{
			pick = _mRewardFactories.size() - 1;
		}

		// 3. Spawn
		weak<Reward> newReward = _mRewardFactories[pick](GetWorld());
		if (!newReward.expired())
		{
			newReward.lock()->SetActorLocation(GetActorLocation());
		}
	}

	void EnemySpaceShip::OnActorBeginOverlap(Actor* other)
	{

		Spaceship::OnActorBeginOverlap(other);
		if (IsOtherHostile(other))
		{
			other->ApplyDamage(_mCollisionDamage);
		}
	}
	void EnemySpaceShip::Blew()
	{
		SpawnReward();
	}
}