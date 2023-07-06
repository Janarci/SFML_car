#include "SceneManager.h"

#include <iostream>
#include "../ApplicationManager.h"

SceneManager* SceneManager::sharedInstance = NULL;


SceneManager* SceneManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new SceneManager();

	}
	return sharedInstance;
}

void SceneManager::registerScene(AScene* scene)
{
	std::cout << scene->getSceneName() << " registered!" << std::endl;
	this->storedScenes[scene->getSceneName()] = scene;



}

void SceneManager::checkLoadScene()
{
	if (this->isLoading)
	{
		this->unloadScene();
		SfxManager::getInstance()->stopAllMusic();

		this->activeScene = this->storedScenes[this->toLoadSceneName];

		this->activeScene->onLoadResources();

		this->activeScene->onLoadObjects();
		this->isLoading = false;
		ApplicationManager::getInstance()->resumeApplication();

	}
}

void SceneManager::loadScene(std::string name)
{
	this->isLoading = true;
	this->toLoadSceneName = name;
}

void SceneManager::unloadScene()
{
	if (this->activeScene != NULL)
	{
		this->activeScene->onUnloadObjects();
		this->activeScene->onUnloadResources();
	}
}

bool SceneManager::isSceneLoaded(std::string name)
{
	return this->activeScene->getSceneName() == name;

}
void SceneManager::reloadScene()
{
	this->isLoading = true;
	this->toLoadSceneName = this->activeScene->getSceneName();
}