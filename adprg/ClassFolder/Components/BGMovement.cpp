#include "BGMovement.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include "../BGObject.h"


BGMovement::BGMovement(std::string name) : AComponent(name, Script)
{
}

BGMovement::~BGMovement()
{
}



void BGMovement::perform()
{
	AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlayerObject");
	PlayerInputController* inputController = (PlayerInputController*)(airplanePlayer->getComponentsOfType(ComponentType::Input)[0]);

	PlayerMovement* playerMovement = (PlayerMovement*)(airplanePlayer->getComponentsOfType(ComponentType::Script)[0]);

	BGObject* BgObject = (BGObject*)this->getOwner();
	this->sprite = BgObject->getSprite();

	
	sf::Vector2f offset(0.0f, 0.0f);
	if (inputController->isBoosting() && playerMovement->boostGas > 0)
	{
		offset.y += SPEED_MULTIPLIER + 400;

	}
	else
	{
		offset.y += SPEED_MULTIPLIER;
	}
	sprite->move(offset * deltaTime.asSeconds());

	sf::Vector2f localPos = sprite->getPosition();
	if (localPos.y*deltaTime.asSeconds() > 0)
	{
		sprite->setPosition(0, -game::WINDOW_HEIGHT * 7);
		
	}

}
