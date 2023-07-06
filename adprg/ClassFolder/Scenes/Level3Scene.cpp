#include "Level3Scene.h"



Level3Scene::Level3Scene() : AScene("Level3")
{
}

Level3Scene::~Level3Scene()
{
}

void Level3Scene::onLoadResources()
{
}

void Level3Scene::onLoadObjects()
{

	EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
	this->registerObject(physicsManager);
	PhysicsManager::initialize("PhysicsManager", physicsManager);


	BGObject* bgObject = new BGObject("BGOjbect");
	GameObjectManager::getInstance()->addObject(bgObject);

	AirplanePlayer* playerObject = new AirplanePlayer("PlayerObject");
	GameObjectManager::getInstance()->addObject(playerObject);


	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* SwarmHandler = new EnemySwarmHandler(20, "SwarmHandler");
	SwarmHandler->changeSpawnInterval(.4);//change spawn interval per level
	enemiesManager->attachComponents(SwarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);

	EmptyGameObject* gamestateHolder = new EmptyGameObject("GamestateHolder");
	GamestateManager* gamestateManager = new GamestateManager("GamestateManager");
	gamestateManager->setTotalTime(180.0);
	gamestateManager->setWinCondition(100);//balance

	gamestateHolder->attachComponents(gamestateManager);
	GameObjectManager::getInstance()->addObject(gamestateHolder);

	Sidebar* sidebar = new Sidebar("Sidebar");
	GameObjectManager::getInstance()->addObject(sidebar);

	UIScreen* uiScreen = new UIScreen("UIScreen");
	GameObjectManager::getInstance()->addObject(uiScreen);
}

void Level3Scene::onUnloadObjects()
{


	GameObjectPool* enemyPooltest = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPooltest);

	AScene::onUnloadObjects();

	//
	//std::cout <<"Pool amaps: "<< ObjectPoolHolder::getInstance()->poolMap.size() << std::endl;


}
