#pragma once

#include "framework/Object.h"
#include "framework/Delegate.h"

namespace ly
{	
	class World;
	class GameStage : public Object
	{
	public:	
		// for constructor we just need to define the World
		GameStage(World* world);
		const World* GetWorld() const { return _mWorld; }
		// why we need the next const version of the same data type
		World* GetWorld() { return _mWorld; }

		Delegate<> onStageFinished;
		
		virtual void StartStage();
		virtual void TickStage(float deltaTime);
		void FinishStage();
		bool IsStageFinished() const { return _mStageFinished; }
	private:
		World* _mWorld;
		bool _mStageFinished;
		virtual void StageFinished();


	};
}