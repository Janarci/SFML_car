#include "ObjectPoolHolder.h"

std::string ObjectPoolHolder::ENEMY_POOL_TAG = "EnemyPool";
std::string ObjectPoolHolder::PROJECTILE_POOL_TAG = "ProjectilePool";

ObjectPoolHolder* ObjectPoolHolder::sharedInstance = NULL;


ObjectPoolHolder* ObjectPoolHolder::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new ObjectPoolHolder();

	}
	return sharedInstance;

}

void ObjectPoolHolder::registerObjectPool(GameObjectPool* pool)
{

	this->poolMap[pool->getTag()] = pool;

}

void ObjectPoolHolder::unregisterObjectPool(GameObjectPool* pool)
{

	std::cout << "Asking: " << pool->getTag() << std::endl;

	this->poolMap.erase(pool->getTag());
	//delete pool;

}

GameObjectPool* ObjectPoolHolder::getPool(std::string tag)
{
	return this->poolMap[tag];

}
