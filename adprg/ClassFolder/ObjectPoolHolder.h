#pragma once
#include "ObjectPooling/GameObjectPool.h"
#include <unordered_map>


typedef  std::unordered_map<std::string, GameObjectPool*> PoolMap;

class ObjectPoolHolder: sf::NonCopyable
{

public:

	static std::string ENEMY_POOL_TAG;
	static std::string PROJECTILE_POOL_TAG;

	static ObjectPoolHolder* getInstance();

	void registerObjectPool(GameObjectPool* pool);
	void unregisterObjectPool(GameObjectPool* pool);

	GameObjectPool* getPool(std::string tag);


private:
	ObjectPoolHolder() {}
	PoolMap poolMap;

	static ObjectPoolHolder* sharedInstance;


};

