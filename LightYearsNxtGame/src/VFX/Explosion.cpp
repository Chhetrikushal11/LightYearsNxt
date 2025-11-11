#include "framework/MathUtility.h"
#include "framework/World.h"
#include "VFX/Particle.h"
#include "VFX/Explosion.h"


namespace  ly
{

Explosion::Explosion(int particleAmt, float lifeTimeMin, float lifeTimeMax, float SizeMin, float SizeMax, float SpeedMin, float SpeedMax, const sf::Color& particleColor, const List<std::string>& ParticleImagePaths)
	: _mParticleAmt{ particleAmt },       // Corrected typo (assuming _mParticleAmt)
	_mLifeTimeMin{ lifeTimeMin },
	_mLifeTimeMax{ lifeTimeMax },
	_mSizeMin{ SizeMin },
	_mSizeMax{ SizeMax },
	_mSpeedMin{ SpeedMin },
	_mSpeedMax{ SpeedMax },
	_mSpawnColor{ particleColor },       // <-- CRITICAL: Added the missing comma
	_mParticleImagesPaths{ ParticleImagePaths }
{
}


void Explosion::SpawnExplosion(World* world, const sf::Vector2f& location)
	{
		if (!world)
		{
			return;
		}
		for (int i = 0; i < _mParticleAmt; ++i)
		{
			std::string particleImagePath = _mParticleImagesPaths[(int)RandomRange(0, _mParticleImagesPaths.size())];
			weak<Particle> newParticle = world->SpawnActor<Particle>(particleImagePath);

			newParticle.lock()->RandomTime(_mLifeTimeMin, _mLifeTimeMax);
			newParticle.lock()->SetActorLocation(location);
			newParticle.lock()->RandomSize(_mSizeMin, _mSizeMax);
			newParticle.lock()->RandomVelocity(_mSpeedMin, _mSpeedMax);
			newParticle.lock()->GetSprite().setColor(_mSpawnColor);


		}
	}
}
