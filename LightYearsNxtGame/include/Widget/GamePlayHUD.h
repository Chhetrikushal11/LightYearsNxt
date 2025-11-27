#pragma once

#include "Widget/HUD.h"
#include "Widget/TextWidget.h"

namespace ly
{
	class GamePlayHUD : public HUD
	{
	public:
		GamePlayHUD();

		virtual void Draw(sf::RenderWindow& windowRef) override;
		virtual void Tick(float deltaTime) override;
	private:
		TextWidget _mFramerateText;
	};
}

