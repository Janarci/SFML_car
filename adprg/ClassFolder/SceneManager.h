#pragma once
#include <unordered_map>
#include "Scenes/AScene.h"


typedef std::unordered_map < std::string, AScene* > sceneTable;
typedef std::vector<std::string> stringList;
const std::string MAIN_MENU_SCENE_NAME = "MainMenuScene";
const std::string GAME_SCENE_NAME = "GameScene";

class SceneManager : sf::NonCopyable
{
public:

	static SceneManager* getInstance();


	void registerScene(AScene* scene);
	void checkLoadScene();
	void loadScene(std::string name);
	void unloadScene();
	void reloadScene();
	bool isSceneLoaded(std::string name);



private:
	SceneManager() {};

	static SceneManager* sharedInstance;

	sceneTable storedScenes;
	AScene* activeScene = NULL;

	bool isLoading = false;
	std::string toLoadSceneName;


};

