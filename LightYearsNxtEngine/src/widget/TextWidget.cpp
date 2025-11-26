#include "widget/TextWidget.h"
#include "framework/AssestManager.h"

namespace ly
{
	TextWidget::TextWidget(const std::string& textStr, const std::string& fontPath, unsigned int characterSize)
		:_mFont{ AssestManager::Get().LoadFont(fontPath) },
		_mText{ textStr, *(_mFont.get()), characterSize }
	{
	}
	void TextWidget::SetString(const std::string& newStr)
	{
		_mText.setString(newStr);
	}
	void TextWidget::SetTextSize(unsigned int newSize)
	{
		_mText.setCharacterSize(newSize);
	}
	void TextWidget::LocationUpdated(const sf::Vector2f& newLocation)
	{
		_mText.setPosition(newLocation);
	}
	void TextWidget::RotationUpdated(float newRotation)
	{
		_mText.setRotation(newRotation);
	}
	void TextWidget::Draw(sf::RenderWindow& windowRef)
	{
		windowRef.draw(_mText);
	}
}