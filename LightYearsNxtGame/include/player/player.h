#pragma once


#include "framework/Object.h"
#include "framework/Delegate.h"

namespace ly
{
	class PlayerSpaceShip;
	class World;
	class Player : public Object
	{
	public:
		Player();
		weak<PlayerSpaceShip> SpawnSpaceship(World* world);
		const weak<PlayerSpaceShip> GetCurrentSpaceship() const { return _mCurrentPlayerSpaceship; }

		void AddLifeCount(unsigned int count);
		int GetLifeCount() const { return _mLifeCount; }
		void AddScore(unsigned int amt);
		int GetScore() const { return _mScore; }

		Delegate<int> onLifeChange;
		Delegate<int> onScoreChange;
		Delegate<> onLifeExhausted;
	private:
		unsigned int  _mLifeCount;
		unsigned int _mScore;
		weak<PlayerSpaceShip> _mCurrentPlayerSpaceship;

	};
}