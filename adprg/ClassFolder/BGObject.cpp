#include "BGObject.h"

#include "Components/BGMovement.h"
#include "Components/Renderer.h"

BGObject::BGObject(std::string name): AGameObject(name)
{

}

void BGObject::initialize()
{

	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("racetrack_bg"));
	sf::Vector2u textureSoze = this->sprite->getTexture()->getSize();

	sprite->setTextureRect(sf::IntRect(0, 0, game::WINDOW_WIDTH, game::WINDOW_HEIGHT * 8));
	sprite->setPosition(0, -game::WINDOW_HEIGHT * 7);

	Renderer* renderer = new Renderer("BGSprite");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);


	BGMovement* bgMovement = new BGMovement("BGMovement");
	this->attachComponents(bgMovement);

}

void BGObject::processInput(sf::Event event)
{
	AGameObject::processInput(event);
}

void BGObject::update(sf::Time deltaTime)
{
	AGameObject::update(deltaTime);
	/*
	sf::Vector2f offset(0.0f, 0.0f);

	offset.y += SPEED_MULTIPLIER;
	sprite->move(offset * deltaTime.asSeconds());

	sf::Vector2f localPos = sprite->getPosition();
	if (localPos.y*deltaTime.asSeconds() > 0)
	{
		sprite->setPosition(0, -game::WINDOW_HEIGHT * 7);
		
	}*/
}
