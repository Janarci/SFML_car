#include "EnemySwarmHandler.h"

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string name) : AComponent(name, Script)
{
	this->enemyPool = new GameObjectPool(
		ObjectPoolHolder::ENEMY_POOL_TAG,
		new EnemyAirplane("enemy"),
		numEnemies,
		NULL
	);
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);


}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete this->enemyPool;
}

void EnemySwarmHandler::perform()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();
	ObjectList usedEnemyPlanes = enemyPool->getUsedObjects();
	
	if (this->ticks > SPAWN_INTERVAL)
	{
		this->ticks = 0.0f;
		enemyPool->requestPoolable();
		
	}
	
	for (int i = 0; i < usedEnemyPlanes.size(); ++i)
	{
		if (usedEnemyPlanes[i]->isEnabled())
		{
			sf::Transformable* transformable = usedEnemyPlanes[i]->getTransformable();

			if (transformable->getPosition().x > game::WINDOW_WIDTH || transformable->getPosition().x < 0 || transformable->getPosition().y > game::WINDOW_HEIGHT)
			{
				//GameObjectManager::getInstance()->findObjectByName("GamestateHolder");
				EmptyGameObject* gameStateHolder = (EmptyGameObject*)GameObjectManager::getInstance()->findObjectByName("GamestateHolder");
				GamestateManager* gamestateManager = (GamestateManager*)(gameStateHolder->getComponentsOfType(ComponentType::Script)[0]);
				gamestateManager->addScore(1);

				//std::cout << "add point here" << std::endl;//make empty gameobject with winning script
				enemyPool->releasePoolable(usedEnemyPlanes[i]);
			}
		}
		
		//enemyPool->releasePoolable(usedEnemyPlanes[i]);
		//std::cout << usedEnemyPlanes.size() << std::endl;

	}
	

	//perform checks for isactive here to release
}

void EnemySwarmHandler::changeSpawnInterval(float spawnInterval)
{
	this->SPAWN_INTERVAL = spawnInterval;

}
