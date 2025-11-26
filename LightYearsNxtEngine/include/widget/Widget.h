#pragma once

#include <SFML/Graphics.hpp>
#include "framework/Object.h"

namespace ly
{
	class Widget : public Object
	{
	public:
		void NativeDraw(sf::RenderWindow & windowRef);
		virtual bool HandleEvent(const sf::Event& event);
		void SetWidgetLocation(const sf::Vector2f& newLocation);
		void SetWidgetRotation(float newRotation);
		sf::Vector2f GetWidgetLocation() const { return _mWidgetTransform.getPosition(); }
		float GetWidgetRotation() const { return _mWidgetTransform.getRotation(); }

		void setVisibility(bool newVisibility);
		bool GetVisibility() const { return _mIsVisible; }
	
	protected:
		Widget();
	private:
		virtual void Draw(sf::RenderWindow& windowRef);
		virtual void LocationUpdated(const sf::Vector2f& newLocation);
		virtual void RotationUpdated(float newRotation);
		sf::Transformable _mWidgetTransform;
		bool _mIsVisible;

	};
}
