#pragma once

#include <SFML/System.hpp>
#include <iostream>

#include "AGameObject.h"
#include <unordered_map>

class GameObjectManager
{
public:
	static  GameObjectManager* getInstance();
	AGameObject* findObjectByName(std::string name);
	std::vector<AGameObject*> getAllObjects();
	int activeObjects();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow* window);
	void addObject(AGameObject* gameObject);
	void deleteObject(AGameObject* gameObject);
	void deleteObjectByName(std::string name);
	void deleteAllObjectsInScene();


private:
	GameObjectManager() {};
	static GameObjectManager* sharedInstance;

	std::unordered_map<std::string, AGameObject*> gameObjectMap;
	std::vector<AGameObject*> gameObjectList;

};

