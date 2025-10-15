#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	sf::Vector2f RotationToVector(float rotation);
	// from degree to rotation
	float DegreeToRadians(float degrees);
	float RadiansToDegree(float radians);
}