#include "ProjectileObject.h"

ProjectileObject::ProjectileObject(std::string name) : APoolable(name), CollisionListener()
{
}

ProjectileObject::~ProjectileObject()
{
}

void ProjectileObject::initialize()
{

	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("bullet"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("BulletSprite");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	this->projectileMovement = new ProjectileMovement("bulletMovement");
	this->attachComponents(this->projectileMovement);

	this->collider = new Collider("BulletCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponents(collider);


}

void ProjectileObject::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
	std::cout << "why am i untracking this" << this->collider->getName()<< std::endl;

}

void ProjectileObject::onActivate()
{
	AirplanePlayer* player = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlayerObject");
	sf::Vector2f position = player->getTransformable()->getPosition();
	this->setPosition(position.x, position.y);

	this->hasHit = false;

	PhysicsManager::getInstance()->trackObject(this->collider);

}

APoolable* ProjectileObject::clone()
{
	APoolable* copyObj = new ProjectileObject(this->name);

	return copyObj;
}

void ProjectileObject::onCollisionEnter(AGameObject* contact)
{
	if (contact->getName().find("enemy") != std::string::npos && !this->hasHit)
	{
		this->hasHit = true;
		GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		projectilePool->releasePoolable(this);
		std::cout << "HIT!" << std::endl;

	}

}

void ProjectileObject::onCollisionExit(AGameObject* contact)
{
}
