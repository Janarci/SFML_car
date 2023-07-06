#include "game.h"
#include <iostream>

#include "ApplicationManager.h"
#include "FontManager.h"
#include "ClassFolder/EmptyGameObject.h"
#include "ClassFolder/SceneManager.h"
#include "ClassFolder/Components/EnemySwarmHandler.h"
#include "ClassFolder/Scenes/MainMenuScene.h"
#include "ClassFolder/Scenes/Level1Scene.h"
#include "ClassFolder/Scenes/Level2Scene.h"
#include "ClassFolder/Scenes/Level3Scene.h"
#include "ClassFolder/Screens/MainMenuScreen.h"
#include "ClassFolder/Screens/Sidebar.h"

game::game() :
mWindows(sf::VideoMode(1200, WINDOW_HEIGHT),"Khalil Jan Arcilla"),
mPlayer()
{
	//load initialize singletons
	TextureManager::getInstance()->loadAll();
//	createEntity("bed_0", 0, 0);
	//createEntity("bed_1", 150, 0);
	//createEntity("bed_2", 300, 0);

	FontManager::getInstance()->loadAll();

	ApplicationManager::getInstance()->initialize(&mWindows);
	//load sfx
	SfxManager::getInstance()->loadAll();
	/*createSound("gunfire");
	createSound("explode1");
	createSound("explode2");
	createSound("launchMissile");*/

	//register scenes
	SceneManager::getInstance()->registerScene(new MainMenuScene); // MainMenuScene
	SceneManager::getInstance()->registerScene(new Level1Scene); //Level1
	SceneManager::getInstance()->registerScene(new Level2Scene); //Level2
	SceneManager::getInstance()->registerScene(new Level3Scene); //Level3
	//
	//load main menu scene
	SceneManager::getInstance()->loadScene("MainMenuScene");
	//load first level
	//SceneManager::getInstance()->loadScene("Level1");


	/*
	
	BGObject* bgObject = new BGObject("BGOjbect");
	GameObjectManager::getInstance()->addObject(bgObject);

	AirplanePlayer* playerObject = new AirplanePlayer("PlayerObject");
	GameObjectManager::getInstance()->addObject(playerObject);

	srand(time(NULL));
	
	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager"); 
	EnemySwarmHandler* SwarmHandler = new EnemySwarmHandler(200, "SwarmHandler");


	enemiesManager->attachComponents(SwarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
	
	//MainMenuScreen* mainMenuScreen = new MainMenuScreen("MainMenuScreen");
	//GameObjectManager::getInstance()->addObject(mainMenuScreen);

	Sidebar* sidebar = new Sidebar("Sidebar");
	GameObjectManager::getInstance()->addObject(sidebar);
	
	
*/

	//BGObject* bgOject = new BGObject("BGObject");
	/* text stuff
	if (!font.loadFromFile("res/fonts/Sansation.ttf"))
	{
		// error...
	}
	text.setFont(font);

	text.setString("Hello world");

	text.setCharacterSize(24); // in pixels, not points!
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	*/
}

void game::run()
{
	//called in main to start
	sf::Clock clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;
	while (mWindows.isOpen())
	{
		//sf::Time deltaTime = clock.restart();

		TimeSinceLastUpdate += clock.restart();
		while (TimeSinceLastUpdate > TimePerFrame)
		{
			TimeSinceLastUpdate -= TimePerFrame;
			processEvents(TimePerFrame);
			update(TimePerFrame, mWindows);

			render();

			

		}

		
		SceneManager::getInstance()->checkLoadScene();
	}
}

void game::processEvents(sf::Time deltaTime)
{
	sf::Event event;
	while (mWindows.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindows.close();
			break;
		default:
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				//GameObjectManager::getInstance()->addObject(new EnemyAirplane("EnemyAirplane"));
			}
			GameObjectManager::getInstance()->processInput(event);
			break;
		}
	}
}

void game::update(sf::Time deltaTime, sf::RenderWindow& window)
{
	if (!ApplicationManager::getInstance()->isPaused())
	{
		GameObjectManager::getInstance()->update(deltaTime);
	}

	/*
	sf::Vector2f pos(0.0f, 0.0f);
	sf::Vector2f mousePos(0.0f, 0.0f);
	sf::Vector2f movement(PlayerSpeed, PlayerSpeed);

	
	mousePos.x = sf::Mouse::getPosition(window).x;
	mousePos.y = sf::Mouse::getPosition(window).y;
	double angle = atan2(mousePos.y - mPlayer.getPosition().y, mousePos.x - mPlayer.getPosition().x);
	angle = angle * (180 / 3.14);


	pos.x = mousePos.x - mPlayer.getPosition().x;
	pos.y = mousePos.y - mPlayer.getPosition().y;

	if (abs(pos.x) > 5 || abs(pos.y) > 5)
	{


		if (pos.x > 0)
			pos.x = pos.x / pos.x;
		else
			pos.x = -pos.x / pos.x;

		if (pos.y > 0)
			pos.y = pos.y / pos.y;
		else
			pos.y = -pos.y / pos.y;

		movement.x *= pos.x;
		movement.y *= pos.y;

		//mPlayer.move(movement * deltaTime.asSeconds());
	}

	*/

}

void game::render()
{
	mWindows.clear();
	GameObjectManager::getInstance()->draw(&mWindows);
	mWindows.display();

}

void game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	int keyCount = 0;
	if (key == (sf::Keyboard::Num1))
	{
		soundList[0]->play();
	}
	if (key == (sf::Keyboard::Num2))
	{
		soundList[1]->play();
	}
	if (key == (sf::Keyboard::Num3))
	{
		soundList[2]->play();
	}
	if (key == (sf::Keyboard::Num4))
	{
		soundList[3]->play();
	}
	if (key == (sf::Keyboard::W))
	{
		gisMovingUp = isPressed;
		keyCount++;
	}
	if (key == (sf::Keyboard::A))
	{
		gisMovingLeft = isPressed;
		keyCount++;
	}
	if (key == (sf::Keyboard::S))
	{
		gisMovingDown = isPressed;
		keyCount++;
	}
	if (key == (sf::Keyboard::D))
	{
		gisMovingRight = isPressed;
		keyCount++;
	}
	if (gisMovingUp && gisMovingRight)
		gisMovingUpRight = true;
	else
		gisMovingUpRight = false;
}

void game::createEntity(std::string key, float x, float y)
{
	entity* entity = new class entity();
	sf::Texture* m_texture;
	m_texture = TextureManager::getInstance()->getTexture(key);
	entity->setTexture(*m_texture);
	entity->getSprite()->setPosition(x, y);
	_EntityList.push_back(entity);
		

}

void game::playerMovement(sf::Time deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (gisMovingUp)
	{
		movement.y -= PlayerSpeed;
		if (mPlayer.getRotation() != 0 && mPlayer.getRotation() <= 180)
		{
			mPlayer.rotate(-10);
		}
		if (mPlayer.getRotation() != 0 && mPlayer.getRotation() > 180)
		{
			mPlayer.rotate(10);
		}
	}
	if (gisMovingDown)
	{
		movement.y += PlayerSpeed;
		if (mPlayer.getRotation() != 180 && mPlayer.getRotation() < 180)
		{
			mPlayer.rotate(10);

		}
		if (mPlayer.getRotation() != 180 && mPlayer.getRotation() > 180)
		{
			mPlayer.rotate(-10);

		}


	}
	if (gisMovingLeft)
	{
		movement.x -= PlayerSpeed;
		if (mPlayer.getRotation() != 270 && mPlayer.getRotation() >= 90 && mPlayer.getRotation() < 270)
		{
			mPlayer.rotate(10);

		}
		if (mPlayer.getRotation() != 270 && mPlayer.getRotation() < 90 || mPlayer.getRotation() > 270)
		{
			mPlayer.rotate(-10);

		}

	}
	if (gisMovingRight)
	{
		movement.x += PlayerSpeed;
		if (mPlayer.getRotation() != 90 && mPlayer.getRotation() > 90 && mPlayer.getRotation() <= 270)
		{
			mPlayer.rotate(-10);
		}
		if (mPlayer.getRotation() != 90 && mPlayer.getRotation() < 90 || mPlayer.getRotation() > 270)
		{
			mPlayer.rotate(10);

		}

	}
	mPlayer.move(movement * deltaTime.asSeconds());
}

void game::createSound(std::string key)
{
	sf::Sound* sound = new sf::Sound;
	sf::SoundBuffer* m_soundBuffer;
	m_soundBuffer = SfxManager::getInstance()->getBuffer(key);
	sound->setBuffer(*m_soundBuffer);
	soundList.push_back(sound);
}
