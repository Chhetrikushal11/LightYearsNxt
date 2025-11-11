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
		onDestroy.Broadcast(this);
		_mIsPendingDestroy = true;
	}

	weak<Object> Object::GetWeakRef()
	{
		
		/* why the GetWeakRef over here is not getting the const value?*/

		return weak_from_this();
	}

	weak<const Object> Object::GetWeakRef() const
	{
		return weak_from_this();
	}


}