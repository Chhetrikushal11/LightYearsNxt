#pragma once

#include "framework/Actor.h"
#include "framework/core.h"
#include "framework/World.h"

namespace ly
{
	class Bullet : public Actor
	{
	public:
		Bullet(World* world, Actor* owner, const std::string& texturePath, float speed = 800.f, float damage = 10.f);
		void SetSpeed(float newSpeed);
		void SetDamage(float Damage);
		float GetSpeed() const { return _mSpeed;}
		float GetDamage() const { return _mDamage; }

		// we need to override the Tick function
		virtual void Tick(float deltaTime);

		// to use physics system
		virtual void BeginPlay() override;

	private:
		virtual void OnActorBeginOverlap(Actor* other) override;
		void Move(float deltaTime);
		Actor* _mOwner;
		float _mSpeed;
		float _mDamage;
	};
}