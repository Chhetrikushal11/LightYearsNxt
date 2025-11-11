#pragma once
#include "framework/Actor.h"
#include "gameplay/HealthComponent.h"
#include"framework/Delegate.h"

namespace ly
{
	// this class is being inherited by class Actor
	class Spaceship:public Actor
	{
	public:
			Spaceship(World* owingWorld, const std::string& texturePath = "");
			
			// to override this function we will create virtual void
			// so we use override word at the end
			virtual void Tick(float deltaTime) override;

			// to set the velocity
			void SetVelocity(const sf::Vector2f& newVel);

			// we need velocity 
			sf::Vector2f GetVelocity() const { return _mVelocity; }

			// for shooting mechanics
			virtual void Shoot();

			// for using physics body
			virtual void BeginPlay() override;

			// for Apply damage
			virtual void ApplyDamage(float amt) override;


	private:
		void Blink();
		void UpdateBlink(float deltaTime);
		virtual void OnHealthChanged(float amt, float health, float maxHealth);
		virtual void OnTakenDamage(float amt, float health, float maxHealth);
		virtual void Blow();
		sf::Vector2f _mVelocity;
		HealthComponent _mhealthComp;

		float _mBlinkTime;
		float _mBlinkDuration;
		sf::Color _mBlinkColorOffset;
	};
}