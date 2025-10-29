#pragma once

#include "spaceship/spaceship.h"
#include "framework/World.h"

// to handle the input 
#include "SFML/System.hpp"
#include "weapon/bulletshooter.h"



namespace ly
{
	class BulletShooter;
	class PlayerSpaceShip : public Spaceship
	{
	public:
		PlayerSpaceShip(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");
	
		// we need to own right to tick
		virtual void Tick(float deltaTime) override;

		// to set speed 
		void SetSpeed(float newSpeed) { _mSpeed = newSpeed; }

		// to get the speed
		float GetSpeed() const { return _mSpeed;  }

		// for shooting mechanics
		virtual void Shoot() override;

	private:
			// to handle the input we need to create function to private function
			void HandleInput();
			sf::Vector2f _mMoveInput;

			// to clamping speed
			void NormalizeInput();

			// for checking the boundary
			void ClampInputOnEdge();

			// to make the input work we need make the function to consume the input
			void ConsumeInput(float deltatime);

			// for speed
			float _mSpeed;

			// for shooting
			unique<BulletShooter> _mShooter;
			

	};
}