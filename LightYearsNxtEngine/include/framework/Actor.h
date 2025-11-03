#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"
#include "framework/AssestManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"
class b2Body;
namespace ly {
	// for physics body
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

		// for getting window size
		sf::Vector2u GetWindowSize() const;

		// since bulletshooter cannot spawn the actor we neeed to create a pointer of World in the Actor header file
		World* GetWorld() const { return _mowningWorld; }

		// to make sure we have the actor size so we can compare
		sf::FloatRect GetActorGlobalBounds() const;

		// to make sure the bullet gets destoryed if they are out of scope
		bool IsActorOutofWindowBounds() const;

		// allow the interface for physics
		void SetEnablePhysics(bool enable);

		virtual void OnActorBeginOverlap(Actor* other);
		virtual void OnActorEndOverlap(Actor* other);
	private:
		// to initialize physics
		void InitializePhysics();
		void UnInitializePhysics();
		// to update location of the physics body
		void UpdatePhysicsTransform();

		World* _mowningWorld;
		bool _mHasBeganPlay;

		// what does the Sprtie class do?
		sf::Sprite _mSprite;
		shared<sf::Texture> _mTexture; // we need to shared pointer

		// to make our actor at the centre
		void CenterPivot();

		// to make the physics body
		b2Body* _mPhysicsBody;

		bool _mPhysicsEnabled;
		

	

	};
}