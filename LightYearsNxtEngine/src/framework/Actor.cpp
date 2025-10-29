#include "framework/Actor.h"
#include "framework/core.h"
#include "framework/World.h"
#include "framework/MathUtility.h"
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
		// LOG("THE ACTOR HAS BEGAN");
	}

	void Actor::Tick(float deltaTime)
	{
		// LOG("Actor Tick Began");
	}
	void Actor::SetTexture(const std::string& texturePath)
	{
		// to load the assest manager
		_mTexture = AssestManager::Get().LoadTexture(texturePath);
		if (!_mTexture) return;
		_mSprite.setTexture(*_mTexture);

		int texthWidth = _mTexture->getSize().x;
		int texthHeight = _mTexture->getSize().y;

		_mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{texthWidth,texthHeight} });
		// to make the origin of the actor on center we run CenterPivot function

		CenterPivot();
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy())
			return;

		window.draw(_mSprite);
	}
	void Actor::SetActorLocation(const sf::Vector2f& newLoc)
	{
		// sprite can have location and our actor are represented by location
		_mSprite.setPosition(newLoc);
	}
	void Actor::SetActorRotation(float newRot)
	{
		_mSprite.setRotation(newRot);
	}
	void Actor::AddActorLocationOffset(const sf::Vector2f& offsetAmt)
	{
		// we need to get the current location of the actor 
		// then we can offset the location
		SetActorLocation(GetActorLocation() + offsetAmt);
	}
	void Actor::AddActorRotationOffset(float offsetAmt)
	{
	
		SetActorRotation(GetActorRotation() + offsetAmt);
	}

	sf::Vector2f Actor::GetActorLocation() const
	{
		return _mSprite.getPosition();
	}
	float Actor::GetActorRotation() const
	{
		return _mSprite.getRotation();
	}
	sf::Vector2f Actor::GetActorForwardDirection() const
	{
		// how to determine the forward direction 
		// first need to hold the orentation of the direction.
		// we will do by determining the rotation.
		return RotationToVector(GetActorRotation());
	}
	sf::Vector2f Actor::GetActorRightDirection() const
	{
		return RotationToVector(GetActorRotation() + 90.f);
	}

	sf::Vector2u Actor::GetWindowSize() const
	{
		return _mowningWorld->GetWindowsSize();
	}


	void Actor::CenterPivot()
	{
		sf::FloatRect bound = _mSprite.getGlobalBounds();
		_mSprite.setOrigin(bound.width / 2.f, bound.height / 2.f);
	}

	sf::FloatRect Actor::GetActorGlobalBounds() const
	{
		return _mSprite.getGlobalBounds();
	}

	bool Actor::IsActorOutofWindowBounds() const
	{
		float windowWidth = GetWorld()->GetWindowsSize().x;
		float windowHeight = GetWorld()->GetWindowsSize().y;

		float width = GetActorGlobalBounds().width;
		float height = GetActorGlobalBounds().height;

		sf::Vector2f actorPos = GetActorLocation();

		if (actorPos.x < -width)
		{
			return true;

		}

		if (actorPos.x > windowWidth + width)
		{
			return true;

		}

		// longitudnal side
		if (actorPos.y < -height)
		{
			return true;

		}

		if (actorPos.y > windowHeight + height)
		{
			return true;

		}

		return false;


	}

}