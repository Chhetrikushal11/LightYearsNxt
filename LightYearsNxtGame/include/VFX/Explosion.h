#pragma once
#include <string>

#include "framework/Core.h"
 
namespace ly
{
	class World;
	class Explosion
	{
	public:
		Explosion(int particleAmt = 20,
			float lifeTimeMin = 0.5f,
			float lifeTimeMax = 1.5f,
			float SizeMin= 1,
			float SizeMax = 3,
			float SpeedMin = 200,
			float SpeedMax = 400,
			const sf::Color& particleColor = { 255, 128,0,255 },
			const	List<std::string>& ParticleImagePaths =
			{		
								 "SpaceShooterRedux/PNG/Effects/star1.png" ,
								"SpaceShooterRedux/PNG/Effects/star2.png",
								"SpaceShooterRedux/PNG/Effects/star3.png"

			}
		);

		void SpawnExplosion(World* world, const sf::Vector2f& location);

	private:
		int _mParticleAmt;

		float _mLifeTimeMin;
		float _mLifeTimeMax;
		float _mSizeMax;
		float _mSizeMin;
		float _mSpeedMax;
		float _mSpeedMin;

		sf::Color _mSpawnColor;

		List<std::string> _mParticleImagesPaths;
	};
}