#include "framework/Actor.h"
#include "framework/core.h"
#include "framework/World.h"

namespace ly{

	Actor::Actor(World * owningWorld, const std::string& texturePath)
		:_mowningWorld{owningWorld},
		_mHasBeganPlay(false),
		_mSprite{},
		_mTexture{}

	{
		SetTexture(texturePath);
	}

	Actor::~Actor()
	{
		LOG("Actor Destroyed.");
	}

	

	void Actor::BeginPlayInternal()
	{
		if (!_mHasBeganPlay)
		{
			_mHasBeganPlay = true;
			BeginPlay();
		}
	}
	
	void Actor::TickInternal(float deltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(deltaTime);
		}
	}

	
	void Actor::BeginPlay()
	{
		// for testing
		LOG("THE ACTOR HAS BEGAN");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Tick Began");
	}
	void Actor::SetTexture(const std::string& texturePath)
	{
		_mTexture.loadFromFile(texturePath);
		_mSprite.setTexture(_mTexture);

		int texthWidth = _mTexture.getSize().x;
		int texthHeight = _mTexture.getSize().y;

		_mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{texthWidth,texthHeight} });
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy())
			return;

		window.draw(_mSprite);
	}
}