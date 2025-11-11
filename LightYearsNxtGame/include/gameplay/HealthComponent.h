#pragma once
#include "framework/core.h"
#include "framework/Delegate.h"
namespace ly
{
	class HealthComponent
	{
	public:
		HealthComponent(float health, float maxHealth);
		void ChangeHealth(float amt);
		float GetHealth() const { return _mHealth; }
		float GetMaxHealth() const { return _maxHealth; }

		Delegate<float, float, float> onHealthChanged;
		Delegate<float, float, float> onTakenDamage;
		Delegate <> onHealthyEmpty;

	private:
		void TakenDamage(float amt);
		void HealthEmpty();
		void HealthRegen(float amt);
		float _mHealth;
		float _maxHealth;
	};
}