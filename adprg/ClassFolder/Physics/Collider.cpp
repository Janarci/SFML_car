#include "Collider.h"

#include <iostream>

Collider::Collider(std::string name) : AComponent(name, Physics)
{
}

void Collider::setCollisionListener(CollisionListener* listener)
{
	this->listener = listener;
}

void Collider::setChecked(bool flag)
{
	this->checked = flag;
}

bool Collider::isChecked()
{
	return this->checked;
}

bool Collider::willCollide(Collider* another)
{
	sf::FloatRect A = this->getGlobalBOunds();
	sf::FloatRect B = another->getGlobalBOunds();

	return A.intersects(B);

}

bool Collider::alreadyCollided()
{
	return this->collided;
}

void Collider::setAlreadyCollided(bool flag)
{
	this->collided = flag;

}

sf::FloatRect Collider::getGlobalBOunds()
{
	return this->getOwner()->getGlobalTransform().transformRect(this->localBOunds);
}

void Collider::setLocalBounds(sf::FloatRect localBounds)
{
	this->localBOunds = localBounds;

}

void Collider::collisionEnter(AGameObject* gameObjects)
{
	if (this->listener!= NULL)
	{

		this->listener->onCollisionEnter(gameObjects);
	}
}

void Collider::collisionExit(AGameObject* gameObjects)
{
	if (this->listener!=NULL)
	{
		this->listener->onCollisionExit(gameObjects);

	}
}

void Collider::perform()
{
}
