#include "framework/Application.h"
#include <stdio.h>
#include "framework/core.h"
#include "framework/World.h"

namespace ly
{
	Application::Application() 
		: _mWindow{ sf::VideoMode(576, 720), "LightYears" }, _mtargetFrameRate(60.f),
		_mTickClock(), currentWorld{nullptr}
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
		// now to build the rectangular shape
		sf::RectangleShape rect{ sf::Vector2f{100,100} };
		rect.setFillColor(sf::Color::Green);
		rect.setPosition(_mWindow.getSize().x / 2.f - rect.getSize().x / 2.f, _mWindow.getSize().y / 2.f - rect.getSize().y / 2.f);
		//after we build the shape we need to tell our window to draw the shape in the canvas
		_mWindow.draw(rect);
	}
	void Application::Tick(float deltaTime)
	{
		
	}
}