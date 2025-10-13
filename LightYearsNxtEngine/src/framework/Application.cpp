#include "framework/Application.h"
#include <stdio.h>
#include "framework/core.h"
#include "framework/World.h"

namespace ly
{

	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		: _mWindow{ sf::VideoMode(windowWidth, windowHeight), title, style},
		_mtargetFrameRate(60.f),
		_mTickClock(), currentWorld{ nullptr }
	{
	}
	void Application::Run()
	{
		// anytime the game restart we want to restart the clock
		_mTickClock.restart();
		float accumlatedTime = 0.f;
		// delta time is 1/FixedFrameRate
		float targetDeltaTime = 1.f / _mtargetFrameRate;

		while (_mWindow.isOpen())
		{
			// since the infinite while loop when open will make the renderWindow to be open but it not responsive
			// to make it responsive we need to build a event and pass another while loop
			// to use event we need to pass function pollEvent
			sf::Event windowEvent;
			while (_mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					_mWindow.close();
				}

			}
			// to find the time elapsed we update the accumulatedTime
			float _actualFrameRate = _mTickClock.restart().asSeconds();
			
			accumlatedTime += _actualFrameRate;
			while (accumlatedTime > targetDeltaTime)
			{	
				
				accumlatedTime -= targetDeltaTime;
				 TickInternal(targetDeltaTime);
				RenderInternal();
			}

			LOG("Ticking at framerate :%f",1.f / _actualFrameRate);
		}
	}
	void Application::TickInternal(float deltaTime)
	{

		Tick(deltaTime);
		if (currentWorld)
		{
			
			currentWorld->TickInternal(deltaTime);
		}
	}
	void Application::RenderInternal()
	{
		// we want render to clear the game
		_mWindow.clear();


		Render(); // template function 
		
		_mWindow.display();
	}
	void Application::Render()
	{
		if (currentWorld)
		{
			currentWorld->Render(_mWindow);
		}
	}
	void Application::Tick(float deltaTime)
	{
		
	}
}