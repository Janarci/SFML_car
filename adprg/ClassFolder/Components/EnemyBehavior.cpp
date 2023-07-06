#include "EnemyBehavior.h"

#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include "../../game.h"
#include "../SceneManager.h"

EnemyBehavior::EnemyBehavior(std::string name) : AComponent(name, Script)
{
	this->reset();

}

void EnemyBehavior::perform()
{
	AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlayerObject");
	PlayerInputController* inputController = (PlayerInputController*)(airplanePlayer->getComponentsOfType(ComponentType::Input)[0]);


	PlayerMovement* playerMovement = (PlayerMovement*)(airplanePlayer->getComponentsOfType(ComponentType::Script)[0]);


	float y = SPEED_MULT;//or change this for level increase
	//if pressing space and boost available
	if (inputController->isBoosting() && playerMovement->boostGas > 0)
	{
		std::cout << playerMovement->boostGas << std::endl;

		if (SceneManager::getInstance()->isSceneLoaded("Level1"))
		{
			if (this->type == 2)
			{
				y = SPEED_MULT + 100;

			}
			else
			{
				y = SPEED_MULT + 50;
			}
			//std::cout << "main menu is loaded" << std::endl;
			//Level1
		}
		else if (SceneManager::getInstance()->isSceneLoaded("Level2"))
		{
			if (this->type == 2)
			{
				y = SPEED_MULT + 120;

			}
			else
			{
				y = SPEED_MULT + 40;
			}
			
			//Level2
		}

		else if (SceneManager::getInstance()->isSceneLoaded("Level3"))
		{
			if (this->type == 2)
			{
				y = SPEED_MULT + 140;

			}
			else
			{
				y = SPEED_MULT + 30;
			}
			std::cout << "main menu is loaded" << std::endl;
			//Level3
		}
		
	}



	this->ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();
	/*
	if (this->ticks > this->forwardDuration && this->movementType != Side)
	{
		int counter = (this->movementType + 1) % EnemyMovementType::Side + 1;
		this->movementType = (EnemyMovementType)counter;

	}*/
	if (this->movementType == Forward)
	{

		transformable->move(0, this->deltaTime.asSeconds() * (y));
	}
	if (this->movementType == SlowForward)
	{
		transformable->move(0, this->deltaTime.asSeconds() * (y / 2.0f));
	}
	if (this->movementType == Side)
	{
		if(transformable->getPosition().x  > game::WINDOW_WIDTH/2)
		{
			transformable->move( this->deltaTime.asSeconds() * (SPEED_MULT * 1.5f), 0);
		}
		else
		{
			transformable->move(-this->deltaTime.asSeconds() * SPEED_MULT * 1.5f, 0);
		}

	}

}

void EnemyBehavior::configure(float delay)
{
	this->delay = delay;

}

void EnemyBehavior::reset()
{
	ticks = 0;
	this->SPEED_MULT = 200;

	this->movementType = Forward;
	this->forwardDuration = 1.0f;//(rand() % 3) + 1.0f;

}

void EnemyBehavior::leftLane()
{
	this->type = 2;

	this->SPEED_MULT = 400;

}

void EnemyBehavior::rightLane()
{
	this->type = 1;
	this->SPEED_MULT = 200.0f;
}
