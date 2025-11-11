#pragma once
#include <memory>
#include "framework/core.h"

#include "framework/Delegate.h"

namespace ly
{
	class Object : public std::enable_shared_from_this<Object>
	/*
	*   public std::enable_shared_from_this<Object> is introduce on Video 105
	*	so as to enable the weak pointer
	*	the enable_shared_from_this function help to build the weak ptr internally for each shared ptr.
	*   with this basically every sharedptr is holding weakptr on themselves.
	*/
	{
	public:
		Object();
		virtual ~Object();

		virtual void Destroy();
		bool IsPendingDestroy() const { return _mIsPendingDestroy;  }

		weak<Object> GetWeakRef();

		// what is the difference between weak<const Object> and weak<Object>?
		weak<const Object> GetWeakRef() const;

		Delegate<Object*> onDestroy;
	private:
		bool _mIsPendingDestroy;
	};
}