#include "MainMenuScene.h"
#include "../Screens/MainMenuScreen.h"
#include "../Screens/Sidebar.h"
#include "../SfxManager.h"

MainMenuScene::MainMenuScene() : AScene("MainMenuScene")
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::onLoadResources()
{
}

void MainMenuScene::onLoadObjects()
{
/*
	Sidebar* sidebar = new Sidebar("Sidebar");
	GameObjectManager::getInstance()->addObject(sidebar);
*/
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);

	SfxManager::getInstance()->playBGM();

}
