#include "entity.h"

entity::entity()
{
}

void entity::setTexture(sf::Texture texture)
{
	mTexture = texture;
	mSprite.setTexture(mTexture);

}

sf::Sprite* entity::getSprite()
{
	return  &mSprite;
}
