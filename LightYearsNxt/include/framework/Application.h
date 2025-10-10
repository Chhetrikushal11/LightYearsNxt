#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		//constructor
		Application();

		//run function
		void Run();
		// to update the frame
		void TickInternal(float deltaTime);

		// rendering
		void RenderInternal();

	private:
		sf::RenderWindow _mWindow;
		// target framerate as we are going for fixed framerate
		float _mtargetFrameRate;

		// need to create a virtual function
		virtual void Render();
		virtual void Tick(float deltaTime);
		// to keep the record of the timing we need a some sort of clock
		sf::Clock _mTickClock;


	};
}
