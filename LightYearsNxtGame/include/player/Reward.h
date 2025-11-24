#pragma once
#include <functional>
#include "framework/Actor.h"

namespace ly
{
	class PlayerSpaceShip;
	class Reward; // forward declaration so that we can make RewardFactoryFunc and RewardFunc work
	using RewardFactoryFunc = std::function<weak<Reward>(World*)>;
	using RewardFunc = std::function<void(PlayerSpaceShip*)>;
	class Reward : public Actor
	{
	public:
		Reward(World* world, const std::string& texturePath, RewardFunc rewardFunc, float speed = 200.f);
		virtual void BeginPlay() override;
		virtual void Tick(float deltaTime) override;

	private:
		virtual void OnActorBeginOverlap(Actor* otherActor) override;
		float _mSpeed;
		RewardFunc _mRewardFunc;
	};

	weak<Reward> CreateHealthReward(World* world);
	weak<Reward> CreateThreeWayShooterReward(World* world);
	weak<Reward> CreateFrontalWiperReward(World* world);

	weak<Reward> CreateReward(World* world, const std::string& texturePath, RewardFunc rewardFunc);
	void RewardHealth(PlayerSpaceShip* player);
	void RewardThreeWayShooter(PlayerSpaceShip* player);
	void RewardFrontWiper(PlayerSpaceShip* player);
}