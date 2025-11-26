#include "widget/HUD.h"

namespace ly
{
	void HUD::NativeInit(const sf::RenderWindow& windowRef)
	{
		if (!_mAlreadyInit)
		{
			_mAlreadyInit = true;
			Init(windowRef);
		}
	}
	bool HUD::HandleEvent(const sf::Event& event)
	{
		return false;
	}
	HUD::HUD()
		:_mAlreadyInit{false}
	{
	}

	void HUD::Init(const sf::RenderWindow& windowRef)
	{
		// WE WILL FILL AFTER WARDS;
	}


}