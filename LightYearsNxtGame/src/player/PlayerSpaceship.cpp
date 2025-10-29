#include "player/PlayerSpaceship.h"
// to handle the input 
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace ly
{
	PlayerSpaceShip::PlayerSpaceShip(World* owningWorld, const std::string& path )
	:Spaceship{ owningWorld, path },
	_mMoveInput{},
	_mSpeed{ 200 },
	_mShooter{new BulletShooter{this, 0.1f} }
	{
	}
	void PlayerSpaceShip::Tick(float deltaTime)
	{
		Spaceship::Tick(deltaTime);
		HandleInput();
		ConsumeInput(deltaTime);
	}
	void PlayerSpaceShip::Shoot()
	{
		if (_mShooter)
		{
			_mShooter->Shoot();
		}
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
		
		// since we are keeping left righ and updown in seprate condition we can move the space ship diagonally.
		// to move towards left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_mMoveInput.x = -1.f;
		}

		// to move towards right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_mMoveInput.x = 1.f;
		}

		ClampInputOnEdge();
		NormalizeInput();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Shoot();
		}
	}
	void PlayerSpaceShip::NormalizeInput()
	{
		Normalize(_mMoveInput); // since we are doing pass by reference we can use function_name(parameter_name)
		// LOG("Moveinput is now: %f, %f", _mMoveInput.x, _mMoveInput.y);
	}
	void PlayerSpaceShip::ClampInputOnEdge()
	{
		sf::Vector2f actorLocation = GetActorLocation();

		// for x-axis --------------------
		if (actorLocation.x < 0 && _mMoveInput.x == -1.f) // if actor is trying to move outside the left boundary
		{
			_mMoveInput.x = 0.f;
			LOG("Going Outside the Left boundary.");
		}
		if (actorLocation.x > GetWindowSize().x && _mMoveInput.x == 1.f) // if actor is trying to move outside the right boundary
		{
			_mMoveInput.x = 0.f;
			LOG("Going Outside the Right boundary.");
		}

		// for y-axis --------------------
		if (actorLocation.y < 0 && _mMoveInput.y == -1.f) // if actor is trying to move upward
		{
			_mMoveInput.y = 0.f;
			LOG("Going Outside the Upper boundary.");
		}
		if (actorLocation.y > GetWindowSize().y && _mMoveInput.y == 1.f) // if actor is trying to move downward
		{
			_mMoveInput.y = 0.f;
			LOG("Going Outside the Lower boundary.");
		}

	}
	void PlayerSpaceShip::ConsumeInput(float deltatime)
	{
		SetVelocity(_mMoveInput * _mSpeed);
		// this way we stop moving after one click
		_mMoveInput.x = _mMoveInput.y = 0;
	}
}