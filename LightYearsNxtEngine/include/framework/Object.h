#pragma once

namespace ly
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		virtual void Destroy();
		bool IsPendingDestroy() const { return _mIsPendingDestroy;  }

	private:
		bool _mIsPendingDestroy;
	};
}