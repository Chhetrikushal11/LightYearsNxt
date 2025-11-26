#include "widget/Widget.h"

namespace ly
{
	Widget::Widget()
		: _mIsVisible{ true },
		_mWidgetTransform{}
	{
	}

	void Widget::Draw(sf::RenderWindow& windowRef)
	{
	}




	
	bool Widget::HandleEvent(const sf::Event& event)
	{
		return false;
	}

	void Widget::SetWidgetLocation(const sf::Vector2f& newLocation)
	{
		_mWidgetTransform.setPosition(newLocation);
		LocationUpdated(newLocation);
	}

	void Widget::SetWidgetRotation(float newRotation)
	{
		_mWidgetTransform.setRotation(newRotation);
		RotationUpdated(newRotation);
	}

	void Widget::setVisibility(bool newVisibility)
	{
		_mIsVisible = newVisibility;
	}

	void Widget::NativeDraw(sf::RenderWindow& windowRef)
	{
	
	}

	void Widget::LocationUpdated(const sf::Vector2f& newLocation)
	{
	}

	void Widget::RotationUpdated(float newRotation)
	{
	}

}