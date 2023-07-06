#include "GamestateManager.h"
#include "../Screens/WinScreen.h"
#include "../Screens/LoseScreen.h"
#include "../Screens/UIScreen.h"
#include "../GameObjectManager.h"
#include "../../ApplicationManager.h"


class WinScreen;

GamestateManager::GamestateManager(std::string name) : AComponent(name, Script)
{
	this->reset();

}

void GamestateManager::perform()
{
	
	UIScreen* UIHolder = (UIScreen*)GameObjectManager::getInstance()->findObjectByName("UIScreen");

	std::string str = std::to_string((int)this->totalTime);
	//str.erase(str.find_last_not_of('0') + 1, std::string::npos);

	UIHolder->setTime(str);
	
	this->ticks += this->deltaTime.asSeconds();
	if (this->ticks > secondsPassed)
	{
		this->totalTime -= secondsPassed;
		this->ticks = 0;
		std::cout << this->totalTime << std::endl;

	}
	if (this->totalTime <= 0 && !ApplicationManager::getInstance()->isPaused())
	{
		LoseScreen* loseScreen = new LoseScreen("LoseScreen");
		GameObjectManager::getInstance()->addObject(loseScreen);
		ApplicationManager::getInstance()->pauseApplication();
	}
}

void GamestateManager::update(sf::Time deltaTime)
{
	
}

void GamestateManager::addScore(int toAdd)
{
	this->score += toAdd;
	std::cout << "this is the score: " << this->score << std::endl;
	if (this->score >= winCondition)
	{
		WinScreen* winScreen = new WinScreen("WinScreen");
		GameObjectManager::getInstance()->addObject(winScreen);
		ApplicationManager::getInstance()->pauseApplication();

	}

}

int GamestateManager::getScore()
{
	return 1;

}

float GamestateManager::getTimeRemaining()
{
	return this->totalTime;

}

void GamestateManager::setWinCondition(int winCon)
{
	this->winCondition = winCon;
}

void GamestateManager::setTotalTime(float time)
{
	this->totalTime = time;

}

void GamestateManager::reset()
{
	this->score = 0;
	this->winCondition = 50;

}
