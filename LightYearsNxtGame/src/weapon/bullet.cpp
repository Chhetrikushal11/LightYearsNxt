#include "weapon/bullet.h"

namespace ly
{
	// constructor wise we need to call Actor constructor along with the bullet constructor


	Bullet::Bullet(World* world, Actor* owner, const std::string& texturePath, float speed, float damage)
		:Actor{world, texturePath},
		_mOwner{owner},
		_mSpeed{speed},
		_mDamage{damage}
	{
		SetTeamID(owner->GetTeamID());
	}
	void Bullet::SetSpeed(float newSpeed)
	{
		_mSpeed = newSpeed;
	}

	void Bullet::SetDamage(float newDamage)
	{
		_mDamage = newDamage;
	}

	void Bullet::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		Move(deltaTime);
		if (IsActorOutofWindowBounds(GetActorGlobalBounds().width))
		{
			Destroy();
		}
	}
	void Bullet::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
	}
	void Bullet::OnActorBeginOverlap(Actor* other)
	{
		if (IsOtherHostile(other))
		{
			other->ApplyDamage(GetDamage());
		}
	}
	void Bullet::Move(float deltaTime)
	{
		// as we shoot we want to move the bullet in forward direction
		/*AddActorLocationOffset(GetActorForwardDirection() * _mSpeed * deltaTime);*/

		// for some reason my bullets were travelling in lattitude direction hence I have use GetActorRightDirection and flip the direction
		// to flip the direction I have to scale it by -1.f
		AddActorLocationOffset(GetActorRightDirection() * _mSpeed * deltaTime * -1.f);
	}
}