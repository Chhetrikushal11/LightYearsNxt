#include "framework/World.h"
#include "framework/core.h"
#include "framework/Actor.h"
#include "framework/Object.h"
#include "framework/Application.h"
#include "gameplay/GameStage.h"

namespace ly
{
	World::World(Application* owningApp)
		:_mowningApp{ owningApp },
		_mBeganPlay(false),
		_mActors{},
		_mPendingActors{},
		_mGameStages{},
		_mCurrentStage{_mGameStages.end()}
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
			/* Video 96 we drop this burden to clean cycle to make it efficent*/
			//if (iter->get()->IsPendingDestroy())
			//{
			//	iter = _mActors.erase(iter);
			//	// erase the Actor from the vector
			//}
			//else
			//{
				iter->get()->TickInternal(deltaTime);
				++iter;
			
		}

		if (_mCurrentStage != _mGameStages.end())
		{
			_mCurrentStage->get()->TickStage(deltaTime);
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
			InitGameStages();
			StartStages();

		}
	}

	World::~World()
	{

	}

	void World::Tick(float deltaTime)
	{
		// LOG("Tick at the frame rate %f", 1.f/deltaTime);
	}

	void World::InitGameStages()
	{


	}

	void World::AllGameStageFinished()
	{
		LOG("All Stage Finished.");
	}

	void World::NextGameStage()
	{
		_mCurrentStage = _mGameStages.erase(_mCurrentStage);
		if (_mCurrentStage != _mGameStages.end())
		{
			_mCurrentStage->get()->StartStage();
			_mCurrentStage->get()->onStageFinished.BindAction(GetWeakRef(), &World::NextGameStage);
		}

		else
		{
			AllGameStageFinished();
		}
	}



	sf::Vector2u World::GetWindowsSize() const
	{
		return _mowningApp-> GetWindowSize();
	}

	void World::CleanCycle()
	{
		for (auto iter = _mActors.begin(); iter != _mActors.end();)
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = _mActors.erase(iter);
				// erase the Actor from the vector
			}

			else
			{
				++iter;
			}
		}


	}

	void World::AddStage(const shared<GameStage>& newStage)
	{
		_mGameStages.push_back(newStage);
	}

	void World::BeginPlay()
	{
		// LOG("Begin the play");
	}

	void World::StartStages()
	{
		_mCurrentStage = _mGameStages.begin();
		_mCurrentStage->get()->StartStage();
		_mCurrentStage->get()->onStageFinished.BindAction(GetWeakRef(), &World::NextGameStage);
	}
}