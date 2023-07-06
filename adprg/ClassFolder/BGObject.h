#pragma once
#include "AGameObject.h"
#include "TextureManager.h"
#include "../game.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class BGObject: public AGameObject
{
public:
	BGObject(std::string name);
	void initialize() override;
	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;

private:
	const float SPEED_MULTIPLIER = 100.0f;


};

