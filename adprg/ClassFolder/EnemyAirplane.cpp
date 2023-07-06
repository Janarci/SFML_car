#include "EnemyAirplane.h"

#include "ObjectPoolHolder.h"
#include "Physics/PhysicsManager.h"


EnemyAirplane::EnemyAirplane(std::string name) : APoolable(name), CollisionListener()
{
}

EnemyAirplane::~EnemyAirplane()
{
	delete this->sprite;
}

void EnemyAirplane::initialize()
{
	//srand(time(0));

	textureRandomizer();
	sprite->setTextureRect(sf::IntRect(80, 0, 100, 256));

	sprite->setScale(.3f, .3f);
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->setPosition(game::WINDOW_WIDTH / 2, -30);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);

	Renderer* renderer = new Renderer("EnemySprite");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	EnemyBehavior* behavior = new EnemyBehavior("EnemyBehavior");
	this->attachComponents(behavior);
	behavior->configure(1.0f);

	this->collider = new Collider("EnemyCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponents(collider);

}

void EnemyAirplane::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

void EnemyAirplane::onActivate()
{
	//srand(time(0));
	int randNum = (rand() % 2) + 1;

	EnemyBehavior* behavior = (EnemyBehavior*)this->findComponentByName("EnemyBehavior");
	behavior->reset();

	if (randNum == 1)//right side
	{
		//this->getTransformable()->setRotation(180);
		this->getTransformable()->setRotation(0);

		this->setPosition((game::WINDOW_WIDTH / 2 + game::WINDOW_WIDTH / 4) - 50, 100);
		behavior->rightLane();
	}
	else//left side
	{
		this->getTransformable()->setRotation(180);

		this->setPosition((game::WINDOW_WIDTH / 2 - game::WINDOW_WIDTH / 4) + 70, 100);
		behavior->leftLane();

	}
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	PhysicsManager::getInstance()->trackObject(this->collider);

}

void EnemyAirplane::onCollisionEnter(AGameObject* contact)
{

	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	enemyPool->releasePoolable(this);
	/*
	if (contact->getName().find("projectile") != std::string::npos)
	{
		GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
		enemyPool->releasePoolable(this);

	}*/

}

void EnemyAirplane::onCollisionExit(AGameObject* contact)
{
	std::cout << "releasing" << std::endl;

}

APoolable* EnemyAirplane::clone()
{
	APoolable* copyObject = new EnemyAirplane(this->name);

	return copyObject;

}

void EnemyAirplane::textureRandomizer()
{

	int randNum = (rand() % 3) + 1;
	std::cout << randNum<< std::endl;

	this->sprite = new sf::Sprite();
	if (randNum == 1)
	{
		sprite->setTexture(*TextureManager::getInstance()->getTexture("enemyCar1"));

	}
	else if(randNum == 2)
	{
		sprite->setTexture(*TextureManager::getInstance()->getTexture("enemyCar2"));

	}
	else if (randNum == 3)
	{
		sprite->setTexture(*TextureManager::getInstance()->getTexture("enemyCar3"));

	}

}

