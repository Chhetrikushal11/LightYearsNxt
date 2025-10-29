#pragma once
#include "framework/Actor.h"

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



	private:
		sf::Vector2f _mVelocity;
	};
}