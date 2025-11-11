#include "VFX/Particle.h"
#include "framework/MathUtility.h"

namespace ly
{
	Particle::Particle(World* owningWorld, const std::string& texturePath)
		: Actor{ owningWorld, texturePath }, _mVelocity{}, _mLifeTime{ 1.f }, _mTimer{}
	{
	}

	void Particle::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);

		Move(deltaTime);
		Fade(deltaTime);

		if (_mTimer.getElapsedTime().asSeconds() == _mLifeTime)
		{
			Destroy();
		}
	}
	void Particle::RandomVelocity(float minSpeed, float maxSpeed)
	{
		_mVelocity = RandomUnitVector() * RandomRange(minSpeed, maxSpeed);

	}
	void Particle::RandomSize(float min, float max)
	{
		float randScale = RandomRange(min, max);
		GetSprite().setScale(randScale, randScale);
	}
	void Particle::RandomTime(float min, float max)
	{
		_mLifeTime = RandomRange(min, max);
	}
	void Particle::Move(float deltaTime)
	{
		AddActorLocationOffset(_mVelocity * deltaTime);
	}

	void Particle::Fade(float deltaTime)
	{
		float elapsedTime = _mTimer.getElapsedTime().asSeconds();
		GetSprite().setColor(LerpColor(GetSprite().getColor(), sf::Color(255, 255, 255, 0), elapsedTime/_mLifeTime));
		GetSprite().setScale(LerpVector(GetSprite().getScale(), sf::Vector2f{ 0,0 }, elapsedTime / _mLifeTime));

	}

}