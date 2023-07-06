#include "GameObjectManager.h"

#include "ObjectPoolHolder.h"


GameObjectManager* GameObjectManager::sharedInstance = NULL;

GameObjectManager* GameObjectManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new GameObjectManager();

	}
	return sharedInstance;
}

AGameObject* GameObjectManager::findObjectByName(std::string name)
{
	if(gameObjectMap[name] != NULL)
	{
		return gameObjectMap[name];
	}
	else
	{
		std::cerr << "object " << name << " not found";
		return NULL;
	}
}

std::vector<AGameObject*> GameObjectManager::getAllObjects()
{
	return gameObjectList;
}

int GameObjectManager::activeObjects()
{
	return gameObjectList.size();
}

void GameObjectManager::processInput(sf::Event event)
{
	if (!gameObjectList.empty())
	{
		for (int i = 0; i < gameObjectList.size(); i++)
		{
			gameObjectList[i]->processInput(event);
		}
	}

}

void GameObjectManager::update(sf::Time deltaTime)
{
	

	if (!gameObjectList.empty())
	{
		for (int i = 0; i < gameObjectList.size(); i++)
		{
			gameObjectList[i]->update(deltaTime);
		}
	}
	

}

void GameObjectManager::draw(sf::RenderWindow* window)
{
	if (!gameObjectList.empty())
	{
		for (int i = 0; i < gameObjectList.size(); i++)
		{
			gameObjectList[i]->draw(window, sf::RenderStates::Default);
		}
	}
}

void GameObjectManager::addObject(AGameObject* gameObject)
{
	gameObjectMap[gameObject->getName()] = gameObject;
	gameObjectList.push_back(gameObject);
	gameObject->initialize();
	std::cout << "size: " << gameObjectList.size() << std::endl;

}

void GameObjectManager::deleteObject(AGameObject* gameObject)
{
	std::string key = gameObject->getName();
	delete gameObject;
	gameObjectMap.erase(key);
	gameObjectList.erase(std::remove(gameObjectList.begin(), gameObjectList.end(), gameObject));
	gameObjectList.shrink_to_fit();

}

void GameObjectManager::deleteObjectByName(std::string name)
{
	AGameObject* object = findObjectByName(name);
	if(object != NULL)
	{
		deleteObject(object);
	}
}

void GameObjectManager::deleteAllObjectsInScene()
{
	for (int i = 0; i < this->gameObjectList.size(); ++i)
	{

		delete this->gameObjectList[i];

	}

	gameObjectMap.clear();
	gameObjectList.clear();
	this->gameObjectList.shrink_to_fit();

	
	//std::cout << "deleted all poolmap size: " << ObjectPoolHolder::getInstance()->poolMap.size() << std::endl;

	std::cout << "size!!!!: " << gameObjectList.size() << std::endl;


}
