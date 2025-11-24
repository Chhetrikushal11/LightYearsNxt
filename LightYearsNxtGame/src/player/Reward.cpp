#include "player/Reward.h"
#include "framework/World.h"
#include "player/PlayerSpaceship.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"
namespace ly
{
	Reward::Reward(World* world, const std::string& texturePath, RewardFunc rewardFunc, float speed)
		: Actor{ world, texturePath },
		_mRewardFunc{ rewardFunc },
		_mSpeed{speed}
	{
	}
	void Reward::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
	}
	void Reward::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset({ 0.f, _mSpeed * deltaTime });
	}
	void Reward::OnActorBeginOverlap(Actor* otherActor)
	{	
		// TODO : clean up casting
		PlayerSpaceShip* playerSpaceship = dynamic_cast<PlayerSpaceShip*>(otherActor);
		if (playerSpaceship != nullptr && !playerSpaceship->IsPendingDestroy())
		{
			_mRewardFunc(playerSpaceship);
			Destroy();
		}

	}
	weak<Reward> CreateHealthReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/Power-ups/pill_green.png", RewardHealth);
	}
	weak<Reward> CreateThreeWayShooterReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/Power-ups/things_bronze.png", RewardThreeWayShooter);
	}
	weak<Reward> CreateFrontalWiperReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/Power-ups/powerupGreen_bolt.png", RewardFrontWiper);
	}
	weak<Reward> CreateReward(World* world, const std::string& texturePath, RewardFunc rewardFunc)
	{
		weak<Reward> reward = world->SpawnActor<Reward>(texturePath, rewardFunc);
		return reward;
	}
	void RewardHealth(PlayerSpaceShip* player)
	{
		static float rewardAmt = 10.f;
		if (player && !player->IsPendingDestroy())
		{
			player->GetHealthComp().ChangeHealth(rewardAmt);
			LOG("REWARDED HEALTHBOOST");
		}

	}
	void RewardThreeWayShooter(PlayerSpaceShip* player)
	{
		if (player && !player->IsPendingDestroy())
		{
			player->SetShooter(unique<Shooter>{new ThreeWayShooter{ player , 0.4f, {50.f, 0.f} }});
			LOG("REWARDED THREEWAY SHOOTER ABILITY");
		}
	}
	void RewardFrontWiper(PlayerSpaceShip* player)
	{
		if (player && !player->IsPendingDestroy())
		{
			player->SetShooter(unique<Shooter>{new FrontalWiper{ player, 0.4f, {50.f, 0.f} }});
			LOG("REWARDED FRONTALWIPE SHOOTER ABILITY");
		}
	}
}