#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "framework/core.h"
#include <SFML/System.hpp>

namespace ly
{
	class World;
	class Application
	{
	public:
		//constructor with Parameter
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style );

		template<typename WorldType>
		weak<WorldType> LoadWorld();
		void Run();

		// to understand the size of the window
		sf::Vector2u GetWindowSize() const;

		// to get the window to use in different place
		sf::RenderWindow& GetWindow() { return _mWindow; }
		const sf::RenderWindow& GetWindow() const { return _mWindow; }
		private:
		
		bool DispatchEvent(const sf::Event& event);

		//run function
		
		// to update the frame
		void TickInternal(float deltaTime);

		// rendering
		void RenderInternal();

	
		sf::RenderWindow _mWindow;
		// target framerate as we are going for fixed framerate
		float _mtargetFrameRate;

		// need to create a virtual function
		virtual void Render();
		virtual void Tick(float deltaTime);
		// to keep the record of the timing we need a some sort of clock
		sf::Clock _mTickClock;

		// to have one copy of the World
		shared<World> _mCurrentWorld;

		// create the clock for AssestManager
		sf::Clock _mCleanCycleClock;
		float _mCleanCycleInterval;
		


	};

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared<WorldType> newWorld{ new WorldType{this} };
		_mCurrentWorld = newWorld;
		_mCurrentWorld->BeginPlayInternal();
		return newWorld;

	}
}

