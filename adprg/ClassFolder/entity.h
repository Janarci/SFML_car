#pragma once
#include <SFML/Graphics.hpp>


class entity
{

public:
	entity();
	void setTexture(sf::Texture texture);
	sf::Sprite* getSprite();

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;

};

