#pragma once
#include "framework/core.h"
#include <SFML/Graphics.hpp>

namespace ly
{
	class AssestManager
	{
	public:
		static AssestManager& Get();
		shared<sf::Texture> LoadTexture(const std::string& path);

		// to loop through our code we need to run a logic to see if there last shared pointer if other go out of scope
		void CleanCycle();

	protected:
		// have to create a singleton constructor
		// will access this public interface
		//
		AssestManager();

	private:
		static unique<AssestManager> assestManager;
		// the reason we use static infront of the unique pointer whole class will use only one pointer.
		
		// we will load the path in container like in dictionary
		Dictionary<std::string, shared<sf::Texture>> _mLoadedTextureMap;
		// the reason we are making the Dictionary for _mLoadedTextureMap to find if the Texture have been loaded already
		// and by pass path as a key it is easier to find the reference.
	};
}