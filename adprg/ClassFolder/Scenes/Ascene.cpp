#include <SFML/Audio/Sound.hpp>

#include  "AScene.h"

AScene::AScene(std::string sceneName)
{
	this->sceneName = sceneName;
}

AScene::~AScene()
{
}

void AScene::onLoadResources()
{
}

void AScene::onLoadObjects()
{

}

void AScene::onUnloadResources()
{
}

void AScene::onUnloadObjects()
{

	GameObjectManager::getInstance()->deleteAllObjectsInScene();

}


std::string AScene::getSceneName()
{
	return this->sceneName;

}

void AScene::registerObject(AGameObject* object)
{
	GameObjectManager::getInstance()->addObject(object);

}
