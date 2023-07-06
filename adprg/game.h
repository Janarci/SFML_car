#pragma once
#include "ClassFolder/entity.h"
#include "ClassFolder/TextureManager.h"
#include "ClassFolder/SfxManager.h"
#include "ClassFolder/GameObjectManager.h"
#include "ClassFolder/BGObject.h"
#include "ClassFolder/AirplanePlayer.h"
#include "ClassFolder/EnemyAirplane.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class game
{

public:
	game();
	void run();
	float PlayerSpeed = 300.0f;
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 800;

private:
	void processEvents(sf::Time);
	void update(sf::Time, sf::RenderWindow&);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);
	const sf::Time TimePerFrame = sf::seconds(1.0f / 60.0f);
private:
	sf::Texture gTexture;
	
	sf::Sprite mPlayer;
	sf::RenderWindow mWindows; 
	sf::CircleShape mcircle;

	//sf::Font font;
	//sf::Text text;


	std::vector<entity> EntityList;
	std::vector<entity*> _EntityList;

	void createEntity(std::string, float, float);
	void playerMovement(sf::Time);

	std::vector<sf::Sound*> soundList;
	void createSound(std::string key);

	sf::SoundBuffer buffer;
	sf::Sound sound, sound2, sound3, sound4;


	bool gisMovingUp = false;
	bool gisMovingUpRight = false;
	bool gisMovingUpLeft = false;
	bool gisMovingDown = false;
	bool gisMovingDownLeft = false;
	bool gisMovingDownRight = false;
	bool gisMovingLeft = false;
	bool gisMovingRight = false;

};

