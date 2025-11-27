#include "Widget/GamePlayHUD.h"
namespace ly
{
	GamePlayHUD::GamePlayHUD()
		:_mFramerateText{"Frame Rate: "}
	{
	}
	void GamePlayHUD::Draw(sf::RenderWindow& windowRef)
	{
		_mFramerateText.NativeDraw(windowRef);
	}
	void GamePlayHUD::Tick(float deltaTime)
	{
		int frameRate = int(1 / deltaTime);
		std::string frameRateStr = "Frame Rate :" + std::to_string(frameRate);
		_mFramerateText.SetString(frameRateStr);
	}
}