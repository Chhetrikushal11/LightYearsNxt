#include "spaceship/spaceship.h"
#include "framework/MathUtility.h"
#include "VFX/Explosion.h"

namespace ly
{
	// here in constructor we will call the Actor class for the parameters
	Spaceship::Spaceship(World* owingWorld, const std::string& texturePath )
		: Actor{ owingWorld, texturePath },
		_mVelocity{},
		_mhealthComp{100.f,100.f},
		_mBlinkTime{},
		_mBlinkDuration{ 0.2f },
		_mBlinkColorOffset{ 255,0,0, 255 } // last value 255 is it is pure red not transparent
	{

	}

	void Spaceship::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset(GetVelocity() * deltaTime);
		UpdateBlink(deltaTime);
	}

	void Spaceship::SetVelocity(const sf::Vector2f& newVel)
	{
		_mVelocity = newVel;
	}

	void Spaceship::Shoot()
	{

	}
	void Spaceship::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
		_mhealthComp.onHealthChanged.BindAction(GetWeakRef(), &Spaceship::OnHealthChanged);
		_mhealthComp.onTakenDamage.BindAction(GetWeakRef(), &Spaceship::OnTakenDamage);
		_mhealthComp.onHealthyEmpty.BindAction(GetWeakRef(), &Spaceship::Blow);

		
		

		// this creates a lambda function
		// [] is called capture list
		// we can use header file <functional> to use desired data type
		/*
		* syntax will look like
		*  std::function<void(parameter datatype,....., parameter datatype)> func = [](parameter datatype var1, ......, parameter datatype varN)
		* {
		*		// type the logic you want
		* }
		*/
		//auto func = [](float var)
		//	{
		//		LOG("the value of var is %f", var);
		//	};

		//func(12);
	}
	void Spaceship::ApplyDamage(float amt)
	{
		_mhealthComp.ChangeHealth(-amt);
	}
	void Spaceship::Blink()
	{
		if (_mBlinkTime == 0)
		{
			_mBlinkTime = _mBlinkDuration;
		}
	}
	void Spaceship::UpdateBlink(float deltaTime)
	{
		if (_mBlinkTime > 0)
		{
			_mBlinkTime -= deltaTime;
			_mBlinkTime = _mBlinkTime > 0 ? _mBlinkTime : 0.f;

			GetSprite().setColor(LerpColor(sf::Color::White, _mBlinkColorOffset, _mBlinkTime));

		}
	}
	void Spaceship::OnHealthChanged(float amt, float health, float maxHealth)
	{
		LOG("health changed by:%f, and is now: %f/%f", amt, health, maxHealth);
	}
	void Spaceship::OnTakenDamage(float amt, float health, float maxHealth)
	{
		Blink();
	}

	void Spaceship::Blow()
	{
		Explosion* exp = new Explosion();
		exp->SpawnExplosion(GetWorld(), GetActorLocation());
		Destroy();
		delete exp;
	}
}