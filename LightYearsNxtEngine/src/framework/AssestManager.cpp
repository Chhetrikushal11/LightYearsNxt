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
		return LoadAssest(path, _mLoadedTextureMap);
	}
	shared<sf::Font> AssestManager::LoadFont(const std::string& path)
	{
		return LoadAssest(path, _mLoadedFontMap);
	}
	void AssestManager::CleanCycle()
	{
		CleanUniqueRef(_mLoadedTextureMap);
		CleanUniqueRef(_mLoadedFontMap);
	}
	void AssestManager::SetAssetRootDirectory(const std::string& directory)
	{
		_mRootDirectory = directory;
	}

	AssestManager::AssestManager() : _mRootDirectory{}
	{

	}
}