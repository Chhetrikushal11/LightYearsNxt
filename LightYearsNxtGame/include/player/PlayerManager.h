#pragma once
#include "framework/Core.h"
#include "player/Player.h"

namespace ly
{
	class PlayerManager
	{
	public:
		Player& CreateNewPlayer();
		const Player* GetPlayer(int playerIndex = 0) const;
		Player* GetPlayer(int playerIndex = 0);

		static PlayerManager& Get();
	protected:
		PlayerManager();
		
	private:
		List<Player> _mPlayers;
		static unique<PlayerManager> _mplayerManager;
	};
}