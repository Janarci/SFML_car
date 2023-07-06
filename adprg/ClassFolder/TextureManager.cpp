#include "TextureManager.h"
#include  <iostream>

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{

	if(sharedInstance == NULL)
	{
		sharedInstance = new TextureManager();

	}
	return sharedInstance;
}

void TextureManager::testFunc()
{
	std::cout << "hello singleton" << std::endl; 
}

void TextureManager::loadAll()
{
	/*
	for (int i = 0; i < 8; i++)
	{
		std::string str_i = std::to_string(i);
		loadTexture("bed_" + str_i, "res/textures/bed000" + str_i + ".png");
	}*/

	//loadTexture("playerCar", "res/textures/Audi.png");
	loadTexture("playerCar", "res/textures/Audi.png");
	loadTexture("enemyCar1", "res/textures/Car.png");
	loadTexture("enemyCar2", "res/textures/Ambulance.png");
	loadTexture("enemyCar3", "res/textures/Police.png");
	loadTexture("raptor", "res/textures/Raptor.png");
	loadTexture("avenger", "res/textures/Avenger.png");
	loadTexture("bullet", "res/textures/Bullet.png");


	loadTexture("ui_bg", "res/textures/f.png");
	loadTexture("desert_bg", "res/textures/Desert.png");
	loadTexture("btn_normal", "res/textures/b_4.png");
	loadTexture("btn_pressed", "res/textures/b_5.png");

	loadTexture("race_bg", "res/textures/bgrace.jpg");
	loadTexture("main_menu_bg", "res/textures/TitleScreenBG.png");
	loadTexture("racetrack_bg", "res/textures/racetrack.png");
	sf::Texture* bgTex;
	sf::Texture* bgTex2;

	bgTex = getTexture("desert_bg");
	bgTex2 = getTexture("racetrack_bg");
	bgTex->setRepeated(true);
	bgTex2->setRepeated(true);
}

sf::Texture* TextureManager::getTexture(std::string key)
{
	if (textureMap[key] != NULL)
	{
		return textureMap[key];
	}
	else {

		std::cerr << "error" << std::endl;
		return NULL;
	}
}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(path);
	textureMap[key] = texture;
}
