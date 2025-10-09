#include <iostream>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"

int main()
{
	// to eradicate any memory leak lets use the shared pointer
	// as it deletes it self after it goes out of scope
	std::shared_ptr<ly::Application> app = std::make_shared<ly::Application>(); // app is name of the Application object

	app->Run();
	return 0;
}