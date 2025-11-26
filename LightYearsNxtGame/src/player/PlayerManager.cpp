#include "player/PlayerManager.h"

namespace ly
{
	unique<PlayerManager> PlayerManager::_mplayerManager{ nullptr };
	PlayerManager::PlayerManager()
	{
	}
	Player& PlayerManager::CreateNewPlayer()
	{
		_mPlayers.emplace(_mPlayers.begin(),Player());
		return _mPlayers.back();
	}
	const Player* PlayerManager::GetPlayer(int playerIndex) const
	{
		if (playerIndex >= 0 && playerIndex <= _mPlayers.size())
		{
			return &(_mPlayers[playerIndex]);
		}
		return nullptr;
	}
	Player* PlayerManager::GetPlayer(int playerIndex)
	{
		if (playerIndex >= 0 && playerIndex <= _mPlayers.size())
		{
			return &(_mPlayers[playerIndex]);
		}

		return nullptr;
		
	}

	PlayerManager& PlayerManager::Get()
	{ 
		if (!_mplayerManager)
		{
			_mplayerManager = std::move(unique<PlayerManager>{new PlayerManager()});
		}
		return *_mplayerManager;
	}
}