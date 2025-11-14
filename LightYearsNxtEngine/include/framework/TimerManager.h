// this class will be singleton
#pragma once
#include <functional>

#include "framework/core.h"
#include "framework/Object.h"
namespace ly
{	
	struct TimerHandle
	{
	public:
		TimerHandle();
		unsigned int GetTimerKey() const { return _mTimerKey; }
	private:
		unsigned int _mTimerKey;
		static unsigned int timerKeyCounter;
		static unsigned int GetNextTimerKey() { return ++timerKeyCounter; }

	};

	// hash function
	struct TimerHandlerHashFunction
	{
	public:
		std::size_t operator() (const TimerHandle& timerHandle) const
		{
			return timerHandle.GetTimerKey();
		}
	};

	//operator overloading.....
	bool operator == (const TimerHandle& lhs, const TimerHandle& rhs);
	struct Timer
	{
	public:
		Timer(weak<Object> weakRef, std::function<void()> callback, float duration, bool repeat);
		void TickTime(float deltaTime);
		bool Expired() const;
		void SetExpired();
	private:
		std::pair<weak<Object>, std::function<void()>> _mlistener;
		float _mDuration;
		bool _mRepeat;
		float _mTimerCounter;
		bool _mIsExpired;
	};
	class TimerManager
	{
	public:
		static TimerManager& Get();
		template<typename ClassName>
		TimerHandle SetTimer(weak < Object> weakRef, void(ClassName::* callback)(), float duration, bool repeat = false)
		{	
			TimerHandle newHandle{};
			_mTimers.insert({ newHandle, Timer(weakRef, [=] {(static_cast<ClassName*>(weakRef.lock().get())->*callback)();}, duration, repeat)});
			return newHandle;
		}

		void UpdateTimer(float deltaTime);
		void ClearTimer(TimerHandle timerHandle);
	protected:
		TimerManager();
		
	private:
		static unique<TimerManager> _mtimerManager;
		Dictionary<TimerHandle, Timer, TimerHandlerHashFunction> _mTimers;

	};
}