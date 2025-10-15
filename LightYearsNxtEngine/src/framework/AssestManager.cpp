#include "framework/AssestManager.h"

namespace ly
{	
	unique<AssestManager> AssestManager::assestManager{ nullptr };
	// why do we write unique<AssestManager> AssestManager::assestManager{ nullptr}?
		// - since we build the constructor Protected we cannot initialize the member function in constructor.
	AssestManager& AssestManager::Get()
	{
		// first we will check for the null ptr

		if(!assestManager)
		{
			assestManager = std::move(unique<AssestManager>{new AssestManager});
				// we cannot use copy operator for unique pointer hence we need to use move operator.
		}

		return *assestManager;
	}
	shared<sf::Texture> AssestManager::LoadTexture(const std::string& path)
	{
		auto found = _mLoadedTextureMap.find(path);
		if (found != _mLoadedTextureMap.end())
		{
			return found->second; // the second is value which is the texture
			// this code will prevent the load of copy of the same exact path.


		}

		// if cannot find the already loaded
		// here we are creating key name newTexture which will hold the value of newTexture stored in the dictionary
		shared<sf::Texture> newTexture{ new sf::Texture };
			if (newTexture->loadFromFile(path))
			{
				_mLoadedTextureMap.insert({ path, newTexture });
				return newTexture;
			}

			// now if we cant load anything
			return shared<sf::Texture> {nullptr}; // returning the dummy one
	}
	void AssestManager::CleanCycle()
	{
		for (auto iter = _mLoadedTextureMap.begin(); iter != _mLoadedTextureMap.end();)
		{
			if (iter->second.unique()) // if the assest manager is only one holding. Which means it is no longer needed.
			{
				LOG("cleaning texture:%s", iter->first.c_str());
				iter = _mLoadedTextureMap.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
	AssestManager::AssestManager()
	{

	}
}