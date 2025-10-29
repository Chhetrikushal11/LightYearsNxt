#pragma once

namespace ly
{
	class Actor;
	class Shooter 
	{
	public:
		void Shoot();

		virtual bool CanShoot() const { return true; }

		virtual bool InOnCooldown() const { return false; }

		Actor* GetOwner() const {return _mOwner;}
	protected:
		// to make this class abstract class we will keep the constructor in protected section
		Shooter(Actor* owner);

	private:
		virtual void ShootImpl() = 0;
		Actor* _mOwner;
	};
}