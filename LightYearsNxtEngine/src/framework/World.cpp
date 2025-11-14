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
		_mCurrentStageIndex{-1},
		_mGameStages{}
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

		if (_mCurrentStageIndex >= 0 && _mCurrentStageIndex < _mGameStages.size())
		{
			_mGameStages[_mCurrentStageIndex]->TickStage(deltaTime);
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
			NextGameStage();

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
	}

	void World::NextGameStage()
	{
		++_mCurrentStageIndex;
		if (_mCurrentStageIndex >= 0 && _mCurrentStageIndex < _mGameStages.size())
		{
			_mGameStages[_mCurrentStageIndex]->onStageFinished.BindAction(GetWeakRef(), &World::NextGameStage);
			_mGameStages[_mCurrentStageIndex]->StartStage();
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

		// cleaning the game stages
		for (auto iter = _mGameStages.begin(); iter != _mGameStages.end();)
		{
			if (iter->get()->IsStageFinished())
			{
				iter = _mGameStages.erase(iter);
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
}