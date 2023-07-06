#include "PlayerInputController.h"

#include <iostream>

PlayerInputController::PlayerInputController(std::string name): GenericInputController(name)
{
}

PlayerInputController::~PlayerInputController()
{
}

void PlayerInputController::perform()
{

	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed)
	{
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		keyFlag = false;
	}

	sf::Keyboard::Key key = event.key.code;
	/*
	if (key == (sf::Keyboard::W))
	{
		this->moveUp = keyFlag;
	}*/
	if (key == (sf::Keyboard::A))
	{
		this->moveRight = keyFlag;

	}/*
	if (key == (sf::Keyboard::S))
	{
		this->moveDown = keyFlag;

	}*/
	if (key == (sf::Keyboard::D))
	{
		this->moveLeft = keyFlag;

	}
	if (key == (sf::Keyboard::Space))
	{
		this->boosting = keyFlag;

		this->fire = keyFlag;
		std::cout << "Fire!" << std::endl;
	}
}

bool PlayerInputController::isUp()
{
	return this->moveUp;
}

bool PlayerInputController::isDown()
{
	return this->moveDown;
}

bool PlayerInputController::isLeft()
{
	return this->moveLeft;
}

bool PlayerInputController::isRight()
{
	return this->moveRight;
}

bool PlayerInputController::isBoosting()
{
	return this->boosting;
}

bool PlayerInputController::hasFired()
{
	return this->fire;
}
