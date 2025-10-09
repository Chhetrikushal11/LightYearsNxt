#pragma once

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

	private:
		sf::RenderWindow _mWindow;


	};
}
