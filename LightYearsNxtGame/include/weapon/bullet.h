#pragma once

#include "framework/Actor.h"

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

	private:
		void Move(float deltaTime);
		Actor* _mOwner;
		float _mSpeed;
		float _mDamage;
	};
}