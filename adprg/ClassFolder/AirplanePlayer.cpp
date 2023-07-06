#include "AirplanePlayer.h"
#include "TextureManager.h"
#include "../game.h"
#include "../ApplicationManager.h"
#include <iostream>

#include "Components/PlayerInputController.h"
#include "Components/PlayerMovement.h"
#include "Components/Renderer.h"
#include "Physics/PhysicsManager.h"
#include "Screens/LoseScreen.h"

AirplanePlayer::AirplanePlayer(std::string name): AGameObject(name), CollisionListener()
{
	
}

void AirplanePlayer::initialize()
{
	/*this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("eagle"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(game::WINDOW_WIDTH / 2, game::WINDOW_WIDTH / 2);*/

	sf::Sprite* sprite = new sf::Sprite;
	sprite->setTexture(*TextureManager::getInstance()->getTexture("playerCar"));
	sprite->setTextureRect(sf::IntRect(80, 0, 100, 256));

	sprite->setScale(.3f, .3f);

	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(game::WINDOW_WIDTH / 2, game::WINDOW_WIDTH - 100);
	Renderer* renderer = new Renderer("PlayerSprite");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	PlayerInputController* inputController = new PlayerInputController("MyPlayerInput");
	this->attachComponents(inputController);

	PlayerMovement* movement = new PlayerMovement("MyMovement");
	this->attachComponents(movement);

	this->collider = new Collider("PlayerCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponents(collider);
	PhysicsManager::getInstance()->playerCollider = this->collider;

	
}

void AirplanePlayer::onCollisionEnter(AGameObject* gameObject)
{
	LoseScreen* loseScreen = new LoseScreen("loseScreen");
	GameObjectManager::getInstance()->addObject(loseScreen);
	ApplicationManager::getInstance()->pauseApplication();
}

void AirplanePlayer::onCollisionExit(AGameObject* gameObject)
{
}

