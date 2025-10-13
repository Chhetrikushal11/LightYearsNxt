#pragma once
#include "framework/Object.h"

namespace ly {
	// need to forward declare Application since it will own the world
	class World;

	// inheritance
;	class Actor : public Object
{
	public:
		Actor(World* owningWorld);
		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		// we use virtual destructor when we use inheritance.
		// otherwise it will not call parent destructor.
		virtual ~Actor();
	private:
	
		World* _mowningWorld;
		bool _mHasBeganPlay;

	

	};
}