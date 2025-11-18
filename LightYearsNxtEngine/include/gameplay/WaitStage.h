#pragma once

#include "gameplay/GameStage.h"

namespace ly
{
	class World;
	class WaitStage : public GameStage
	{
	public:
		WaitStage(World* world, float waitDuration = 5.f);
		virtual void StartStage() override;
	private:
		float _mWaitDuration;

	};
}