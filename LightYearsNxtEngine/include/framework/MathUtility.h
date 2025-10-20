#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	sf::Vector2f RotationToVector(float rotation);
	// from degree to rotation
	float DegreeToRadians(float degrees);
	float RadiansToDegree(float radians);

	// we want to clamp the velocity
	// we are using template here because type of template can float or the vector or double.

	template<typename T>
	float GetVectorLength(const sf::Vector2<T>& vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	// in this case we are not passing by reference as constant so we are changing it at the place.
	template<typename T>
	sf::Vector2<T>& ScaleVector(sf::Vector2<T>& vectorToScale, float amt)
	{
		vectorToScale.x *= amt;
		vectorToScale.y *= amt;
		return vectorToScale;

	}

	template<typename T>
	sf::Vector2<T>& Normalize(sf::Vector2<T>& vector)
	{
		float vectorLength = GetVectorLength<T>(vector);
			if (vectorLength == 0.f) return sf::Vector2<T>{};

		ScaleVector(vector, 1.0f / vectorLength);
		return vector;
	}
}