#include "framework/TimerManager.h"

namespace ly
{
	Timer::Timer(weak<Object> weakRef, std::function<void()> callback, float duration, bool repeat)
		: _mlistener{ weakRef, callback },
		_mDuration{ duration },
		_mRepeat{ repeat },
		_mTimerCounter{ 0.f },
		_mIsExpired{ false }
	{
	}
	void Timer::TickTime(float deltaTime)
	{
		if (Expired())
		{
			return;
		}
		_mTimerCounter += deltaTime;

		if (_mTimerCounter >= _mDuration)
		{
			_mlistener.second();

			if (_mRepeat)
			{
				_mTimerCounter = 0.f;
			}

			else
			{
				SetExpired();
			}
		}


	}
	bool Timer::Expired() const
	{
		return _mIsExpired || _mlistener.first.expired() || _mlistener.first.lock()->IsPendingDestroy(); // how this work
	}

	void Timer::SetExpired()
	{
		_mIsExpired = true;

	}

	unique<TimerManager> TimerManager::_mtimerManager{ nullptr };

	void TimerManager::UpdateTimer(float deltaTime)
	{
		for (Timer& timer:_mTimers)
		{
			timer.TickTime(deltaTime);
		}
	}

	TimerManager::TimerManager()
		:_mTimers{}
	{

	}

	TimerManager& TimerManager::Get()
	{
		if (!_mtimerManager)
		{
			_mtimerManager = std::move(unique<TimerManager>(new TimerManager{}));

		}
		return *_mtimerManager;
	}


}