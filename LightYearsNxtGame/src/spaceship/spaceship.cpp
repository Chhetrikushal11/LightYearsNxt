#include "spaceship/spaceship.h"

namespace ly
{
	// here in constructor we will call the Actor class for the parameters
	Spaceship::Spaceship(World* owingWorld, const std::string& texturePath)
		: Actor{ owingWorld, texturePath },_mVelocity{}
	{

	}

	void Spaceship::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset(GetVelocity() * deltaTime);
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
	}
}