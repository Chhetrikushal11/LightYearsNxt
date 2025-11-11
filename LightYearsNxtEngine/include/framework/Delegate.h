#pragma once
#include<functional>

#include "framework/core.h"


namespace ly
{
	class Object;
	template<typename ... Args>
	class Delegate
	{
	public:
		template<typename ClassName>
		void BindAction(weak<Object> obj, void(ClassName::*callback)(Args...))
		{
			std::function<bool(Args...)>callbackFunc = [obj, callback](Args...args)->bool
				{
					if (!obj.expired())
					{
						(static_cast<ClassName*>(obj.lock().get())->*callback)(args...);
						return true;
					}

					return false;

				};
			_mCallbacks.push_back(callbackFunc);

		}


		void Broadcast(Args... args)
		{
			for (auto iter = _mCallbacks.begin(); iter!= _mCallbacks.end();)
			{
				if ((*iter)(args...))
				{
					iter++;
				}

				else
				{
					iter = _mCallbacks.erase(iter);
				}
			}
		}
	private:
		List<std::function<bool(Args...)>> _mCallbacks;
	};
}