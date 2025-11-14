#include "framework/TimerManager.h"

namespace ly
{	
	unsigned int TimerHandle::timerKeyCounter = 0;
	TimerHandle::TimerHandle()
		: _mTimerKey{GetNextTimerKey()}
	{

	}
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
		for (auto iter = _mTimers.begin(); iter != _mTimers.end();)
		{
			if (iter->second.Expired())
			{
				iter = _mTimers.erase(iter);
			}
			
			else
			{
				iter->second.TickTime(deltaTime);
				++iter;
			}
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

	void TimerManager::ClearTimer(TimerHandle timerHandle)
	{
		auto iter = _mTimers.find(timerHandle);
		if (iter != _mTimers.end())
		{
			iter->second.SetExpired();
		}
	}


	bool operator==(const TimerHandle& lhs, const TimerHandle& rhs)
	{
		return lhs.GetTimerKey() == rhs.GetTimerKey();
	}

}