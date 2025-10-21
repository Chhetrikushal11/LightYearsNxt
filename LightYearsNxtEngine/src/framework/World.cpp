#include "framework/World.h"
#include "framework/core.h"
#include "framework/Actor.h"
#include "framework/Object.h"
#include "framework/Application.h"


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

		_mPendingActors.clear();
		for (auto iter = _mActors.begin(); iter != _mActors.end();)
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = _mActors.erase(iter);
				// erase the Actor from the vector
			}
			else
			{
				iter->get()->TickInternal(deltaTime);
				++iter;
			}
		}
		Tick(deltaTime);
	}

	void World::Render(sf::RenderWindow& window)
	{
		for (auto& actor : _mActors)
		{
			actor->Render(window);
		}
	}

	void World::BeginPlayInternal()
	{
		if (!_mBeganPlay) {
			_mBeganPlay = true;
			BeginPlay();

		}
	}

	World::~World()
	{

	}

	void World::Tick(float deltaTime)
	{
		// LOG("Tick at the frame rate %f", 1.f/deltaTime);
	}

	sf::Vector2u World::GetWindowsSize() const
	{
		return _mowningApp-> GetWindowSize();
	}

	void World::BeginPlay()
	{
		// LOG("Begin the play");
	}
}