#include "ProjectileMovement.h"

#include "../AGameObject.h"
#include "../ObjectPoolHolder.h"
#include "SFML/Graphics.hpp"
ProjectileMovement::ProjectileMovement(std::string name) : AComponent(name, Script)
{
}

void ProjectileMovement::perform()
{
	sf::Transformable* transform = this->getOwner()->getTransformable();
	transform->move(0, this->deltaTime.asSeconds() * -SPEED_MULTIPLIER);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > 3.0f)
	{
		reset();
		GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		projectilePool->releasePoolable((APoolable*)this->getOwner());
	}
}

void ProjectileMovement::reset()
{
	this->ticks = 0.0f;

}
