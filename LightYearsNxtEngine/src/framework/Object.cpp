#include "framework/Object.h"
#include "framework/core.h"

namespace ly 
{
	Object::Object()
		:_mIsPendingDestroy{false}
	{

	}

	Object::~Object()
	{
		LOG("Object Destroyed.");

	}

	void Object::Destroy()
	{
		_mIsPendingDestroy = true;
	}


}