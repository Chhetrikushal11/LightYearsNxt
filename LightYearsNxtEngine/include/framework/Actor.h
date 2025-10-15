#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"
#include "framework/AssestManager.h"
#include "framework/MathUtility.h"

namespace ly {
	// need to forward declare Application since it will own the world
	class World;

	// inheritance
;	class Actor : public Object
{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		void BeginPlayInternal();
		virtual void BeginPlay();
		void TickInternal(float deltaTime);
		virtual void Tick(float deltaTime);
		void SetTexture(const std::string& texturePath);
		// we use virtual destructor when we use inheritance.
		// otherwise it will not call parent destructor.
		virtual ~Actor();
		void Render(sf::RenderWindow& window);

		// setting actor location
		void SetActorLocation(const sf::Vector2f& newLoc);

		// setting actor Rotation
		void SetActorRotation(float newRot);

		// need some hyperfunction to manage the orentation and position of the player
		void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
		void AddActorRotationOffset(float offsetAmt);
		sf::Vector2f GetActorLocation() const;
		float GetActorRotation() const;

		// to get the front vector direction of the actor
		sf::Vector2f GetActorForwardDirection() const;

		// to get the right side vector direction of the actor
		sf::Vector2f GetActorRightDirection() const;


	private:
	
		World* _mowningWorld;
		bool _mHasBeganPlay;

		sf::Sprite _mSprite;
		shared<sf::Texture> _mTexture; // we need to shared pointer


	

	};
}