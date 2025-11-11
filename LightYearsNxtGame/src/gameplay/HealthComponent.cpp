#include "gameplay/HealthComponent.h"
#include "framework/core.h"



namespace ly 
{
	HealthComponent::HealthComponent(float health, float maxHealth)
		: _mHealth{health},
		_maxHealth{maxHealth}
	{
	}

	void HealthComponent::ChangeHealth(float amt)
	{
		if (amt == 0) return;
		if (_mHealth == 0) return;

		_mHealth += amt;

		if (_mHealth < 0)
		{
			_mHealth = 0;
		}

		if (_mHealth > _maxHealth)
		{
			_mHealth = _maxHealth;
		}

		if (amt < 0)
		{
			TakenDamage(-amt);
			if (_mHealth <= 0)
			{
				HealthEmpty();
			}

			else
			{
				HealthRegen(amt);
			}
			
			onHealthChanged.Broadcast(amt, _mHealth, _maxHealth);

		}

	}
	void HealthComponent::TakenDamage(float amt)
	{
		onTakenDamage.Broadcast(amt, _mHealth, _maxHealth);
	}

	void HealthComponent::HealthEmpty()
	{
		onHealthyEmpty.Broadcast();
	}

	void HealthComponent::HealthRegen(float amt)
	{
		/*LOG("Health Regened: %f, now health is :%f/%f", amt, _mHealth, _maxHealth);*/
	}

}
