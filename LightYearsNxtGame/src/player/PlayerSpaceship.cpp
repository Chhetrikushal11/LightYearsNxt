#include "player/PlayerSpaceship.h"
// to handle the input 
#include "SFML/System.hpp"

namespace ly
{
	PlayerSpaceShip::PlayerSpaceShip(World* owningWorld, const std::string& path )
		:Spaceship{owningWorld, path}, _mMoveInput{}, _mSpeed{200}
	{
	}
	void PlayerSpaceShip::Tick(float deltaTime)
	{
		Spaceship::Tick(deltaTime);
		HandleInput();
		ConsumeInput(deltaTime);
	}
	void PlayerSpaceShip::HandleInput()
	{
	
		// to move upward
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			_mMoveInput.y = -1.f;
		}
		// to move downward
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			_mMoveInput.y = 1.f;
		}
		// to move towards left
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_mMoveInput.x = -1.f;
		}

		// to move towards right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_mMoveInput.x = 1.f;
		}
	}
	void PlayerSpaceShip::ConsumeInput(float deltatime)
	{
		SetVelocity(_mMoveInput * _mSpeed);
		// this way we stop moving after one click
		_mMoveInput.x = _mMoveInput.y = 0;
	}
}