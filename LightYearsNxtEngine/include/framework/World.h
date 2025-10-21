#pragma once
#include "framework/core.h"
#include <SFML/Graphics.hpp>


namespace ly {
	// need to forward declare Application since it will own the world
	// Inherit from: 
	class Application;

	// since the world should be able to spawn the actor
	// this means world is owner of the actors
	// we need to add actor class
	
	// Owner of the class
	class Actor;

	class World {
	public:
		World(Application* owningApp);


		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow& window);

		// we use virtual destructor when we use inheritance.
		// otherwise it will not call parent destructor.
		virtual ~World();
		
		// now we need to add Spawn the actor 
		// for that we need to Spawn the weak pointer
		
		template <typename ActorType>
		weak<ActorType> SpawnActor();

		// to queries from the application
		sf::Vector2u GetWindowsSize() const;

	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* _mowningApp;
		bool _mBeganPlay;

		// here we need to hold the container of the actor and when World ask for the Actor 
		// Actor class spawn the new actor as the world ask.
		// for this job we will use the List 

		List<shared<Actor>> _mActors;

		// we could be in middle of the updating every actor
		// and we add actor at the same time of updating.It might cause some issue. 
		// It will casue issue as we updating the size of array need to be changed due to addition of the new actor
		// to avoid the list to loop properly

		List<shared<Actor>> _mPendingActors;



	};

	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		_mPendingActors.push_back(newActor);
		return newActor;

	}

}