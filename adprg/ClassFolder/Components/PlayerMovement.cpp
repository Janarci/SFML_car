#include "PlayerMovement.h"

#include <iostream>

#include "PlayerInputController.h"
#include "../AirplanePlayer.h"
#include "../ObjectPooling/GameObjectPool.h"
#include "../ObjectPoolHolder.h"
#include "../SfxManager.h"
#include "../Screens/UIScreen.h"


PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script)
{
}

PlayerMovement::~PlayerMovement()
{
}

void PlayerMovement::perform()
{

	AirplanePlayer* airplanePlayer = (AirplanePlayer*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)(airplanePlayer->getComponentsOfType(ComponentType::Input)[0]);

	UIScreen* UIHolder = (UIScreen*)GameObjectManager::getInstance()->findObjectByName("UIScreen");

	std::string str = std::to_string(this->boostGas);
	//str.erase(str.find_last_not_of('0') + 1, std::string::npos);

	UIHolder->setGas(str);


	sf::Transformable* playerTransformable = this->getOwner()->getTransformable();
	if (playerTransformable == NULL || inputController == NULL) {
		std::cout << "One or more of the needed dependencies are missing!\n";
		return;
	}
	if (playerTransformable->getPosition().x > 700)
	{
		playerTransformable->setPosition(sf::Vector2f(700,playerTransformable->getPosition().y));
	}
	if (playerTransformable->getPosition().x < 200)
	{
		playerTransformable->setPosition(sf::Vector2f(200, playerTransformable->getPosition().y));
	}
	std::cout << playerTransformable->getPosition().x << " " << playerTransformable->getPosition().y << std::endl;

	sf::Vector2f offset(0.0f, 0.0f);
	/*
	if (inputController->isUp()) {
		offset.y -= inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isDown()) {
		offset.y += inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	*/
	if (inputController->isRight()) {
		offset.x -= inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isLeft()) {
		offset.x += inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}

	if (inputController->isBoosting() && this->boostGas > 0)
	{

		if (!isHeld)
		{
			std::vector<sf::Sound*> soundList;
			soundList = SfxManager::getInstance()->getSoundList();
			soundList[0]->stop();
			soundList[1]->play();
			std::cout << "tap once" << std::endl;

		}

		boostGas -= 1.0;
	}
	else if (!inputController->isBoosting())
	{
		if (isHeld)
		{
			std::vector<sf::Sound*> soundList;
			soundList = SfxManager::getInstance()->getSoundList();
			soundList[1]->stop();
			soundList[0]->play();
			std::cout << "tap once" << std::endl;

		}
	}
	this->isHeld = inputController->isBoosting();

	this->ticks += this->deltaTime.asSeconds();
	/*
	if (inputController->hasFired() && this->ticks > bulletSpawnInterval)
	{
		GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		this->ticks = 0.0f;
		std::cout << "adding bullet" << std::endl;
		projectilePool->requestPoolable();

	}*/
}
