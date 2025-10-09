#include "framework/Application.h"

namespace ly
{
	Application::Application() : _mWindow{ sf::VideoMode(576, 720), "LightYears" }
	{
	}
	void Application::Run()
	{
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
		}
	}
}