#include "framework/World.h"
#include "framework/core.h"
#include "framework/Actor.h"

namespace ly
{
	World::World(Application* owningApp)
		:_mowningApp{ owningApp },
		_mBeganPlay(false),
		_mActors{},
		_mPendingActors{}
	{

	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : _mPendingActors)
		{
			_mActors.push_back(actor);
			actor->BeginPlayInternal();
			
		}
		for (shared<Actor> actor : _mActors)
		{
			actor->Tick(deltaTime);

		}
		_mPendingActors.clear();
		Tick(deltaTime);
	}

	void World::BeginPlayInternal()
	{
		if (!_mBeganPlay) {
			_mBeganPlay = true;

		}
	}

	World::~World()
	{

	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at the frame rate %f", 1.f/deltaTime);
	}

	void World::BeginPlay()
	{
		LOG("Begin the play");
	}
}