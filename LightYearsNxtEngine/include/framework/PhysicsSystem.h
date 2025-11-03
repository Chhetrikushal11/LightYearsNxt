#pragma once
#include "framework/core.h"
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>

namespace ly
{
    class Actor;
    class PhysicsContactListener : public b2ContactListener
    {
        virtual void BeginContact(b2Contact* contact) override;
        virtual void EndContact(b2Contact* contact) override;
       
    };
    class PhysicsSystem
    {
    public:
        static PhysicsSystem& Get();
        void Step(float deltaTime);
        b2Body* AddListener(Actor* listener);
        void RemoveListener(b2Body* bodyToRemove);
        float GetPhysicsScale() const { return _mPhysicsScale; }

    protected:
        PhysicsSystem();

    private:
        static unique<PhysicsSystem> physicsSystem;
        b2World _mPhysicsWorld;
        float _mPhysicsScale;
        int _mVelocityIterations;
        int _mPositionIterations;
        PhysicsContactListener _mContactListener;

    };
}