#include "framework/Actor.h"
#include "framework/core.h"
#include "framework/World.h"

namespace ly{

	Actor::Actor(World * owningWorld)
		:_mowningWorld{owningWorld},
		_mHasBeganPlay(false)

	{

	}

	Actor::~Actor()
	{

	}

	void Actor::BeginPlayInternal()
	{
		if (!_mHasBeganPlay)
		{
			_mHasBeganPlay = true;
			BeginPlay();
		}
	}

	
	void Actor::BeginPlay()
	{
		// for testing
		LOG("THE ACTOR HAS BEGAN");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Tick Began");
	}
}