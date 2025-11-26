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
		// to read the font
		shared<sf::Font> LoadFont(const std::string& path);

		// to loop through our code we need to run a logic to see if there last shared pointer if other go out of scope
		void CleanCycle();

		// making the function to ask the root directory of Asset
		void SetAssetRootDirectory(const std::string& directory);
	protected:
		// have to create a singleton constructor
		// will access this public interface
		//
		AssestManager();

	private:
		// for Loading template
		template<typename T>
		shared<T> LoadAssest(const std::string& path, Dictionary<std::string, shared<T>>& container);

		// for Clean Cycle template
		template<typename T>
		void CleanUniqueRef(Dictionary<std::string, shared<T>>& container);

		static unique<AssestManager> assestManager;
		// the reason we use static infront of the unique pointer whole class will use only one pointer.
		
		// we will load the path in container like in dictionary
		Dictionary<std::string, shared<sf::Texture>> _mLoadedTextureMap;
		// the reason we are making the Dictionary for _mLoadedTextureMap to find if the Texture have been loaded already
		// and by pass path as a key it is easier to find the reference.

		std::string _mRootDirectory; // need to call this for path.
		Dictionary<std::string, shared<sf::Font>> _mLoadedFontMap;
	};
	template<typename T>
	inline shared<T> AssestManager::LoadAssest(const std::string& path, Dictionary<std::string, shared<T>>& container)
	{
		auto found = container.find(path);
		if (found != container.end())
		{
			return found->second; // the second is value which is the texture
			// this code will prevent the load of copy of the same exact path.


		}

		// if cannot find the already loaded
		// here we are creating key name newTexture which will hold the value of newTexture stored in the dictionary
		shared<T> newAssest{ new T };
		if (newAssest->loadFromFile(_mRootDirectory + path))
		{
			container.insert({ path, newAssest });
			return newAssest;
		}

		// now if we cant load anything
		return shared<T> {nullptr};
	}
	template<typename T>
	inline void AssestManager::CleanUniqueRef(Dictionary<std::string, shared<T>>& container)
	{
		for (auto iter = container.begin(); iter != container.end();)
		{
			if (iter->second.unique()) // if the assest manager is only one holding. Which means it is no longer needed.
			{
				LOG("cleaning assest:%s", iter->first.c_str());
				iter = container.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}