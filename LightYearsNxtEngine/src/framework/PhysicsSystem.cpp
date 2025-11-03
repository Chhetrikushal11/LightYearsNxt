#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"

#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_contact.h>

namespace ly
{
	unique<PhysicsSystem> PhysicsSystem::physicsSystem{nullptr}; // instantiate with nullptr to avoid link error
	PhysicsSystem& PhysicsSystem::Get()
	{
		if (!physicsSystem)
		{
			physicsSystem = std::move(unique<PhysicsSystem>{new PhysicsSystem});
		}

		return *physicsSystem;
	}
	void PhysicsSystem::Step(float deltaTime)
	{
		// we are asking Step, it knows two steps deltaTime, how frequent you will update
		_mPhysicsWorld.Step(deltaTime, _mVelocityIterations, _mPositionIterations);

	}
		b2Body* PhysicsSystem::AddListener(Actor* listener)
	{
		// any actor that need to involve the physic simulation they have to call listner
		// and PhyscisSystem will figure out the physics body
		// in our case it will be Actor Global bound
		if (listener->IsPendingDestroy()) return nullptr;
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener); // helps to keep record who gets collided, and cast the collliders as listener
		bodyDef.position.Set(listener->GetActorLocation().x * GetPhysicsScale(), listener->GetActorLocation().y * GetPhysicsScale());
		bodyDef.angle = DegreeToRadians(listener->GetActorRotation());

		b2Body* body = _mPhysicsWorld.CreateBody(&bodyDef);
		
		b2PolygonShape shape;
		auto bound = listener->GetActorGlobalBounds();
		shape.SetAsBox(bound.width/2.f * GetPhysicsScale(), bound.height / 2.f * GetPhysicsScale());

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.friction = true;

		body->CreateFixture(&fixtureDef);

		return body;
	}

		void PhysicsSystem::RemoveListener(b2Body* bodyToRemove)
		{
			// TODO remove of the physics body

		}

	PhysicsSystem::PhysicsSystem()
		:_mPhysicsWorld{b2Vec2{0.f,0.f}},
		// this _mPhysicWorld take the parameter to define gravity yet we don't have gravity hence we are doing the 0.f,0.f
		_mPhysicsScale{ 0.01f }, // here we are shrinking to work on Centimeter.
		_mVelocityIterations{ 8 }, // for natural behavior it need to set at 8
		_mPositionIterations{ 3 }, // for natural behavior it need to set at 3
		_mContactListener{ }

	{
		// need contact listener for contact happen
		_mPhysicsWorld.SetContactListener(&_mContactListener);
		_mPhysicsWorld.SetAllowSleeping(false);

	}

	void PhysicsContactListener::BeginContact(b2Contact* contact)
	{
		Actor* ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		Actor* ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);


		if (ActorA && !ActorA->IsPendingDestroy())
		{
			ActorA->OnActorBeginOverlap(ActorB);
		}

		if (ActorB && !ActorB->IsPendingDestroy())
		{
			ActorB->OnActorBeginOverlap(ActorA);
		}
	}

	void PhysicsContactListener::EndContact(b2Contact* contact)
	{
		Actor* ActorA = nullptr;
		Actor* ActorB = nullptr;

		if (contact->GetFixtureA() && contact->GetFixtureA()->GetBody())
		{
			ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		}

		if (contact->GetFixtureB() && contact->GetFixtureB()->GetBody())
		{
			ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
		}
		if (ActorA && !ActorA->IsPendingDestroy())
		{
			ActorA->OnActorEndOverlap(ActorB);
		}

		if (ActorB && !ActorB->IsPendingDestroy())
		{
			ActorB->OnActorEndOverlap(ActorA);
		}
	}
}