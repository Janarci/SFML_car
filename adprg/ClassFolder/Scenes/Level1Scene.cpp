#include "Level1Scene.h"



Level1Scene::Level1Scene() : AScene("Level1")
{
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::onLoadResources()
{
}

void Level1Scene::onLoadObjects()
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
	SwarmHandler->changeSpawnInterval(.8);//change spawn interval per level
	enemiesManager->attachComponents(SwarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);

	//AirplanePlayer* airplanePlayer = (AirplanePlayer*)this->getOwner();
	//PlayerInputController* inputController = (PlayerInputController*)(airplanePlayer->getComponentsOfType(ComponentType::Input)[0]);


	EmptyGameObject* gamestateHolder = new EmptyGameObject("GamestateHolder");
	GamestateManager* gamestateManager = new GamestateManager("GamestateManager");
	gamestateManager->setTotalTime(180.0);
	gamestateManager->setWinCondition(30);//balance

	gamestateHolder->attachComponents(gamestateManager);
	GameObjectManager::getInstance()->addObject(gamestateHolder);
	
	Sidebar* sidebar = new Sidebar("Sidebar");
	GameObjectManager::getInstance()->addObject(sidebar);

	UIScreen* uiScreen = new UIScreen("UIScreen");
	GameObjectManager::getInstance()->addObject(uiScreen);

	std::vector<sf::Sound*> soundList;
	soundList = SfxManager::getInstance()->getSoundList();
	soundList[0]->setLoop(true);
	soundList[1]->setLoop(true);
	soundList[0]->play();

	/*createSound("carSlow");
	soundList[0]->setLoop(true);
	soundList[0]->play();
	soundList[0]->stop();*/
}

void Level1Scene::onUnloadObjects()
{

	
	GameObjectPool* enemyPooltest = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPooltest);

	AScene::onUnloadObjects();

	//
	//std::cout <<"Pool amaps: "<< ObjectPoolHolder::getInstance()->poolMap.size() << std::endl;


}
